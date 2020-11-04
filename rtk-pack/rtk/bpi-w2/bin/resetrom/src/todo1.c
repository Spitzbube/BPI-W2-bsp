
#include "register.h"
#include "usb.h"


struct
{
	int fill_0[125]; //0
	int Data_80005B44; //500
	char bData_80005B48; //504
	int Data_80005B4C; //508

} Data_0x80005950;


struct
{
	void* Data_80005748; //0
	void* Data_80005750; //8
	int fill_16[16]; //16
	void* Data_80005798; //80
	int fill_88[70]; //88
	char fill_800058B8; //368
	char fill_800058B9;
	char bData_800058BA; //370
	int fill_372[37]; //372 - 800058BC
} Data_0x80005748;


/* c108 - todo */
void func_c108_test(struct dwc3 *dwc)
{
	if (Data_0x80005748.bData_800058BA == 5)
	{
		Data_0x80005748.bData_800058BA = 0;

		int a = ((char*)Data_0x80005748.Data_80005750)[15];
		if (a == 0xf2)
		{
			func_11b0(); // Watchdog reset?
		}
		else if (a == 0xf9)
		{
			if ((((char*)Data_0x80005748.Data_80005750)[13] & 0xc0) &&
					((((char*)Data_0x80005748.Data_80005750)[13] & 0x0f) == 3))
			{
				prints("IG\n");

				func_1844(Data_0x80005748.Data_80005798);
			}
		}
		else if (a == 0xfa)
		{
			Data_0x80005950.Data_80005B4C = 1;
		}

		if (Data_0x80005950.Data_80005B4C != 0)
		{
			func_b7cc(); //Malloc DDR Event Buffers
		}

		flush_cache(Data_0x80005748.Data_80005750, Data_0x80005748.Data_80005750 + 0x764/*+1892*/);

		func_a7f8(dwc, 4, Data_0x80005748.Data_80005750, 512);
	}
	else if (Data_0x80005748.bData_800058BA == 1)
	{
		Data_0x80005748.bData_800058BA = 0x05;

		func_b928(Data_0x80005950.bData_80005B48);
	}
}


/* 6944 - todo */
void sync(void)
{
	CP15DMB;
	//(*(volatile unsigned int *)(0x9801a020)) =0x0;
	*((unsigned int*)SB2_SYNC) = 0;
    CP15DMB;
}





/* 66b4 - todo */
void flush_cache(unsigned long start, unsigned long size)
{
#if 0
	if (Data_80005084 != 0)
	{
		CP15DSB;
		CP15DMB;

		REG32(SB2_SYNC) = 0;
		CP15DMB;

		__asm_flush_dcache_range(start, size);
		CP15DMB;

		REG32(SB2_SYNC) = 0;
		CP15DMB;
	}
#endif
}


