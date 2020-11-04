
#include "register.h"



/* c79c - complete */
void func_c79c(int a)
{
}




/* d678 - complete (-O2) */
int func_d678(unsigned int addr)
{
	int res = 0x90;

	if ((addr % 4) == 0)
	{
//		if ((a - 0x1f000) <= 0x1ffe1000)
		if ((addr >= 0x0001f000) && (addr <= 0x20000000))
		{
			res = 0;
		}
	}

	return res;
}


/* d6a8 - complete (-O2) */
int memcmp(char* a, char* b, unsigned int count)
{
	unsigned int i;

	sync();

	for (i = 0; i < count; i++)
	{
		if (a[i] != b[i])
		{
			return a[i] - b[i];
		}
	}

	return 0;
}

/* d7f0 - complete (-O2) */
void hexdump(char* a, void* buf, unsigned int length)
{
	unsigned int i;
	char *ptr = (char *)buf;

	if ((ptr == 0) || (length == 0))
	{
		prints("NULL\n");
	}
	else
	{
		prints((a == 0)? "hexdump": a);
		prints(" (0x");
		print_hex((unsigned int)ptr);
		prints(")\n");

		for (i = 0; i < length; i++)
		{
			print_val(ptr[i], 2);

			if ((i & 15) == 15)
			{
				prints("\n");
			}
			else
			{
				prints(" ");
			}
		}

		prints("\n");
	}
}


/* d8d8 - todo */
void func_d8d8(void)
{
	REG32(MIS_TCWCR) = 0xa5; //wden
	REG32(MIS_TCWTR) = 1; //wdclr = 1
	REG32(MIS_TCWOV) = 1 << 23; //sel
	REG32(MIS_TCWCR) = 0;
}


unsigned int Data_80005038; //80005038
unsigned int Data_8000503C; //8000503C
unsigned int Data_80005040; //80005040
unsigned int Data_80005044; //80005044

unsigned int max_alloc_size; //80005048
unsigned int Data_8000504C; //8000504C
unsigned int alloc_count; //80005050
unsigned int alloc_current; //80005054

extern unsigned int d_30;


/* 12a50 - todo */
void func_12a50(int a)
{
	if (a == 0)
	{
		Data_80005038 = 2048;
		Data_8000503C = d_30 + 0x7200;
		Data_80005040 = 0;
		Data_80005044 = Data_8000503C; //d_30 + 0x7200;
	}
	else
	{
		Data_80005038 = 2048;
		Data_8000503C = d_30 + 0x7800;
		Data_80005040 = 0;
		Data_80005044 = Data_8000503C; //d_30 + 0x7800;
	}
}


/* 12abc - todo */
void *func_12abc(unsigned int n_bytes)
{
	void *p;

	if ((Data_80005040 + n_bytes) > (Data_80005038 - 1))
	{
		// exceed limit
		return 0; //NULL;
	}

	if (Data_80005040 == 0) Data_80005044 = Data_8000503C;

	p = (void *)(Data_80005044);

	// always aligned to word boundary
	if (n_bytes & 0x3)
		n_bytes = (n_bytes & ((unsigned int)~0x3)) + 0x4;

	Data_80005044 += n_bytes;
	Data_80005040 += n_bytes;
	return p;
}


/* 12b24 - todo */
void func_12b24(unsigned int n_bytes)
{
	if (n_bytes & 0x3)
		n_bytes = (n_bytes & ((unsigned int)~0x3)) + 0x4;


	Data_80005040 -= n_bytes;
	Data_80005044 -= n_bytes;
}


/* 12b58 - todo */
void func_12b58(void)
{
	Data_80005040 = 0;
	Data_80005044 = Data_8000503C;
}


/* 12b70 - todo */
void func_12b70(int a)
{
	if (a == 0)
	{
		max_alloc_size = 2048;
		Data_8000504C = d_30 + 0x7200;
		alloc_count = 0;
		alloc_current = d_30 + 0x7200;
	}
	else
	{
		max_alloc_size = 2048;
		Data_8000504C = 0x02000100;
		alloc_count = 0;
		alloc_current = 0x02000100;
	}
}


/* 12bd8 - todo */
void *simple_malloc(unsigned int n_bytes)
{
	void *p;

	if ((alloc_count + n_bytes) > (max_alloc_size - 1))
	{
		// exceed limit
		return 0; //NULL;
	}

	if (alloc_count == 0) alloc_current = Data_8000504C;

	p = (void *)(alloc_current);

	// always aligned to word boundary
	if (n_bytes & 0x3)
		n_bytes = (n_bytes & ((unsigned int)~0x3)) + 0x4;

	alloc_current += n_bytes;
	alloc_count += n_bytes;
	return p;
}


/* 12c40 - todo */
void func_12c40(unsigned int n_bytes)
{
	if (n_bytes & 0x3)
		n_bytes = (n_bytes & ((unsigned int)~0x3)) + 0x4;


	alloc_count -= n_bytes;
	alloc_current -= n_bytes;
}


/* 12c74 - todo */
void func_12c74(void)
{
	alloc_count = 0;
	alloc_current = Data_8000504C;
}


/* 12c8c - todo */
int strlen(char* a)
{
	int i = 0;

	while (*a++)
	{
		i++;
	}

	return i;
}


/* 12cb4 - todo */
void memset(void* p, unsigned int b, unsigned int count)
{
	unsigned int addr = p;
	unsigned int i = 0;

	if (!(addr % 4) && !(count % 4))
	{
		for (; i < count; i += 4)
		{
			*((volatile unsigned int*)(addr + i)) = b;
		}
	}
	else
	{
		for (; i < count; i++)
		{
			*((volatile unsigned char*)(addr + i)) = (char)b;
		}
	}
}


//extern void flush_cache(unsigned int a, unsigned int b);

#define SHA256_SIZE					32
#define RSA_SIGNATURE_LENGTH		256


/* 12d0c - todo */
int do_RSA(unsigned int signature_addr, int b, unsigned int output_addr)
{
	unsigned int tcnt = 0;

    unsigned int publicExponent[64];

	CP15DSB;
	sync();

	REG32(CTRL3) = (1 << 1); //int_en
	REG32(SEC_CTRL1) = 0;

	OTP_Get_Word(0, 0x9804cc00, RSA_SIGNATURE_LENGTH / 4);

	flush_cache(0x9804cc00, 0x9804cc00 + RSA_SIGNATURE_LENGTH);

	memset(publicExponent, 0, RSA_SIGNATURE_LENGTH);

	publicExponent[0] = 0x10001;

	copy_memory(0x9804CD80, (unsigned char*)publicExponent, RSA_SIGNATURE_LENGTH);
	copy_memory(0x9804C780, signature_addr, RSA_SIGNATURE_LENGTH);
    copy_memory(0x9804C900, signature_addr + RSA_SIGNATURE_LENGTH, RSA_SIGNATURE_LENGTH);

    REG32(SEC_CTRL3) = swap_endian_volatile(*((unsigned int*)(signature_addr + RSA_SIGNATURE_LENGTH + RSA_SIGNATURE_LENGTH)));

    REG32(SEC_CTRL4) = REG32(SEC_CTRL4) | (1 << 31); //go

    while (REG32(CTRL4) != ((1<<5)|(1<<1)|(1<<0))) //rsa_sec_fin | m_lt_n | me_done
    {
        //1s to timeout
        if (tcnt++ > 1000)
        {
        	prints("==>HWRSA timeout !\n");
            return 1;
        }
        mdelay(0, 1);
    }

    copy_memory(output_addr, 0x9804c900, SHA256_SIZE);
    flush_cache(output_addr, output_addr + SHA256_SIZE);
    reverse_rsa_signature(output_addr);
    flush_cache(output_addr, output_addr + SHA256_SIZE);

    return output_addr;
}



