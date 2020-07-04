
#include "register.h"


#define OTP_REG_BASE    	 	0x98017000

/* 8a70 - complete */
int OTP_Get_Word(unsigned int offset, unsigned int* data, unsigned int size)
{
	unsigned int i;
	unsigned int addr = OTP_REG_BASE;

	addr += (offset & ~3);

	for (i = 0; i < size; i++, addr += 4)
	{
		data[i] = REG32(addr);
	}

	return 0;
}


/* 8aac - complete */
unsigned int OTP_JUDGE_BIT(unsigned int offset)
{
    unsigned int div_n=0, rem_n=0;
    unsigned int align_n=0, align_rem_n=0, real_n=0;

    rem_n = offset%8;
    div_n = offset/8;

    align_n = div_n & ~0x3;
    align_rem_n = div_n & 0x3;

    real_n = REG32(OTP_REG_BASE + align_n);
    return(((real_n >>(align_rem_n*8)) >> rem_n)&1);
}


