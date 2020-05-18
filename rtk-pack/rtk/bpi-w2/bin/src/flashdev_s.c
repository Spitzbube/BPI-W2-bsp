
#include "io.h"
#include "sb2_reg.h"
#include "sysdefs.h"
#include "flashdev_s.h"


void _sync(void)
{
	sync();
}


/************************************************************************
 *
 *                          do_identify_s
 *  Description :
 *  -------------
 *  implement the identyfy flash type
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
int do_identify_s(void **dev)
{
    UINT32 id;
    UINT32 idx;
    s_device_type * pDevice;
    UINT8 * temp_ptr = (UINT8 *)SPI_BASE_ADDR;


//    rtprintf("*** %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

    // configure spi flash controller register
    rtd_outl(SB2_SFC_POS_LATCH,0x00000001);   //set serial flash controller latch data at rising edge

    //remove this, due to we already set this register at hw-setting
    //rtd_outl(0xb801a808,0x0101000f);   //lowering frequency, setup freq divided no

    rtd_outl(SB2_SFC_CE,0x001A1307);   //setup control edge

    // read Manufacture & device ID
    rtd_outl(SB2_SFC_OPCODE,0x0000009f);
    rtd_outl(SB2_SFC_CTL,0x00000010);
	_sync();
    id = swap_endian(rtd_inl((UINT32 *)temp_ptr));

    id >>= 8;

	prints("\nnor flash id [0x");
	print_hex(id);
	prints("]\n");

    /* find the match flash brand */
    for (idx = 0; idx < DEV_SIZE_S; idx++)
    {
        if ( s_device[idx].id == id )
        {
            //special case: the same id have two mode, check ext-id
            if (id == SPANSION_128Mbit)
            {
                /* read extended device ID */
                    rtd_outl(SB2_SFC_OPCODE,0x0000009f);
                    rtd_outl(SB2_SFC_CTL,0x00000013);
					_sync();
                    id = swap_endian(rtd_inl((UINT32 *)temp_ptr));
                    id >>= 16;

					prints("\textension id [0x");
					print_hex(id);
					prints("]\n");

//                    rtprintf("\textension id [0x%x]\n", id);
                continue;
            }

            *dev = (void *)&s_device[idx];
            pDevice = &s_device[idx];

            // show flash info
			prints("      sector 256k en: 0x");
			print_hex(pDevice->sec_256k_en);
            prints("\n");
			prints("      sector  64k en: 0x");
			print_hex(pDevice->sec_64k_en);
            prints("\n");
			prints("      sector  32k en: 0x");
			print_hex(pDevice->sec_32k_en);
            prints("\n");
			prints("      sector   4k en: 0x");
			print_hex(pDevice->sec_4k_en);
            prints("\n");
			prints("      page_program  : 0x");
			print_hex(pDevice->page_program);
            prints("\n");
			prints("      max capacity  : 0x");
			print_hex(pDevice->size);
            prints("\n");
			prints("      spi type name : ");
            prints(pDevice->string);
            prints("\n");

            return 0;
        }
    }

	prints("ID not match try CMD 90h\n");

	//device not found, down freq and try again
	if (idx == DEV_SIZE_S)
	{
		rtd_outl(SB2_SFC_OPCODE,0x00000090);  //read id
		rtd_outl(SB2_SFC_CTL,0x00000010);  //issue command
		_sync();
		id = rtd_inl((UINT32 *)temp_ptr);
		id >>= 16;

		for (idx = 0; idx < DEV_SIZE_S; idx++)
		{
			if ( s_device[idx].id == id )
			{
				//special case: the same id have two mode, check ext-id
				if (id == SPANSION_128Mbit)
				{
					/* read extended device ID */
					rtd_outl(SB2_SFC_OPCODE,0x00000090);
					rtd_outl(SB2_SFC_CTL,0x0000001b);
					_sync();
					id = swap_endian(rtd_inl((UINT32 *)temp_ptr));
					id >>= 16;
					continue;
				}

				*dev = (void *)&s_device[idx];
				pDevice = &s_device[idx];

#if 0
				// show flash info
				rtprintf("sector 256k en: %d\n", pDevice->sec_256k_en);
				rtprintf("sector  64k en: %d\n", pDevice->sec_64k_en);
				rtprintf("sector  32k en: %d\n", pDevice->sec_32k_en);
				rtprintf("sector   4k en: %d\n", pDevice->sec_4k_en);
				rtprintf("page_program  : %d\n", pDevice->page_program);
				rtprintf("max capacity  : 0x%08x\n", pDevice->size);
				rtprintf("spi type name : %s\n", pDevice->string);
#endif

				return 0;
			}
		}

		if (idx == DEV_SIZE_S)
		{
			*dev = (void *)0x0;
			return -1;
		}
	}

	*dev = (void *)0x0;

	return -1;
}

/************************************************************************
 *
 *                          do_init_s
 *  Description :
 *  -------------
 *  implement the init flash controller
 *
 *  Parameters :
 *  ------------
 *
 *  Return values :
 *  ---------------
 *
 ************************************************************************/
int do_init_s(void *dev)
{
    UINT8 tmp;
    UINT8 * temp_ptr = (UINT8 *)SPI_BASE_ADDR;

//    rtprintf("*** %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

    // configure serial flash controller

    rtd_outl(SB2_SFC_CE,0x001A1307);   // setup control edge

    rtd_outl(SB2_SFC_WP,0x00000000);    // disable hardware potection

    // enable write status register
    rtd_outl(SB2_SFC_OPCODE,0x00000050);
    rtd_outl(SB2_SFC_CTL,0x00000000);
	_sync();
    tmp = rtd_inb(temp_ptr);
    rtd_outb(temp_ptr, 0x0);

    // write status register , no memory protection
    rtd_outl(SB2_SFC_OPCODE,0x00000001);
    rtd_outl(SB2_SFC_CTL,0x00000010);
	_sync();
    rtd_outb(temp_ptr, 0x0);

    return 0;
}

