
/************************************************************************
 *
 *  otp.c
 *
 *  OTP routine for RTD299X internal ROM
 *
 *
 * Copyright (c) 2012 Realtek Semiconductor Corp. All rights reserved.
 *
 ************************************************************************/

#include "util.h"
#include "otp.h"

unsigned char check_secure_boot(void)
{
	#if defined(Config_Secure_Key_TRUE)
        //TODO : for real case
		#if 1
			return NONE_SECURE_BOOT;
		#else
			return get_secure_type_from_efuse();
		#endif
	#else
		return NONE_SECURE_BOOT;
	#endif
}

