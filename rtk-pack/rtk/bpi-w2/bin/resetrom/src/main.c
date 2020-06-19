

#include "uart.h"
#include "timer.h"

extern unsigned int d_30;

int Data_8000500C; //8000500C
int fill_80005010[80];
int Data_80005058; //80005058
int Data_8000505c; //8000505c
int Data_80005060; //80005060
int Data_80005064; //80005064 0x80005058+12
int Data_80005068; //80005068 0x80005058+16
int fill_8000506c;
int fill_80005070;
int fill_80005074;
int fill_80005078;
int Data_8000507C; //8000507C
int Data_80005080; //80005080 0x80005058+40
int Data_80005084; //80005084
unsigned int Data_80005088; //80005088 0x80005058+48
unsigned int Data_8000508C; //8000508C 0x80005058+52
int Data_80005090; //80005090 0x80005058+56
int Data_80005094; //80005094 0x80005058+60
int Data_80005098; //80005098

struct
{
	int fill_0[2]; //0
	int Data_8; //8
	int Data_12; //12
	int fill_16; //16
	int Data_20; //20
	int fill_24[2]; //24
	char bData_32; //32
	int Data_36; //36

} Data_80005D98; //80005D98

int Data_80006868; //80006868

int Data_80005b58; //80005b58




void main()
{
}


extern void func_66b4(unsigned long a, unsigned long b); //void* a, void* b);
extern int func_77a0(int a, int b, void* c, void* d);
extern int func_d6a8(void* a, void* b, int c);
extern void func_d724(void* a, void* b, int c);
extern void func_d7f0(char* a, void* b, int c);



/* ab8 - todo */
int func_ab8(int a, int b, unsigned long w21, unsigned int w23)
{
	volatile int sp76 = 0;
	volatile int sp80 = 0;
	volatile unsigned int sp84 = 0;
	volatile unsigned int sp88 = 0;
	volatile int sp92 = 0;
	unsigned long w19;
	unsigned long w20;

	prints("\n5-5");

	sp88 = d_30 + 0xc40;
	w19 = d_30 + 0xc20;

	sp92 = (REG32(ISO_RESERVED_USE_1) >> 1) & 1;

	sync();
	CP15DSB;

	sp76 = func_77a0(a, b, w19, 0);
	if (sp76 != 0)
	{
		return sp76;
	}

	CP15DSB;
	func_66b4(w19, w19 + 32);

	if (sp92 != 0)
	{
		//0xc18
		func_d7f0("s0 = ", w19, 32);
		prints("\n");
	}
	//b78
	if (Data_80005058 == 1)
	{
		//0xc48
		func_66b4(w21, w21 + 256);

		func_d724(sp88, w21, 516);

		func_66b4(sp88, sp88 + 516);

		sp84 = func_12d0c(sp88, w23, d_30 + 0xc60);

		w20 = sp84;

		func_66b4(d_30 + 0xc40, d_30 + 0xc60);

		func_66b4(w20, w20 + 32);

		sync();
	}
	else
	{
		//b88
		func_66b4(w21, w21 + 32);

		func_d724(sp88, w21, 32);

		w20 = d_30 + 0xc40;

		func_66b4(w20, d_30 + 0xc60);
		func_66b4(w20, w20 + 32);
		sync();
	}

	if (sp92 != 0)
	{
		//0xcc0
		func_d7f0("s1 : ", w20, 32);
	}

	//bd4
	sync();
	CP15ISB;

	sp76 = func_d6a8(w19, w20, 32)? 0x3f: 0;
	if (sp76)
	{
	}

	return sp76;
}


/* 11b4 - todo */
void func_11b4(void)
{
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	prints("fill");
	while (1);
}


/* 1244 - todo */
int func_1244(void)
{
	int w19;
	int i;
	volatile int sp60 = 0;

	func_6728(0);
	sync();

	Data_80005088 = *((volatile unsigned int*)PWDN_CTRL2);

	if (((Data_80005088) - 0xace2) & ~0x02)
	{
		//1288
		Data_80005088 = 0;
	}
	//0x14c8
	else if (Data_80005088 != 0)
	{
		//14cc
		*((volatile unsigned int*)SOFT_RESET1) |= (1 << 28); //rstn_ae
		*((volatile unsigned int*)SOFT_RESET2) |= (1 << 0); //rstn_acpu
		*((volatile unsigned int*)CLOCK_ENABLE2) |= (1 << 4); //clk_en_acpu
		*((volatile unsigned int*)DREQ_MASK) |= (1 << 1); //mask_id

		func_c79c(16);

		*((volatile unsigned int*)PWDN_CTRL3) = (1 << 3); //write_en2
		*((volatile unsigned int*)PWDN_CTRL) = 0xace3;
		*((volatile unsigned int*)PWDN_CTRL3) = (1 << 3)|(1 << 2); //write_en2 + kcpu_boot_info_valid
	}
	//0x1290
	for (i = 1002; (i != 0) && (Data_80005088 != 0); i--)
	{
		if ((*((volatile unsigned int*)PWDN_CTRL4) & (1 << 0)) && //acpu_boot_info_valid
				(func_e4e8(0xace6) != 0))
		{
			break;
		}

		mdelay(TIMERID_0, 1);
	}

	if (i == 0)
	{
		//0x15e0
		Data_80005088 = 0;
	}
	//0x12d4
	if ((*((volatile unsigned int*)ISO_DUMMY1) & 0xff000000) == 0xff000000)
	{
		//0x1558
		*((volatile unsigned int*)ISO_DUMMY1) &= 0x01;
	}
	//12f0
	if ((*((volatile unsigned int*)ISO_DUMMY2) & 0xff000000) == 0xff000000)
	{
		//0x1550
		*((volatile unsigned int*)ISO_DUMMY2) = 0;
	}
	//130c
	func_d55c();

	init_uart();

	*((volatile unsigned int*)INV_INTEN) = 0;

//	prints("\nBanana Pi BPI-W2(SPI ROM:20180907)\n");

	prints("\nC1:");
	print_hex( d_30 );

	Data_80005058 = func_84f4();

	Data_80005068 /*Data_80005D98.Data_20*/ = func_8540();

	Data_8000508C = func_8534();
	Data_80005090 = func_84d0();

	if (Data_80005058 == 1)
	{
		//->0x160c
		func_85e4(&Data_80005b58);
	}
	//1368
	func_12a50(0);
	func_d5e0();

	prints("\nC2");
	//1380
	if (Data_80005058 == 0)
	{
		//1388
		prints("\n?");
	}
	else
	{
		//0x14b8
		prints("\n+");
		//->1394
	}

	while (1)
	{
		//1394
		if (Data_80005088 == 0)
		{
			//13a0
			func_5da8(); //->uart.c
			asm volatile("isb");

			sp60 = func_695c();
			if (sp60 > 0)
			{
				//13bc
				func_5dc4(); //->uart.c

				if (func_6ae4() != 1)
				{
					return 0x9f;
				}
			}
			//0x13e0
			func_5dc4(); //->uart.c
		}
		//0x13e4
		func_de8(1);

		prints("\nC3");

		Data_80005094 = 0;

		prints("h");

		if ((Data_80005088 == 0) && (Data_80005058 == 1))
		{
			//0x15bc
			*((volatile unsigned int*)CP_OTP_LOAD) |= (1 << 0); //otp_load

			while (*((volatile unsigned int*)CP_OTP_LOAD) & (1 << 0));
		}
		//0x1424
		Data_80005080 = func_7ff0();

		if (Data_80005080 == 1)
		{
			//0x1598
			*((volatile unsigned int*)SB2_MUXPAD5) |= (1 << 0); //sf_en

			w19 = func_4844(&Data_80005094);
			//->1474
		}
		else if (Data_80005080 == 0)
		{
			//0x15ec
			*((volatile unsigned int*)SYS_muxpad0) = 0x55555555;

			w19 = func_3acc(&Data_80005094);
			//->1474
		}
		else if (Data_80005080 == 2)
		{
			//1444
			*((volatile unsigned int*)SYS_muxpad0) = (*((volatile unsigned int*)SYS_muxpad0) & 0xf3c3) | 0xaaaa0828;

			w19 = func_599c(&Data_80005094);
		}
		else
		{
			//0x1568
			w19 = 0x92;
	#if 0
			print_hex(w19);

			func_de8(0);

			Data_80005064 = w19;
			return w19;
	#endif
		}
		//1474
		if (w19 != 0)
		{
			//->0x1570
			print_hex(w19);

			func_de8(0);

			Data_80005064 = w19;
			return w19;
		}
		//147c
		prints("\nhwsetting size: ");
		print_hex(Data_80005094);
		prints("\n");

		if (Data_80005088 != 0xace2)
		{
			//->0x13d0
	#if 0
			return 0;
	#else
			break;
	#endif
		}
		//14b4
		func_11b4();

		prints("\n+");
		//->1394
	}

	return 0;
}

extern int func_73c0(void* a, int b, void* c, void* d, int e);
extern unsigned int func_c7b8(int a);


/* 161c - todo */
int func_161c(void)
{
	int w20;
	volatile unsigned int sp32;
	volatile unsigned int sp36;
	volatile int sp40;
	volatile unsigned int sp44;

	prints("C4\n");
	prints("C4 ..\n");
	prints("b");

	func_66b4(&Data_80005080, (unsigned int)&Data_80005080 + 4);

#if 0
	if (Data_80005080 == 1)
	{
		//0x1814
		w20 = func_4948();
	}
	else if (Data_80005080 == 2)
	{
		//0x1798
		w20 = func_5b94();
	}
	else if (Data_80005080 == 0)
	{
		//0x1808
		w20 = func_3674();
	}
	else
	{
		//1674
		w20 = 0x92;
	}
#else
	switch (Data_80005080)
	{
	case 0:
		//0x1808
		w20 = func_3674();
		break;

	case 1:
		//0x1814
		w20 = func_4948();
		break;

	case 2:
		//0x1798
		w20 = func_5b94();
		break;

	default:
		w20 = 0x92;
		break;
	}
#endif

	if (w20 != 0)
	{
		//0x1678
		print_hex(w20);

		func_de8(0);
	}
	//0x1684
	prints("C5\n");

	sp32 = Data_8000505c;
	sp36 = Data_80005060;

	if (func_d678(REG32(ISO_DUMMY2)) != 0)
	{
		//16b8
		sp44 = 0x20000;
	}
	else
	{
		//0x17a4
		sp44 = REG32(ISO_DUMMY2);
	}

	prints("\n5-1");

	if (Data_80005058 == 1)
	{
		//17c4
		w20 = func_73c0(sp32, sp36, sp44, 0, 0);
	}
	else
	{
		w20 = 0;
	}

	prints("\n5-3");

	if (w20 == 0)
	{
		//0x16e4
		unsigned int r0;
		if (Data_80005058 == 1)
		{
			//0x1820
			r0 = *((unsigned int*)(sp44 + sp36 - 4));
		}
		else
		{
			//16f0
			r0 = *((unsigned int*)(sp32 + sp36 - 4));
		}

		Data_80005098 = func_c7b8(r0) >> 3;

		sp40 = sp32 + sp36;

		prints("\n5-4");

		//1730
		if (Data_80005058 == 1)
		{
			w20 = func_ab8(sp44, Data_80005098, sp40, Data_8000507C);
		}
		else
		{
			w20 = func_ab8(sp32, Data_80005098, sp40, Data_8000507C);
		}
	}
    //17f8
	prints("C6\n");
    //1760
	if (w20 != 0)
	{
		//1764
		print_hex(w20);

		func_de8(0);

		prints("C7\n");

		Data_80005064 = w20;

		return w20;
	}
	//0x1840
	func_11b4();
}





