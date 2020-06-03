

#include "uart.h"

extern unsigned int d_30;

int Data_8000500C; //8000500C
unsigned int Data_8000501C; //8000501C
unsigned int Data_80005020; //80005020

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



void main()
{
}


/* 1c58 - todo */
int func_1c58(void)
{
	int ret;
	int i;
	int w19;
	int w22;
	int sp56 = 0x3a3b3c3d;
	int sp60 = 0x3a3b3c3d;

	func_73c8(0);
	func_75fc();

	Data_8000501C = *((volatile unsigned int*)PWDN_CTRL2);

	if (((Data_8000501C) - 0xace2) & ~0x02)
	{
		//1ca8
		Data_8000501C = 0xdada;
	}
	//0x1f30
	else if (Data_8000501C != 0xdada)
	{
		//1f3c

		func_db5c(16);

	}
	//0x1cb0
	for (i = 0; (i < 1002) && (Data_8000501C != 0xdada); i++)
	{
		if (*((volatile unsigned int*)PWDN_CTRL4) & 0x01)
		{
			if (func_fcd4(0xace6) != 0)
			{
				break;
			}
		}

		func_fdb0(0, 1);
	}
	//1cfc
	if ((*((volatile unsigned int*)ISO_DUMMY1) & 0xff000000) == 0xff000000)
	{
		//0x2084
		*((volatile unsigned int*)ISO_DUMMY1) &= 0x01;
	}
	//1d18
	if ((*((volatile unsigned int*)ISO_DUMMY2) & 0xff000000) == 0xff000000)
	{
		//0x207c
		*((volatile unsigned int*)ISO_DUMMY2) = 0;
	}
	//1d34
	func_e77c();

	init_uart();

	*((volatile unsigned int*)INV_INTEN) = 0;

	prints("\nBanana Pi BPI-W2(SPI ROM:20180907)\n");
	prints("\nC1:");
	print_hex( d_30 );

	Data_80005D98.Data_20 = func_94cc();

	do
	{
		Data_80005020 = func_94c0();
		if (func_94c0() == Data_80005020)
		{
			//->0x21a4
			break;
		}

		if (func_9458() == 0xdaaa)
		{
			//0x20f4
			func_ec7c();

			*((volatile unsigned int*)REG_0x9801519c) |= 0x01;

			while (*((volatile unsigned int*)REG_0x9801519c) & 0x01);

			*((volatile unsigned int*)ISO_SB2_0) |= 0x01;
		}
		//1da8
		if (*((volatile unsigned int*)SB2_CHIP_INFO) > 0x1ffff)
		{
			//0x1fd0
			func_12784();
		}
		//1dc0
		if (func_9458() == 0xdaaa)
		{
			//0x1fe4
			func_ec7c();
			if (*((volatile unsigned int*)SB2_CHIP_INFO) > 0x1ffff)
			{
				//2000
				func_125a0();
			}
			else
			{
				//0x2130
				func_9570(&Data_80006868);
			}
		}
		//1dd0
		func_16b00(0);
		func_e800();

		prints("\nC2");

		if (func_9458() == 0xbeee)
		{
			//0x206c
			prints("\n?");
		}
		else
		{
			//1df8
			prints("\n+");
		}
		//1e04
		w19 = Data_8000501C;

		if (w19 == 0xdada)
		{
			//0x2008
			func_6898(); //->uart.c
		    asm volatile("isb");

		    sp56 = func_7614(&sp60);
		    asm volatile("isb");

		    w22 = sp60;

		    if (w22 != 0x4a923105)
		    {
				//->0x21a4
				break;
		    }
		    //2034
		    sp60 = sp56;

		    if (sp56 == 0x2f2e2d2c)
		    {
		    	//0x2140
		    	func_68b4(); //->uart.c

		    	if (w19 != Data_8000501C)
		    	{
					//->0x21a4
					break;
		    	}

		    	if (sp60 != sp56)
		    	{
					//->0x21a4
					break;
		    	}

		    	sp56 = func_77cc(&sp60);

		    	if (sp60 != w22)
		    	{
					//->0x21a4
					break;
		    	}
		    	//2178
		    	if (sp56 == 0x6a6a6a6a)
		    	{
		    		//->0x2064
		    	}
		    	//218c
		    	else if (sp56 == 0x21212121)
		    	{
		    		//->0x1f20
		    		return 0x9f;
		    	}
		    	else
		    	{
		    		//21a4
					break;
		    	}
		    }
		    else
		    {
		    	//2050
		    	if (sp56 != 0x3a3b3c3d)
		    	{
					//->0x21a4
					break;
		    	}
		    }
		    //2064
		    func_68b4();
		}
		//1e18
		func_1694(1);

		prints("\nC3");

		Data_80005D98.Data_12 = 0;

		prints("h");

		*((volatile unsigned int*)SYS_muxpad1) = 0x55550555;
		*((volatile unsigned int*)EMMC_PFUNC_NF2) = 0x03200332;

		Data_80005D98.Data_8 = 0;

		*((volatile unsigned int*)EMMC_PFUNC_CR) = 0x33333323;

		func_75fc();
		func_11250();

		if (func_11394() == 4)
		{
			//->0x2094
			prints("\nSD card is detected !!\n");

			Data_80005D98.bData_32 = 1;

			ret = func_12b4(&Data_80005D98.Data_12, &Data_80005D98.Data_8);
			if (ret != 0)
			{
				//20bc
				print_hex(ret);

				func_1694(0);

				Data_8000500C = ret;

				return ret;
			}
			else
			{
				//->1ef0
			}
		}
		else
		{
			//1e94
			prints("\nSD card is not detected !!\n");

			if (func_12b4(&Data_80005D98.Data_12, &Data_80005D98.Data_8) == 0)
			{
				//->0x1fc0
				prints("BPI: try get_builtin_hwsetting !!\n");
				//->1ecc
			}
			else
			{
				//1eb8
				ret = func_1338(&Data_80005D98.Data_12, &Data_80005D98.Data_8);
				if (ret != 0)
				{
					//->20bc
					print_hex(ret);

					func_1694(0);

					Data_8000500C = ret;

					return ret;
				}
			}
			//1ecc
			prints("\nhwsetting size: ");
			print_hex(Data_80005D98.Data_12);
			prints("\n");
		}
		//1ef0
		if (Data_80005D98.Data_8 != 0x84a130bb)
		{
			//->0x21a4
			break;
		}
		//1f08
		if (Data_8000501C == 0xace2)
		{
			//->21a8

			//TODO

			Data_80005D98.Data_36 = 0;

		}
		else
		{
			//1f20
			return 0;
		}
	}
	while (0);
	//0x21a4
	func_1500();
	//21a8
}














