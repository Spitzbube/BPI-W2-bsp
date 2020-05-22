

#include "sysdefs.h"
#include "sys_reg.h"
#include "uart.h"
#include "util.h"
#include "flashdev_s.h"
#include "io.h"
#include "extern_param.h"
#include "otp.h"


#define FLASH_MAGICNO_NOR_SERIAL		0xDE

extern unsigned char resetrom[];		//rom data : 0x1FC0_0000 ~ 0x1FC0_1FFF
extern unsigned char resetrom_end;
extern unsigned char mips_resetrom[];
extern unsigned char mips_resetrom_end;
extern unsigned char hwsetting[];
extern unsigned char hwsetting_end;
extern unsigned char hasharray[];
extern unsigned char hasharray_end;
extern unsigned char signature[];
extern unsigned char signature_end;
extern unsigned char fsbl[];
extern unsigned char fsbl_end;
extern unsigned char fsbl_signature[];
extern unsigned char fsbl_signature_end;
extern unsigned char fsbl_os[];
extern unsigned char fsbl_os_end;
extern unsigned char fsbl_os_signature[];
extern unsigned char fsbl_os_signature_end;
extern unsigned char bl31[];
extern unsigned char bl31_end;
extern unsigned char bl31_signature[];
extern unsigned char bl31_signature_end;
extern unsigned char rsa_pub[];
extern unsigned char rsa_pub_end;
extern unsigned char bootcode2_boot_hasharray[];
extern unsigned char bootcode2_boot_hasharray_end;

extern unsigned char linux_rescue_hasharray[];
extern unsigned char linux_rescue_hasharray_end;

extern unsigned int  mcp_dscpt_addr;

unsigned char  verify_after_write;
unsigned char  force_secure;
unsigned char  test_secure;
unsigned char  noreset;

PrintFuncPtr_t 			rtprintf = NULL; //15AF688
Flush_Dcache_AllPtr_t 	rtflush_dcache_all = NULL; //15AF690
Flush_CachePtr_t  		rtflush_cache = NULL; //15AF698



void set_spi_pin_mux(void)
{
#ifndef FPGA	  //wilma+  0802
	//1295
	//set sf_en=1
	REG32(SYS_muxpad5) |= 0x01;
#endif
}


/************************************************************************
 * get uboot domain function pointer to dvrmain domain function pointer
 ************************************************************************/
void rebuild_function_pointer_from_uboot_to_dvrmain( void )
{
	// get fun ptr of printf(...) from specified address
	#define DUMMY                               (*((unsigned int *)0x00020060))
	#define DUMMY2                              (*((unsigned int *)0x00020064))
	#define UBOOT_PRINTF_ADDRESS_TAG            (*((unsigned int *)0x00020068))
	#define UBOOT_PRINTF_ADDRESS                (*((unsigned int *)0x0002006C))
	#define UBOOT_FLUSH_DCACHE_ALL_ADDRESS_TAG  (*((unsigned int *)0x00020070))
	#define UBOOT_FLUSH_DCACHE_ALL_ADDRESS      (*((unsigned int *)0x00020074))
	#define UBOOT_FLUSH_CACHE_ADDRESS_TAG       (*((unsigned int *)0x00020078))
	#define UBOOT_FLUSH_CACHE_ADDRESS           (*((unsigned int *)0x0002007C))

	if( UBOOT_PRINTF_ADDRESS_TAG == CODE_VAILD_MAGIC_NUMBER )
	{
		rtprintf = (PrintFuncPtr_t) (UBOOT_PRINTF_ADDRESS);
//		rtprintf("\n\nHello World(%s %s), get printf ptr=%p\n\n", __DATE__, __TIME__, rtprintf);
	}
	else
	{
		rtprintf = NULL;
	}

    if( UBOOT_FLUSH_DCACHE_ALL_ADDRESS_TAG == CODE_VAILD_MAGIC_NUMBER ) {
        rtflush_dcache_all = (Flush_Dcache_AllPtr_t) (UBOOT_FLUSH_DCACHE_ALL_ADDRESS);
    }
    else {
        rtflush_dcache_all = NULL;
    }

    if( UBOOT_FLUSH_CACHE_ADDRESS_TAG == CODE_VAILD_MAGIC_NUMBER ) {
        if (UBOOT_FLUSH_CACHE_ADDRESS != UBOOT_PRINTF_ADDRESS) // prevent side effect
        {
            rtflush_cache = (Flush_CachePtr_t) (UBOOT_FLUSH_CACHE_ADDRESS);
        }
        else
        {
            rtflush_cache = NULL;
        }
    }
    else {
        rtflush_cache = NULL;
    }
}


int dvrmain(void)
{
    // spi used
    unsigned char * spi_resetrom_addr;
    unsigned char * spi_mips_resetrom_addr;
    unsigned char * spi_hwsetting_addr;
    unsigned char * spi_param_addr;
    unsigned char * spi_bootcode_addr;
    unsigned char * spi_fsbl_addr;
    unsigned char * spi_fsbl_sig_addr;
    unsigned char * spi_fsbl_os_addr;
    unsigned char * spi_fsbl_os_sig_addr;
    // spi bl31
    unsigned char * spi_bl31_addr;
    unsigned char * spi_bl31_sig_addr;
    unsigned char * spi_rsa_pub_addr;
    unsigned char * spi_bootcode_sig_addr;
    unsigned char * spi_bootcode_addr2;

    unsigned int  resetrom_size;
    unsigned int  mips_resetrom_size;
    unsigned int  hwsetting_size;
    unsigned int  hasharray_size;
	unsigned int  signature_size;
	unsigned int  bootcode2_boot_hasharray_size;
	unsigned int  linux_rescue_hasharray_size;

    unsigned char * env_param_addr;
    unsigned char * linux_sec1_addr;
    unsigned char * linux_sec2_addr;
    unsigned int    linux_sec1_size;
    unsigned int    linux_sec2_size;

    unsigned char * programmed_img_base;
    unsigned int    programmed_img_size;

	unsigned char * programmed_img_sig_base;
	unsigned int	programmed_img_sig_size;

	unsigned char * programmed_fsbl_base;
	unsigned int	programmed_fsbl_size;
	unsigned char * programmed_fsbl_sig_base;
	unsigned int	programmed_fsbl_sig_size;
	unsigned char * programmed_fsbl_os_base;
	unsigned int	programmed_fsbl_os_size;
	unsigned char * programmed_fsbl_os_sig_base;
	unsigned int	programmed_fsbl_os_sig_size;
    unsigned char * programmed_bl31_base;
	unsigned int	programmed_bl31_size;
	unsigned char * programmed_bl31_sig_base;
	unsigned int	programmed_bl31_sig_size;

	unsigned char * programmed_rsa_pub_base;
	unsigned int	programmed_rsa_pub_size;

    unsigned char * bootcode2_boot_programmed_img_base;
    unsigned int    bootcode2_boot_programmed_img_size;

    unsigned char * programmed_linux_rescue_img_base;
    unsigned int    programmed_linux_rescue_img_size;

    unsigned char   flash_magicno;
	unsigned int    idx, i;
	void * device;
    t_extern_param param;

	rebuild_function_pointer_from_uboot_to_dvrmain();
	init_uart();
	set_focus_uart(0); //default : uart0

	// -------------------------------------------------------------------------
	// initial global variable
	// -------------------------------------------------------------------------
	mcp_dscpt_addr = 0;

	// -------------------------------------------------------------------------
	// initial local variable
	// -------------------------------------------------------------------------
	// sort by address value
	resetrom_size  				  = (unsigned int )(&resetrom_end  			   - resetrom);
	mips_resetrom_size  		  = (unsigned int )(&mips_resetrom_end  	   - mips_resetrom);
    hwsetting_size 				  = (unsigned int )(&hwsetting_end 			   - hwsetting);	//hwsetting + signature for both secure/non-secure
    hasharray_size                = (unsigned int )(&hasharray_end 			   - hasharray);	//bootcode for secure/non-secure
	signature_size                = (unsigned int )(&signature_end 			   - signature);	//bootcode signature for secure/non-secure
	bootcode2_boot_hasharray_size = (unsigned int )(&bootcode2_boot_hasharray_end 			   - bootcode2_boot_hasharray);

	linux_rescue_hasharray_size   = (unsigned int )(&linux_rescue_hasharray_end - linux_rescue_hasharray);

    programmed_img_size 		  = hasharray_size;
	programmed_img_base           = hasharray;			//without signature

	programmed_img_sig_base		  = signature;

    // fsbl
	programmed_fsbl_size          = (unsigned int )(&fsbl_end - fsbl);
    programmed_fsbl_base          = fsbl;
	programmed_fsbl_sig_size      = (unsigned int )(&fsbl_signature_end - fsbl_signature);
    programmed_fsbl_sig_base      = fsbl_signature;
    // tee os
	programmed_fsbl_os_size       = (unsigned int )(&fsbl_os_end - fsbl_os);
    programmed_fsbl_os_base       = fsbl_os;
	programmed_fsbl_os_sig_size   = (unsigned int )(&fsbl_os_signature_end - fsbl_os_signature);
    programmed_fsbl_os_sig_base   = fsbl_os_signature;
    // bl31
    programmed_bl31_size       = (unsigned int )(&bl31_end - bl31);
    programmed_bl31_base       = bl31;
	programmed_bl31_sig_size   = (unsigned int )(&bl31_signature_end - bl31_signature);
    programmed_bl31_sig_base   = bl31_signature;

	programmed_rsa_pub_size   = (unsigned int )(&rsa_pub_end - rsa_pub);
    programmed_rsa_pub_base       = rsa_pub;

	if (signature_size>=sizeof(unsigned int))
		programmed_img_sig_size		  = signature_size;
	else
		programmed_img_sig_size = 0;

	bootcode2_boot_programmed_img_size = bootcode2_boot_hasharray_size;
	bootcode2_boot_programmed_img_base = bootcode2_boot_hasharray;

	programmed_linux_rescue_img_size = linux_rescue_hasharray_size;
	programmed_linux_rescue_img_base = linux_rescue_hasharray;

#ifdef ROMCODE_ON_SPI
    spi_resetrom_addr  			 = (unsigned char *)SPI_CODE_PART1; //assign arm romcode start address
    spi_mips_resetrom_addr  	 = (unsigned char *)SPI_CODE_PART11; //assign lexra romcode start address
    spi_param_addr 				 = (unsigned char *)(SPI_CODE_PART1 + SPI_RESETROM_SIZE + SPI_MIPS_RESETROM_SIZE);
    spi_hwsetting_addr 			 = (unsigned char *)(SPI_CODE_PART1 + SPI_RESETROM_SIZE + SPI_MIPS_RESETROM_SIZE + SPI_MAX_PARAM_SIZE); //assign hw setting start address, moidfy by angus, original value is 0xb8108000
#endif

	spi_bootcode_addr            = spi_hwsetting_addr + hwsetting_size;
	spi_bootcode_sig_addr        = spi_bootcode_addr + hasharray_size;
    // spi fsbl
    spi_fsbl_addr                = spi_bootcode_sig_addr + signature_size;
	spi_fsbl_sig_addr            = spi_fsbl_addr + programmed_fsbl_size;
    // spi tee os
    spi_fsbl_os_addr             = spi_fsbl_sig_addr + programmed_fsbl_sig_size;
	spi_fsbl_os_sig_addr         = spi_fsbl_os_addr + programmed_fsbl_os_size;
    // spi bl31
	spi_bl31_addr                = spi_fsbl_os_sig_addr + programmed_fsbl_os_sig_size;
	spi_bl31_sig_addr            = spi_bl31_addr + programmed_bl31_size;

	spi_rsa_pub_addr             = SPI_CODE_PART1+0x80000;
	spi_bootcode_addr2           = SPI_CODE_PART2;

    verify_after_write = 0;
    force_secure = 0;
    test_secure = 0;
    noreset = 0;

	prints("flash_type: ");
	prints("SPI\n");
	flash_magicno     = FLASH_MAGICNO_NOR_SERIAL;
	env_param_addr    = (unsigned char *)SPI_ENV_PARAM_ADDR;

    /***********************************************************************
     * calculate images start address
     ***********************************************************************/

    linux_sec1_addr = 0;
    linux_sec1_size = 0;
    linux_sec2_addr = 0;
    linux_sec2_size = 0;


    /*else*/ if (flash_magicno == FLASH_MAGICNO_NOR_SERIAL)	// NOR flash case
    {
	    /*res =*/ check_secure_boot();
    }

    /***********************************************************************
     * assign value to param object
     ***********************************************************************/
    param.secure_mode        	= check_secure_boot();
    param.flash_type 		 	= flash_magicno;
    param.region     		 	= 0;

	param.mac_hi     		 	= Param_MAC_hi;
	param.mac_lo     		 	= Param_MAC_lo;

    param.array_img_saddr        = 0;
    param.array_img_size         = 0;
    param.secure_mode            = check_secure_boot();
    param.rescue_img_size        = programmed_linux_rescue_img_size;
    param.rescue_img_addr        = 0;
    param.rescue_img_part0_saddr = linux_sec1_addr;
    param.rescue_img_part0_len   = linux_sec1_size;
    param.rescue_img_part1_saddr = linux_sec2_addr;
    param.rescue_img_part1_len   = linux_sec2_size;


	//clear logo value if logo2, logo3 ,logo4 was not used
	param.logo_img_saddr         = 0;
	param.logo2_img_saddr        = 0;
	param.logo3_img_saddr        = 0;
	param.logo4_img_saddr        = 0;
	param.logo5_img_saddr        = 0;
	param.logo6_img_saddr        = 0;
	param.logo7_img_saddr        = 0;
	param.logo8_img_saddr        = 0;

	param.logo_img_len           = 0;
	param.logo2_img_len          = 0;
	param.logo3_img_len          = 0;
	param.logo4_img_len          = 0;
	param.logo5_img_len          = 0;
	param.logo6_img_len          = 0;
	param.logo7_img_len          = 0;
	param.logo8_img_len          = 0;

	param.logo_type              = 0;
	param.logo2_type             = 0;
	param.logo3_type             = 0;
	param.logo4_type             = 0;
	param.logo5_type             = 0;
	param.logo6_type             = 0;
	param.logo7_type             = 0;
	param.logo8_type             = 0;

	param.logo_offset     		 = 0;
	param.logo2_offset    		 = 0;
	param.logo3_offset    		 = 0;
	param.logo4_offset    		 = 0;
	param.logo5_offset    		 = 0;
	param.logo6_offset    		 = 0;
	param.logo7_offset    		 = 0;
	param.logo8_offset    		 = 0;

	param.logo_reg_5370   		 = 0;
	param.logo2_reg_5370  		 = 0;
	param.logo3_reg_5370  		 = 0;
	param.logo4_reg_5370  		 = 0;
	param.logo5_reg_5370  		 = 0;
	param.logo6_reg_5370  		 = 0;
	param.logo7_reg_5370  		 = 0;
	param.logo8_reg_5370  		 = 0;

	param.logo_reg_5374   		 = 0;
	param.logo2_reg_5374  		 = 0;
	param.logo3_reg_5374  		 = 0;
	param.logo4_reg_5374  		 = 0;
	param.logo5_reg_5374  		 = 0;
	param.logo6_reg_5374  		 = 0;
	param.logo7_reg_5374  		 = 0;
	param.logo8_reg_5374  		 = 0;

	param.logo_reg_5378   		 = 0;
	param.logo2_reg_5378  		 = 0;
	param.logo3_reg_5378  		 = 0;
	param.logo4_reg_5378  		 = 0;
	param.logo5_reg_5378  		 = 0;
	param.logo6_reg_5378  		 = 0;
	param.logo7_reg_5378  		 = 0;
	param.logo8_reg_5378  		 = 0;

	param.logo_reg_537c   		 = 0;
	param.logo2_reg_537c  		 = 0;
	param.logo3_reg_537c  		 = 0;
	param.logo4_reg_537c  		 = 0;
	param.logo5_reg_537c  		 = 0;
	param.logo6_reg_537c  		 = 0;
	param.logo7_reg_537c  		 = 0;
	param.logo8_reg_537c  		 = 0;

	// clear hdmi key
	for (i = 0; i < sizeof(param.hdmi_key1); i++)
		param.hdmi_key1[i] = 0;
	for (i = 0; i < sizeof(param.hdmi_key2); i++)
		param.hdmi_key2[i] = 0;
	for (i = 0; i < sizeof(param.hdmi_key3); i++)
		param.hdmi_key3[i] = 0;
	for (i = 0; i < sizeof(param.hdmi_key4); i++)
		param.hdmi_key4[i] = 0;
	for (i = 0; i < sizeof(param.hdmi_key5); i++)
		param.hdmi_key5[i] = 0;
	for (i = 0; i < sizeof(param.hdmi_key6); i++)
		param.hdmi_key6[i] = 0;

	set_memory(param.custom_field, 0, sizeof(param.custom_field));

    param.env_param_saddr = env_param_addr;
    param.data_start_blk = 0;

	prints("begin: ");

	/*else*/ if ( flash_magicno == FLASH_MAGICNO_NOR_SERIAL)
	{
		/***********************************************************************
		 * copy parameters in flash to DDR
		 ***********************************************************************/
		for (idx = 0; idx < SPI_MAX_PARAM_SIZE; idx +=4) {
			rtd_outl( (PARAMETER_TMP_ADDR + idx) ,rtd_inl((unsigned int)(SPI_ENV_PARAM_ADDR + idx))); //copy to ddr : 0x02400000 , len: 0x10000
		}

		/***********************************************************************
		 * set pin mux
		 ***********************************************************************/
		set_spi_pin_mux();
		if (do_identify_s(&device) < 0)
		{
			prints("error identify flash!!\n");
			return -2;
		}
		//150064c
        prints("init\n");

	    do_init_s(device);

#if defined(SPI_ERASE_2MB_ONLY)
    //
    //  SPI_FACTORY_BASE   SPI_FACTORY_BASE   SPI_UBOOT64_BASE   SPI_RSV_BASE
    //  /                 /                  /                   /
    //  +----------------+-------------------+-------------------+----------------+
    //  |                |                   |                   |                |
    //  |                |                   |                   |                |
    //  +----------------+-------------------+-------------------+----------------+
    //  \__________________________________  ____________________________________/
    //                                     \/
    //                                   total 2MB
    //
	#define SPI_FACTORY_BASE (0x88280000UL)
	#define SPI_FACTORY_SIZE (0x00010000UL)
	#define SPI_UBOOT64_BASE (SPI_FACTORY_BASE+SPI_FACTORY_SIZE)
	#define SPI_UBOOT64_SIZE (0x00030000UL)
	#define SPI_RSV_BASE     (SPI_UBOOT64_BASE+SPI_UBOOT64_SIZE)
	#define SPI_RSV_SIZE     (0x00040000UL)

	#define SPI_ERASE_BASE1  (SPI_BASE_ADDR)	//flashdev_s.h
		#ifdef NOT_ERSASE_SPI_FACTORY_DATA
			#define SPI_ERASE_SIZE1  (SPI_FACTORY_BASE-SPI_BASE_ADDR)
			#define SPI_ERASE_BASE2  (SPI_UBOOT64_BASE)
			#define SPI_ERASE_SIZE2  (SPI_UBOOT64_SIZE+SPI_RSV_SIZE)
		#else
			#define SPI_ERASE_SIZE1  (0x00200000UL)		// 2MB
		#endif
#endif // end of SPI_ERASE_2MB_ONLY

#if defined(SPI_ERASE_1MB_ONLY)
	//
    //  RSV     FACTORY_BASE    HW_setting(0x8812_0800)
    //   /       /               /
    //  +-------+-------+-------+---------+----
    //  | 64KB  | 64KB  | para. | HW      |
    //  |       |       | 2KB   | SETTING |
    //  +-------+-------+-------+---------+----
    //   \__________________________________  ____________________________________/
    //                                     \/
    //                                   total 1MB
    //
	#define SPI_FACTORY_BASE (0x88110000UL)
	#define SPI_FACTORY_SIZE (0x00010000UL)
		#ifdef NOT_ERSASE_SPI_FACTORY_DATA
			#define SPI_ERASE_BASE1  (SPI_FACTORY_BASE+SPI_FACTORY_SIZE)
			#define SPI_ERASE_SIZE1  (0x000E0000UL)		// 1MB-128KB=896KB
		#else
			#define SPI_ERASE_BASE1  (SPI_BASE_ADDR)
			#define SPI_ERASE_SIZE1  (0x00100000UL)		// 1MB
		#endif
#endif // end of SPI_ERASE_1MB_ONLY

		prints("spi : erase 0x");
		print_hex(SPI_ERASE_SIZE1);
		prints(" bytes from 0x");
		print_hex(SPI_ERASE_BASE1);
		prints("\n");

	    if (do_erase_s(device, (unsigned int *)SPI_ERASE_BASE1, (SPI_ERASE_SIZE1)) !=0 )
	    {
			return -3;
		}
	    //15006b0

#ifdef ROMCODE_ON_SPI
		//arm
        prints("\nspi : write arm romcode, start=0x");
        print_hex(spi_resetrom_addr);
        prints(", len=0x");
        print_hex(resetrom_size);
        prints("\n");

	    if (do_write_s(device, resetrom, (unsigned int *)spi_resetrom_addr, resetrom_size, 0, 0)!= 0 )
	    {
	        return -4;
		}
	    //1500710

		//lexra
        prints("\nspi : write lexra romcode, start=0x");
        print_hex(spi_mips_resetrom_addr);
        prints(", len=0x");
        print_hex(mips_resetrom_size);
        prints("\n");

	    if (do_write_s(device, mips_resetrom, (unsigned int *)spi_mips_resetrom_addr, mips_resetrom_size, 0, 0)!= 0 )
	    {
	        return -4;
		}
#endif
	    //1500768

		//for secure / non-secure
		//hwsetting
        prints("\nspi : write hw setting&signature, start=0x");
        print_hex(spi_hwsetting_addr);
        prints(", len=0x");
        print_hex(hwsetting_size);
        prints("\n");

	    if (do_write_s(device, hwsetting, (unsigned int *)spi_hwsetting_addr, hwsetting_size, 0, 0)!= 0 )
	    {
	        return -5;
	    }
	    //15007d0

		//bootcode
        prints("\nspi : write bootcode, start=0x");
        print_hex(spi_bootcode_addr);
        prints(", len=0x");
        print_hex(programmed_img_size);
        prints("\n");

	    if (do_write_s(device, programmed_img_base, (unsigned int *)spi_bootcode_addr, programmed_img_size, 0, 0)!= 0 )
	    {
	        return -6;
	    }
	    //150083c

		//bootcode signature
	    if (programmed_img_sig_size > 0)
	    {
	    	//1500864
            prints("\nspi : write bootcode signature, start=0x");
            print_hex(spi_bootcode_sig_addr);
            prints(", len=0x");
            print_hex(programmed_img_sig_size);
            prints("\n");

	    	if (do_write_s(device, programmed_img_sig_base, (unsigned int *)spi_bootcode_sig_addr, programmed_img_sig_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //1500844

        //fsbl
	    if (programmed_fsbl_size > 0)
	    {
	    	//15008b8
            prints("\nspi : write fsbl, start=0x");
            print_hex(spi_fsbl_addr);
            prints(", len=0x");
            print_hex(programmed_fsbl_size);
            prints("\n");

	    	if (do_write_s(device, programmed_fsbl_base, (unsigned int *)spi_fsbl_addr, programmed_fsbl_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //1500904

        //fsbl sig
	    if (programmed_fsbl_sig_size > 0)
	    {
            prints("\nspi : write fsbl sig, start=0x");
            print_hex(spi_fsbl_sig_addr);
            prints(", len=0x");
            print_hex(programmed_fsbl_sig_size);
            prints("\n");

	    	if (do_write_s(device, programmed_fsbl_sig_base, (unsigned int *)spi_fsbl_sig_addr, programmed_fsbl_sig_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //150096c

        //fsbl os
	    if (programmed_fsbl_os_size > 0)
	    {
            prints("\nspi : write fsbl_os, start=0x");
            print_hex(spi_fsbl_os_addr);
            prints(", len=0x");
            print_hex(programmed_fsbl_os_size);
            prints("\n");

	    	if (do_write_s(device, programmed_fsbl_os_base, (unsigned int *)spi_fsbl_os_addr, programmed_fsbl_os_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //15009d4

        //fsbl os sig
	    if (programmed_fsbl_os_sig_size > 0)
	    {
            prints("\nspi : write fsbl_os sig, start=0x");
            print_hex(spi_fsbl_os_sig_addr);
            prints(", len=0x");
            print_hex(programmed_fsbl_os_sig_size);
            prints("\n");

	    	if (do_write_s(device, programmed_fsbl_os_sig_base, (unsigned int *)spi_fsbl_os_sig_addr, programmed_fsbl_os_sig_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //1500a3c

        //bl31
	    if (programmed_bl31_size > 0)
	    {
            prints("\nspi : write bl31, start=0x");
            print_hex(spi_bl31_addr);
            prints(", len=0x");
            print_hex(programmed_bl31_size);
            prints("\n");

	    	if (do_write_s(device, programmed_bl31_base, (unsigned int *)spi_bl31_addr, programmed_bl31_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //1500aa4

	    //bl31 sig
	    if (programmed_bl31_sig_size > 0)
	    {
            prints("\nspi : write bl31 sig, start=0x");
            print_hex(spi_bl31_sig_addr);
            prints(", len=0x");
            print_hex(programmed_bl31_sig_size);
            prints("\n");

	    	if (do_write_s(device, programmed_bl31_sig_base, (unsigned int *)spi_bl31_sig_addr, programmed_bl31_sig_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //1500b0c

        //rsa_pub
	    if (programmed_rsa_pub_size > 0)
	    {
            prints("\nspi : write rsa_pub, start=0x");
            print_hex(spi_rsa_pub_addr);
            prints(", len=0x");
            print_hex(programmed_rsa_pub_size);
            prints("\n");

	    	if (do_write_s(device, programmed_rsa_pub_base, (unsigned int *)spi_rsa_pub_addr, programmed_rsa_pub_size, 0, 0)!= 0 )
	    	{
	        	return -6;
	    	}
	    }
	    //1500b70

	    if( bootcode2_boot_programmed_img_size )
	    {
	    	//1500c00
	    	// write bootcode2
			prints("\nspi : write bootcode2, start=0x");
			print_hex(spi_bootcode_addr2);
			prints(", len=0x");
			print_hex(bootcode2_boot_programmed_img_size);
			prints(", src=0x");
			print_hex(bootcode2_boot_programmed_img_base);
			prints("\n");

#ifdef CONFIG_DTB_IN_SPI_NOR
		    if( bootcode2_boot_programmed_img_size > (320<<10) )
		    {
				prints("\nspi : bootcode2 size is too large, bootcode2 not program");
				return -5;
	    	}
#else
			if( bootcode2_boot_programmed_img_size > (384<<10) )
			{
				prints("\nspi : bootcode2 size is too large, bootcode2 not program");
				return -5;
	    	}
#endif
			if (do_write_s(device, bootcode2_boot_programmed_img_base, (unsigned int *)spi_bootcode_addr2, bootcode2_boot_programmed_img_size, 0, 0)!= 0 )
			{
		        return -6;
		    }
   		}
	    //1500bac

	    // write parameter in bootcode1
        prints("\nspi : write parameter, start=0x");
        print_hex(spi_param_addr);
        prints(", len=0x");
        print_hex(sizeof(t_extern_param));
        prints("\n");

	    if (do_write_s(device, (unsigned char *)&param, (unsigned int *)spi_param_addr, sizeof(t_extern_param), 0, 0)!= 0 )
	    {
	        return -14;
	    }
	    //1500c5c
	    prints("exit\n");

	    /* Reset Command */
	    do_exit_s(device);
	}

    prints("Finish\n");

    if (noreset == 0)
    {
        prints("reset...\n");

        watchdog_reset();
    }

    prints("end\n");

	return 0;
}










