

#include "sysdefs.h"
#include "uart.h"
#include "util.h"


PrintFuncPtr_t 			rtprintf = NULL; //15AF688
Flush_Dcache_AllPtr_t 	rtflush_dcache_all = NULL; //15AF690
Flush_CachePtr_t  		rtflush_cache = NULL; //15AF698


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


void dvrmain(void)
{
	rebuild_function_pointer_from_uboot_to_dvrmain();
	init_uart();
	set_focus_uart(0); //default : uart0
}


