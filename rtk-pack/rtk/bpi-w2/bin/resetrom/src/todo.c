
#include "uart.h"
#include "timer.h"
#include "usb.h"
#include "usb_ch9.h"

extern unsigned int func_12abc(unsigned int n_bytes);


struct usb_endpoint_descriptor Data_80005010;
struct usb_endpoint_descriptor Data_80005020;

int Data_80005078; //80005078 +120
extern int Data_80005080; //80005080 +128
int Data_800050B0; //800050B0 +176
int Data_800050B8; //800050B8 +184

struct Struct_80005748_
{
	void* Data_80005748; //80005748 0x80005000 +1864
	void* Data_80005750; //80005750 80005748 +8
	void* Data_80005758; //80005758 80005748 +16

	void* Data_800057A8; //800057A8 +96
	unsigned short wData_800057B0; //800057B0 +104

	void* Data_800057B8; //800057B8 +112
	unsigned short wData_800057C0; //800057C0 +120

	void* Data_800057C8; //800057C8 +128
	unsigned short wData_800057D0; //800057D0 +136

	void* Data_800057D8; //800057D8 +144
	unsigned short wData_800057E0; //800057E0 +152

	void* Data_80005808; //80005808 +192
	unsigned short wData_80005810; //80005810 +200

	void* Data_80005818; //80005818 +208
	unsigned short wData_80005820; //80005820 +216

	char* Data_800058B0; //800058B0 +360

	char bData_800058B9; //800058B9 80005748 +369
	char bData_800058BA; //800058BA

	char* Data_800058D0; //800058D0 +392

	int fill_50[24];

	char bData_80005934; //80005934 80005748 +492

//	struct usb_device_descriptor Data_80005938; //80005938 +496

} volatile Data_80005748_; //80005748

struct usb_device_descriptor Data_80005938; //80005938 +496
struct dwc3 Data_80005950; //80005950
struct bla
{
	int Data_488; //488
	int Data_492; //492
	int Data_496; //496

} bla;

void* volatile Data_80005748; //80005748 0x80005000 +1864
void* volatile Data_80005750; //80005750
void* volatile Data_80005758; //80005758

//80005790
//80005798

#if 0
void* Data_800057A8; //800057A8 +96
unsigned short wData_800057B0; //800057B0 +104
void* Data_800057B8; //800057B8 +112
unsigned short wData_800057C0; //800057C0 +120
void* Data_800057C8; //800057C8 +128
unsigned short wData_800057D0; //800057D0 +136
void* Data_800057D8; //800057D8 +144
unsigned short wData_800057E0; //800057E0 +152
void* Data_80005808; //80005808 +192
unsigned short wData_80005810; //80005810 +200
void* Data_80005818; //80005818 +208
unsigned short wData_80005820; //80005820 +216
#endif
char* Data_800058B0; //800058B0 +360
char bData_800058B8; //800058B8 +368
char bData_800058B9; //800058B9 80005748 +369
char bData_800058BA; //800058BA
unsigned short wData_800058BC; //800058BC +372
char* Data_800058D0; //800058D0 +392


struct dwc3* get_dwc()
{
	return &Data_80005950;
}

extern unsigned int OTP_JUDGE_BIT(unsigned int offset);


/* 12b4 - todo */
int func_12b4(int* a, int* b)
{

}


/* 1338 - todo */
int func_1338(int* a, int* b)
{

}



/* 1500 - todo */
void func_1500(void)
{

}


/* de8 - complete */
void func_de8(int a)
{
#define OTP_BIT_SECUREBOOT		3494 //0xda6
#define OTP_USB2SRAM			3522 //0xdc2

	if (OTP_JUDGE_BIT(OTP_USB2SRAM) && OTP_JUDGE_BIT(OTP_BIT_SECUREBOOT))
	{
		prints("Security: Fobidden to enter USB Device Mode!");
		while (1);
	}

	if (a != 1)
	{
		REG32(ISO_COLD_RST9) |= (1 << 2);

		func_d8d8();

		sync();
	}
	else
	{
		Data_80005078 = func_8140();

		if ((Data_80005078 == 1) ||
				(REG32(ISO_COLD_RST9) & (1 << 2)))
		{
			REG32(ISO_COLD_RST9) &= ~(1 << 2);

			prints("u");

			func_a284();
		}
	}
}


#if 0
/* 11b4 - todo */
void func_11b4(void)
{

}
#endif

/* 3acc - todo */
int func_3acc(void* a)
{

}


/* 3674 - todo */
int func_3674(void)
{

}


/* 4844 - todo */
int func_4844(void* a)
{

}


/* 4948 - todo */
int func_4948(void)
{

}


/* 599c - todo */
int func_599c(void* a)
{

}


/* 5b94 - todo */
int func_5b94(void)
{

}


extern int Data_80005084; //80005084


#if 0
/* 66b4 - todo */
void flush_cache(unsigned long start, unsigned long size)
{
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
}
#endif


/* 6728 - todo */
void func_6728(int a)
{

}

#if 0
/* 6944 - todo */
void sync(void)
{
	CP15DMB;
	//(*(volatile unsigned int *)(0x9801a020)) =0x0;
	*((unsigned int*)SB2_SYNC) = 0;
    CP15DMB;
}
#endif

/* 695c - todo */
int func_695c(void)
{

}


/* 6ae4 - todo */
int func_6ae4(void)
{

}


/* 7614 - todo */
int func_7614(int* a)
{

}


/* 73c0 - todo */
int func_73c0()
{

}


/* 77a0 - todo */
int func_77a0(int a, int b, int c, int d)
{

}

#define EFUSE_DATA_110	0x980171B8
#define EFUSE_DATA_113	0x980171C4

/* 7fa0 - complete */
int func_7fa0(void)
{
	int w1 = (REG32(EFUSE_DATA_113) >> 2) & 1;
	int w2 = (REG32(EFUSE_DATA_113) >> 3) & 1;

	if (!w1 && !w2)
	{
		//None
		return -1;
	}

	if (w1 && !w2)
	{
		//Only w1
		return 2;
	}

	if (!w1 && w2)
	{
		//Only w2
		return 1;
	}

	//Both
	return 0;
}


/* 7ff0 - complete (sync not inlined */
int func_7ff0(void)
{
	unsigned int w0, w1;

	int w19;
	int w22;
	unsigned int w20 = REG32(PLL_EMMC1);
	unsigned int w21 = REG32(EMMC_PAD_CTL);

	sync();

	REG32(PLL_EMMC1) = (1<<19)|(3<<17)|(1<<1)|(1<<0); //reg_tuned3318 | reg_d3318pow | phrt0 | bias_en
	REG32(EMMC_PAD_CTL) = 0;

	mdelay(0, 10);
	CP15ISB;
	sync();

	REG32(MIS_GP1DIR) = REG32(MIS_GP1DIR) & 0xf9ffffff;

	w0 = REG32(MIS_GP1DATI) & (1 << 25);
	w1 = REG32(MIS_GP1DATI) & (1 << 26);

	if (w0 && !w1)
	{
		w22 = 0;
	}
	else if (!w0 && w1)
	{
		w22 = 1;
	}
	else if (w0 && w1)
	{
		w22 = 3;
	}
	else
	{
		w22 = 2;
	}

	w19 = func_7fa0();
	if (w19 < 0)
	{
		w19 = w22;
	}

	if ((w19 != 1) && (Data_80005080 != 2))
	{
		REG32(PLL_EMMC1) = w20;
		REG32(EMMC_PAD_CTL) = w21;

		mdelay(0, 10);
		CP15ISB;
		sync();
	}

	switch (w19)
	{
		case 0: return 1;
		case 1: return 2;
		case 2: return 0;
		case 3: return 3;
		default: return -1;
	}
}


/* 8140 - todo */
int func_8140(void)
{
	unsigned int w19;
	unsigned int w20;
	unsigned int w24 = REG32(PLL_EMMC1);
	unsigned int w23 = REG32(EMMC_PAD_CTL);

	sync();

	REG32(PLL_EMMC1) = (1<<19)|(3<<17)|(1<<1)|(1<<0); //reg_tuned3318 | reg_d3318pow | phrt0 | bias_en
	REG32(EMMC_PAD_CTL) = 0;

	mdelay(0, 10);
	CP15ISB;
	sync();

	REG32(MIS_GP1DIR) = REG32(MIS_GP1DIR) & 0xf9ffffff;

	w19 = REG32(MIS_GP1DATI) & (1 << 25);
	w20 = REG32(MIS_GP1DATI) & (1 << 26);

	Data_80005080 = func_7ff0();
	if (Data_80005080 != 2)
	{
		REG32(PLL_EMMC1) = w24;
		REG32(EMMC_PAD_CTL) = w23;

		mdelay(0, 5);
		CP15ISB;
		sync();
	}

	if (w19 && w20)
	{
		if ((REG32(EFUSE_DATA_110) & (1 << 2)) != (1 << 2))
		{
			return 1;
		}
	}

	return 0;
}


/* 84d0 - todo */
int func_84d0(void)
{

}


/* 84f4 - todo */
int func_84f4(void)
{

}


/* 8534 - complete */
int func_8534(void)
{
	return 0x88120800;
}


/* 8540 - complete */
int func_8540(void)
{
	return 0;
}


/* 85e4 - todo */
void func_85e4(void* a)
{

}


static struct usb_device_descriptor* get_device_descriptor(/*struct usb_device_descriptor* a*/)
{
#if 0
	struct usb_device_descriptor* p = &Data_80005938;

	p->bDeviceClass = 0;
	p->bLength = USB_DT_DEVICE_SIZE;
	p->bDescriptorType = USB_DT_DEVICE;
	p->iManufacturer = 1;
	p->bNumConfigurations = 1;
	p->idProduct = 0x1195;
	p->bcdDevice = 0x100;
	p->bcdUSB = 0x200;
	p->iProduct = 2;
	p->bMaxPacketSize0 = 64;
	p->iSerialNumber = 3;
	p->idVendor = 0xbda;
	p->bDeviceSubClass = 0;
	p->bDeviceProtocol = 0;

	return p;
#else
#if 0
	static struct usb_device_descriptor Data_80005938_; /* =
	{
			.bLength = USB_DT_DEVICE_SIZE,
			.bDescriptorType = USB_DT_DEVICE,
#if 0
			.bcdUSB = 0x200,
			0,
			0,
			0,
			64,
			0xbda,
			0x1195,
			0x100,
			1,
			2,
			3
#endif
	};*/

//	Data_80005938_.bcdUSB = 0x200;
#endif

	return 0; //&Data_80005938;
#endif
}


/* 8fe4 - todo */
void func_8fe4(void)
{
	static const struct
	{
		struct usb_config_descriptor config;
		struct usb_interface_descriptor interface;
		struct usb_endpoint_descriptor endpoint3;
		struct usb_endpoint_descriptor endpoint4;

	} __attribute__ ((packed))
	Data_11ee0 =
	{
		{
			USB_DT_CONFIG_SIZE,
			USB_DT_CONFIG,
			32,
			1,
			1,
			0,
			0xc0,
			50,
		},
		{
			USB_DT_INTERFACE_SIZE,
			USB_DT_INTERFACE,
			0,
			0,
			2,
			0xff,
			0xff,
			0x50,
			0,
		},
		{
			USB_DT_ENDPOINT_SIZE,
			USB_DT_ENDPOINT,
			0x81,
			0x02,
			512,
			0,
		},
		{
			USB_DT_ENDPOINT_SIZE,
			USB_DT_ENDPOINT,
			0x02,
			0x02,
			512,
			0,
		}
	};

	static const struct
	{
		struct usb_otg_descriptor otg;
		char bData_3;

	} __attribute__ ((packed))
	Data_11f00 =
	{
		{
			4,
			USB_DT_OTG,
			0x03,
		},
		0x04,
	};

	static const struct
	{
		struct usb_string_descriptor string1;
		__le16 string_char[];

	}__attribute__ ((packed))
	Data_11f08 =
	{
		{
			16,
			USB_DT_STRING,
			'R',
		},
		{'e','a','l','t','e','k'},
	};

	static const struct
	{
		struct usb_string_descriptor string1;
		__le16 string_char[];

	}__attribute__ ((packed))
	Data_11f18 =
	{
		{
			32,
			USB_DT_STRING,
			'U',
		},
		{'S','B',' ','R','E','D','I','R','E','C','T','I','O','N'},
	};

	static const struct
	{
		struct usb_string_descriptor string1;
		__le16 string_char[];

	}__attribute__ ((packed))
	Data_11f38 =
	{
		{
			28,
			USB_DT_STRING,
			'0',
		},
		{'3','5','7','8','0','2','1','1','5','9','4','6'}, //0357802115946
	};

	static const struct
	{
		struct usb_string_descriptor string1;
		__le16 string_char[];

	}__attribute__ ((packed))
	Data_11f58 =
	{
		{
			26,
			USB_DT_STRING,
			'#',
		},
		{'#','#','#','#','#','#','#','#','#','#','#','#'},
	};

	static const struct
	{
		struct usb_string_descriptor string1;
		__le16 string_char[];

	}__attribute__ ((packed))
	Data_11f78 =
	{
		{
			28,
			USB_DT_STRING,
			'R',
		},
		{'T','L','8','1','1','1','D','P','D','A','S','H'}, //RTL 8111 DP DASH console tool?
	};

	static const struct usb_qualifier_descriptor Data_11f98 =
	{
			10,
			USB_DT_DEVICE_QUALIFIER,
			0x0200,
			0,
			0,
			0,
			64,
			1,
			0
	};

	static const struct
	{
		struct usb_config_descriptor config;
		struct usb_interface_descriptor interface;
		struct usb_endpoint_descriptor endpoint3;
		struct usb_endpoint_descriptor endpoint4;

	}__attribute__ ((packed))
	Data_11fa8 =
	{
		{
			USB_DT_CONFIG_SIZE,
			USB_DT_OTHER_SPEED_CONFIG,
			32, //wTotalLength
			1, //bNumInterfaces
			1, //bConfigurationValue
			0, //iConfiguration
			0xc0, //bmAttributes
			50
		},
		{
			USB_DT_INTERFACE_SIZE,
			USB_DT_INTERFACE,
			0,
			0,
			2,
			0x08,
			0x06,
			0x50,
			0,
		},
		{
			USB_DT_ENDPOINT_SIZE,
			USB_DT_ENDPOINT,
			0x81,
			0x02,
			64,
			0,
		},
		{
			USB_DT_ENDPOINT_SIZE,
			USB_DT_ENDPOINT,
			0x02,
			0x02,
			64,
			0,
		}
	};

	struct
	{
		char bData[32];
	}* x20;

	x20 = func_12abc(512);
	memset(x20, 0, 512);

	Data_80005748_.Data_800058B0 = func_12abc(8);
	memset(Data_80005748_.Data_800058B0, 0, 8);

	Data_80005748_.Data_800058D0 = func_12abc(8);
	memset(Data_80005748_.Data_800058D0, 0, 8);

#if 0
	Data_80005938.bDeviceClass = 0;
	Data_80005938.bLength = USB_DT_DEVICE_SIZE;
	Data_80005938.bDescriptorType = 1;
	Data_80005938.iManufacturer = 1;
	Data_80005938.bNumConfigurations = 1;
	Data_80005938.idProduct = 0x1195;
	Data_80005938.bcdDevice = 0x100;
	Data_80005938.bcdUSB = 0x200;
	Data_80005938.iProduct = 2;
	Data_80005938.bMaxPacketSize0 = 64;
	Data_80005938.iSerialNumber = 3;
	Data_80005938.idVendor = 0xbda;
	Data_80005938.bDeviceSubClass = 0;
	Data_80005938.bDeviceProtocol = 0;
#endif

	copy_memory(x20, get_device_descriptor(), USB_DT_DEVICE_SIZE);

	Data_80005748_.Data_800057B8 = x20;
	Data_80005748_.wData_800057C0 = USB_DT_DEVICE_SIZE;

	copy_memory(&x20[1], &Data_11ee0, 32);

	Data_80005748_.Data_800057A8 = &x20[1];
	Data_80005748_.wData_800057B0 = 32;

	Data_80005748_.Data_800057C8 = (unsigned int)Data_80005748_.Data_800057A8;
	Data_80005748_.wData_800057D0 = Data_80005748_.wData_800057B0;

	copy_memory(&x20[2], &Data_11f00, 4);

	Data_80005748_.Data_800057D8 = &x20[2];
	Data_80005748_.wData_800057E0 = 0;

	copy_memory(&x20[3], &Data_11f08, 16);
	copy_memory(&x20[4], &Data_11f18, 32);
	copy_memory(&x20[5], &Data_11f38, 32);
	copy_memory(&x20[6], &Data_11f58, 32);
	copy_memory(&x20[7], &Data_11f78, 32);

	copy_memory(&x20[8], &Data_11f98, 10);

	Data_80005748_.Data_80005808 = &x20[8];
	Data_80005748_.wData_80005810 = 10;

	copy_memory(&x20[9], &Data_11fa8, 32);

	Data_80005748_.Data_80005818 = &x20[9];
	Data_80005748_.wData_80005820 = 32;
}

static inline int rtk_xhci_usb2_phy_write(unsigned char addr, unsigned char data)
{
	unsigned int regVal;

#if 0
	__raw_writeb(data, (volatile u32*)(dwc3.wrap_addr + REG_WRAP_VUSB2StatusOut2));
#else
	REG32(0x98013214) = data;
#endif

	// VCtrl = low nibble of addr, VLoadM = 1
	regVal = (1 << 25) |
			 ((addr & 0x0f) << 8);

#if 0
	__raw_writel(regVal, (volatile u32*)(dwc3.dwc3_addr + REG_GUSB2PHYACC0));
	xhci_usb_utmi_wait_register(dwc3.dwc3_addr + REG_GUSB2PHYACC0, USB_ST_BUSY, 0);
#else
	func_8db0(regVal);
#endif

	// VCtrl = low nibble of addr, VLoadM = 0
	regVal = (1 << 25) |
			 ((addr & 0xf0) << 4);

#if 0
	__raw_writel(regVal, (volatile u32*)(dwc3.dwc3_addr + REG_GUSB2PHYACC0));
	xhci_usb_utmi_wait_register(dwc3.dwc3_addr + REG_GUSB2PHYACC0, USB_ST_BUSY, 0);
#else
	func_8db0(regVal);
#endif

	return 0;
}


/* 91d4 - complete */
void rtk_dwc3_usb2_phy_setting(void)
{
	rtk_xhci_usb2_phy_write(0xf4, 0x9b);
	rtk_xhci_usb2_phy_write(0xf4, 0x9b);
	rtk_xhci_usb2_phy_write(0xe0, 0xe1);
	rtk_xhci_usb2_phy_write(0xe0, 0xe1);
	rtk_xhci_usb2_phy_write(0xe1, 0x2e);
	rtk_xhci_usb2_phy_write(0xe1, 0x2e);
	rtk_xhci_usb2_phy_write(0xe2, 0xb5);
	rtk_xhci_usb2_phy_write(0xe2, 0xb5);
	rtk_xhci_usb2_phy_write(0xe4, 0x9b);
	rtk_xhci_usb2_phy_write(0xe4, 0x9b);
	rtk_xhci_usb2_phy_write(0xe6, 0xca);
	rtk_xhci_usb2_phy_write(0xe6, 0xca);
	rtk_xhci_usb2_phy_write(0xf4, 0xbb);
	rtk_xhci_usb2_phy_write(0xf4, 0xbb);
	rtk_xhci_usb2_phy_write(0xe0, 0x25);
	rtk_xhci_usb2_phy_write(0xe0, 0x25);
	rtk_xhci_usb2_phy_write(0xe1, 0xef);
	rtk_xhci_usb2_phy_write(0xe1, 0xef);
	rtk_xhci_usb2_phy_write(0xe5, 0x0f);
	rtk_xhci_usb2_phy_write(0xe5, 0x0f);
	rtk_xhci_usb2_phy_write(0xe7, 0xe3);
	rtk_xhci_usb2_phy_write(0xe6, 0x18);
	rtk_xhci_usb2_phy_write(0xe6, 0x18);
}

#define REG_MDIO_CTL 0x10//0x18013210

static int rtk_xhci_usb3_phy_write(char addr, unsigned short data)
{
	volatile unsigned int regVal;

	regVal = (1 << 0) |
			(addr << 8) |
			(data <<16);
#if 0
	__raw_writel(regVal, (volatile u32*)(dwc3.wrap_addr + REG_MDIO_CTL));

	rtk_usb_phy3_wait_vbusy(dwc3);
	mdelay(10);
#else
	while ((REG32(0x98013210) & 0x50) == 0x50);
	REG32(0x98013210) = regVal;
#endif
	return 0;
}


/* 9438 - complete */
void rtk_dwc3_usb3_phy_setting(void)
{
	rtk_xhci_usb3_phy_write(0x00, 0x4008);
	rtk_xhci_usb3_phy_write(0x01, 0xa878);
	rtk_xhci_usb3_phy_write(0x02, 0x6046);
	rtk_xhci_usb3_phy_write(0x03, 0x2771);
	rtk_xhci_usb3_phy_write(0x04, 0xb2f5);
	rtk_xhci_usb3_phy_write(0x05, 0x2ad7);
	rtk_xhci_usb3_phy_write(0x06, 0x0001);
	rtk_xhci_usb3_phy_write(0x07, 0x3200);
	rtk_xhci_usb3_phy_write(0x08, 0x3590);
	rtk_xhci_usb3_phy_write(0x09, 0x325c);
	rtk_xhci_usb3_phy_write(0x0a, 0xd643);
	rtk_xhci_usb3_phy_write(0x0b, 0xe909);
	rtk_xhci_usb3_phy_write(0x0c, 0xc008);
	rtk_xhci_usb3_phy_write(0x0d, 0xff28);
	rtk_xhci_usb3_phy_write(0x0e, 0x2010);
	rtk_xhci_usb3_phy_write(0x0f, 0x8000);
	rtk_xhci_usb3_phy_write(0x10, 0x000c);
	rtk_xhci_usb3_phy_write(0x11, 0x4c00);
	rtk_xhci_usb3_phy_write(0x12, 0xfc00);
	rtk_xhci_usb3_phy_write(0x13, 0x0c81);
	rtk_xhci_usb3_phy_write(0x14, 0xde01);
	rtk_xhci_usb3_phy_write(0x15, 0x0000);
	rtk_xhci_usb3_phy_write(0x16, 0x0000);
	rtk_xhci_usb3_phy_write(0x17, 0x0000);
	rtk_xhci_usb3_phy_write(0x18, 0x0000);
	rtk_xhci_usb3_phy_write(0x19, 0x7004);
	rtk_xhci_usb3_phy_write(0x1a, 0x1260);
	rtk_xhci_usb3_phy_write(0x1b, 0xff0c);
	rtk_xhci_usb3_phy_write(0x1c, 0xcb1c);
	rtk_xhci_usb3_phy_write(0x1d, 0xa03f);
	rtk_xhci_usb3_phy_write(0x1e, 0xc200);
	rtk_xhci_usb3_phy_write(0x1f, 0x9000);
	rtk_xhci_usb3_phy_write(0x20, 0xd4ff);
	rtk_xhci_usb3_phy_write(0x21, 0xaaff);
	rtk_xhci_usb3_phy_write(0x22, 0x0051);
	rtk_xhci_usb3_phy_write(0x23, 0xdb60);
	rtk_xhci_usb3_phy_write(0x24, 0x0800);
	rtk_xhci_usb3_phy_write(0x25, 0x0000);
	rtk_xhci_usb3_phy_write(0x26, 0x0004);
	rtk_xhci_usb3_phy_write(0x27, 0x01d6);
	rtk_xhci_usb3_phy_write(0x28, 0xf882);
	rtk_xhci_usb3_phy_write(0x29, 0x3080);
	rtk_xhci_usb3_phy_write(0x2a, 0x3083);
	rtk_xhci_usb3_phy_write(0x2b, 0x2038);
	rtk_xhci_usb3_phy_write(0x2c, 0xffff);
	rtk_xhci_usb3_phy_write(0x2d, 0xffff);
	rtk_xhci_usb3_phy_write(0x2e, 0x0000);
	rtk_xhci_usb3_phy_write(0x2f, 0x0040);
	rtk_xhci_usb3_phy_write(0x09, 0x325c);
	rtk_xhci_usb3_phy_write(0x09, 0x305c);
	rtk_xhci_usb3_phy_write(0x09, 0x325c);
}


/* 9e80 - complete */
void dwc3_core_soft_reset(void)
{
	unsigned int reg;

	/* Before Resetting PHY, put Core in Reset */
	reg = dwc3_readl(DWC3_GCTL);
	reg |= DWC3_GCTL_CORESOFTRESET;
	dwc3_writel(DWC3_GCTL, reg);

	/* Assert USB3 PHY reset */
	reg = dwc3_readl(DWC3_GUSB3PIPECTL(0));
	reg |= DWC3_GUSB3PIPECTL_PHYSOFTRST;
	dwc3_writel(DWC3_GUSB3PIPECTL(0), reg);

	/* Assert USB2 PHY reset */
	reg = dwc3_readl(DWC3_GUSB2PHYCFG(0));
	reg |= DWC3_GUSB2PHYCFG_PHYSOFTRST;
	dwc3_writel(DWC3_GUSB2PHYCFG(0), reg);

	rtk_dwc3_usb3_phy_setting();
	mdelay(0, 100);

	/* Clear USB3 PHY reset */
	reg = dwc3_readl(DWC3_GUSB3PIPECTL(0));
	reg &= ~DWC3_GUSB3PIPECTL_PHYSOFTRST;
	dwc3_writel(DWC3_GUSB3PIPECTL(0), reg);

	/* Clear USB2 PHY reset */
	reg = dwc3_readl(DWC3_GUSB2PHYCFG(0));
	reg &= ~DWC3_GUSB2PHYCFG_PHYSOFTRST;
	dwc3_writel(DWC3_GUSB2PHYCFG(0), reg);

	mdelay(0, 100);

	/* After PHYs are stable we can take Core out of reset state */
	reg = dwc3_readl(DWC3_GCTL);
	reg &= ~DWC3_GCTL_CORESOFTRESET;
	dwc3_writel(DWC3_GCTL, reg);

	rtk_dwc3_usb2_phy_setting();
	mdelay(0, 100);
}


/* inlined */
static int dwc3_core_init(void)
{
	volatile unsigned int vreg;
	unsigned int reg = dwc3_readl(DWC3_GSNPSID);
	if ((reg & DWC3_GSNPSID_MASK) != 0x55330000)
	{
		prints("this is not a DesignWare USB3 DRD Core\n");
//		return -1;
	}
	else
	{
		dwc3_writel(DWC3_DCTL, DWC3_DCTL_CSFTRST);
		while (1)
		{
			reg = dwc3_readl(DWC3_DCTL);
			if (!(reg & DWC3_DCTL_CSFTRST))
			{
				vreg = reg;
				break;
			}
		}

		dwc3_core_soft_reset();

		dwc3_writel(DWC3_GCTL, vreg);

		dwc3_writel(DWC3_DCFG, dwc3_readl(DWC3_DCFG) & ~0x07);

		dwc3_writel(DWC3_GTXTHRCFG, 0x01010000);

#define RX_THRESHOLD_EN		(1<<29)
#define RX_PKT_CNT(n)		(n<<24)
#define RX_MAX_BURST_SZ(n)	(n<<19)
//		dwc3_writel(DWC3_GRXTHRCFG, RX_THRESHOLD_EN | RX_PKT_CNT(3) | RX_MAX_BURST_SZ(3));
		dwc3_writel(DWC3_GRXTHRCFG, RX_THRESHOLD_EN | RX_PKT_CNT(6) | RX_MAX_BURST_SZ(6));

		dwc3_writel(DWC3_GUCTL, dwc3_readl(DWC3_GUCTL) | (1<<14)); // enable auto retry
	}

	return 0;
}


/* 9f2c - todo */
void func_9f2c(char a)
{
	if (a)
	{
		Data_80005748_.Data_80005748 = func_12abc(81); //malloc
		memset(Data_80005748_.Data_80005748, 0, 81);

		Data_80005748_.Data_80005750 = func_12abc(88);
		memset(Data_80005748_.Data_80005750, 0, 88);

		Data_80005748_.Data_80005758 = func_12abc(52);
		memset(Data_80005748_.Data_80005758, 0, 52);

		*((int*)Data_80005748_.Data_80005758) = 0x53425355;

		func_8fe4();
	}

	Data_80005748_.bData_800058B9 = 0;
	Data_80005748_.bData_800058BA = 0;
	Data_80005748_.bData_80005934 = 0;

	REG32(0x981e8800) &= ~0x03;
	REG32(0x981e8800) &= 0xff7fe7fb;

	dwc3_core_init();

	REG32(0x981e8810) = 0;
	REG32(0x981e8814) = 0;
	REG32(0x981e8818) = 0xffffffff;
	REG32(0x981e881c) = 0;
	REG32(0x981e8014) = 0xffffffff;
	REG32(0x981e8004) = 0xffffffff;
	REG32(0x981e8018) |= 0x30;
	REG32(0x981e8804) &= ~0x02;
	REG32(0x981e8018) |= 0x803c08;
}


/* a11c - todo */
void func_a11c(void)
{
	REG32(SOFT_RESET1) = REG32(SOFT_RESET1) | ((1 << 4) | (1 << 2));

	func_12a50(1); //-> init allocator 1
	func_12b70(1); //-> init allocator 2

	func_b748(1);

	if (func_8140() == 0)
	{
		//0xa274
		Data_80005080 = func_7ff0();
		//->0xa164
	}
	else
	{
		//a158
		Data_80005080 = 3;
	}
	//a164
	Data_800050B0 = 0;

	REG32(0x98013208) |= (1 << 0);
	udelay(0, 200);
	REG32(0x98013208) &= ~(1 << 0);
	udelay(0, 200);

	REG32(0x9801320C) |= (1 << 0);
	udelay(0, 200);
	REG32(0x9801320C) &= ~(1 << 0);
	udelay(0, 200);

	func_9f2c(Data_800050B8 == 0);

	REG32(0x98013258) = 0;
	REG32(0x98013270) = 0;

	dwc3_set_mode(DWC3_GCTL_PRTCAP_DEVICE);
	udelay(0, 100);

	REG32(0x98013244) |= 0x180;
	udelay(0, 100);

	REG32(0x981e800c) |= 0x40000000;
	REG32(0x981e8008) |= 0x23;

	sync();
}


/* a284 - todo */
void func_a284(void)
{
	func_258();
	func_a11c();
	func_b04c();

	mdelay(0, 10);
	sync();
	mdelay(0, 10);
	sync();

	if (Data_800050B8 == 0)
	{
		func_c568();

		Data_800050B8 = 1;
	}
}


/* a2d4 - todo */
void func_a2d4(struct dwc3_ep* a)
{
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
	prints("func_a2d4");
}


/* a320 - todo */
int dwc3_gadget_init_hw_endpoints(struct dwc3* dwc, char num, int direction)
{
	struct dwc3_ep* dep;
	char i;

	for (i = 0; i < num; i++)
	{
		unsigned char epnum = (i << 1) | (!!direction);

		dep = func_12abc(96);
		memset(dep, 0, 96);

		if (dep == 0)
		{
			return -12;
		}

		dep->dwc = dwc;
		dep->number = epnum;
		dep->direction = !!direction;
		dwc->eps[epnum] = dep;

		dep->endpoint.name = dep->name;
	}

	return 0;
}


/* a3f4 - todo */
int dwc3_event_buffers_setup(void)
{
	struct dwc3_event_buffer* evt;
	int i;

	for (i = 0; i < Data_80005950.num_event_buffers; i++)
	{
		evt = Data_80005950.ev_buffs[i];

		evt->lpos = 0;

		dwc3_writel(DWC3_GEVNTADRLO(i), (unsigned int)(evt->buf));
		dwc3_writel(DWC3_GEVNTADRHI(i), 0);
		dwc3_writel(DWC3_GEVNTSIZ(i), (unsigned short)(evt->length));
		dwc3_writel(DWC3_GEVNTCOUNT(i), 0);
	}

	return 0;
}


/* a654 - complete */
int dwc3_send_gadget_ep_cmd(struct dwc3* dwc, unsigned int ep, unsigned int cmd,
		struct dwc3_gadget_ep_cmd_params* params)
{
	unsigned int timeout = 500;
	unsigned int reg;

	dwc3_writel(DWC3_DEPCMDPAR0(ep), params->param0);
	dwc3_writel(DWC3_DEPCMDPAR1(ep), params->param1);
	dwc3_writel(DWC3_DEPCMDPAR2(ep), params->param2);

	sync();

	dwc3_writel(DWC3_DEPCMD(ep), cmd | DWC3_DEPCMD_CMDACT);

	do
	{
		sync();

		reg = dwc3_readl(DWC3_DEPCMD(ep));

		if (!(reg & DWC3_DEPCMD_CMDACT))
		{
			return 0;
		}

		/*
		 * We can't sleep here, because it is also called from
		 * interrupt context.
		 */
		timeout--;
		if (!timeout)
		{
			prints("send cmd timeout\n");
			return -110; //ETIMEDOUT;
		}

		udelay(0, 1);
	}
	while (1);
}


static inline unsigned int dwc3_gadget_ep_get_transfer_index(char number)
{
	unsigned int res_id;

	res_id = dwc3_readl(DWC3_DEPCMD(number));

	return DWC3_DEPCMD_GET_RSC_IDX(res_id);
}


/* a708 - complete */
int dwc3_ep0_start_trans(struct dwc3* dwc, char epnum, unsigned int buf, unsigned int len, unsigned int type)
{
	struct dwc3_gadget_ep_cmd_params params;
	struct dwc3_trb* trb;
	struct dwc3_ep* dep;
	int ret;

	dep = dwc->eps[epnum];

	sync();

	if (dep->flags & DWC3_EP_BUSY)
	{
		prints("dwc->dev ep0 still busy\n");
		return 0;
	}

	trb = dwc->Data_8;

	trb->bpl = buf;
	trb->bph = 0;
	trb->size = len;
	trb->ctrl = type;

	trb->ctrl |= (DWC3_TRB_CTRL_HWO
			| DWC3_TRB_CTRL_ISP_IMI);

	trb->ctrl |= (DWC3_TRB_CTRL_IOC
			| DWC3_TRB_CTRL_LST);

	memset(&params, 0, sizeof(params));

	params.param0 = 0;
	params.param1 = dwc->Data_8;

	ret = dwc3_send_gadget_ep_cmd(dwc, dep->number,
			DWC3_DEPCMD_STARTTRANSFER, &params);
	if (ret < 0)
	{
		return ret;
	}

	dep->resource_index = dwc3_gadget_ep_get_transfer_index(dep->number);

	return 0;
}


/* a7f8 - todo */
void func_a7f8(struct dwc3 *dwc, int b, int c, int d)
{
#if 0
	static int dwc3_ep0_start_trans(struct dwc3 *dwc, u8 epnum, dma_addr_t buf_dma,
					u32 len, u32 type, unsigned chain)
	{
		struct dwc3_gadget_ep_cmd_params params;
		struct dwc3_trb			*trb;
		struct dwc3_ep			*dep;

		int				ret;

		dep = dwc->eps[epnum];
		if (dep->flags & DWC3_EP_BUSY) {
			dev_vdbg(dwc->dev, "%s still busy", dep->name);
			return 0;
		}

		trb = &dwc->ep0_trb[dep->free_slot];

		if (chain)
			dep->free_slot++;

		trb->bpl = lower_32_bits(buf_dma);
		trb->bph = upper_32_bits(buf_dma);
		trb->size = len;
		trb->ctrl = type;

		trb->ctrl |= (DWC3_TRB_CTRL_HWO
				| DWC3_TRB_CTRL_ISP_IMI);

		if (chain)
			trb->ctrl |= DWC3_TRB_CTRL_CHN;
		else
			trb->ctrl |= (DWC3_TRB_CTRL_IOC
					| DWC3_TRB_CTRL_LST);

		dwc3_flush_cache((int)buf_dma, len);
		dwc3_flush_cache((int)trb, sizeof(*trb));

		if (chain)
			return 0;

		memset(&params, 0, sizeof(params));
		params.param0 = upper_32_bits(dwc->ep0_trb_addr);
		params.param1 = lower_32_bits(dwc->ep0_trb_addr);

		ret = dwc3_send_gadget_ep_cmd(dwc, dep->number,
				DWC3_DEPCMD_STARTTRANSFER, &params);
		if (ret < 0) {
			dev_dbg(dwc->dev, "%s STARTTRANSFER failed", dep->name);
			return ret;
		}

		dep->flags |= DWC3_EP_BUSY;
		dep->resource_index = dwc3_gadget_ep_get_transfer_index(dwc,
				dep->number);

		dwc->ep0_next_event = DWC3_EP0_COMPLETE;

		return 0;
	}
#else
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
	prints("func_a7f8");
#endif
}


/* inlined */
static int dwc3_gadget_start_config(struct dwc3 *dwc, struct dwc3_ep *dep)
{
	struct dwc3_gadget_ep_cmd_params params;
	unsigned int cmd;

	memset(&params, 0x00, sizeof(params));

	if (dep->number != 1)
	{
		cmd = DWC3_DEPCMD_DEPSTARTCFG;
		/* XferRscIdx == 0 for ep0 and 2 for the remaining */
		if (dep->number > 1)
		{
			if (dwc->start_config_issued)
			{
				return 0;
			}

			dwc->start_config_issued = 1;
			cmd |= DWC3_DEPCMD_PARAM(2);
		}

		return dwc3_send_gadget_ep_cmd(dwc, 0, cmd, &params);
	}

	return 0;
}

/* inlined */
static int dwc3_gadget_set_ep_config(struct dwc3 *dwc, struct dwc3_ep *dep,
		const struct usb_endpoint_descriptor *desc)
{
	struct dwc3_gadget_ep_cmd_params params;

	memset(&params, 0x00, sizeof(params));

	params.param0 = DWC3_DEPCFG_EP_TYPE(usb_endpoint_type(desc))
		| DWC3_DEPCFG_MAX_PACKET_SIZE(/*usb_endpoint_maxp(desc)*/512);

	params.param0 |= DWC3_DEPCFG_BURST_SIZE(6);

	params.param1 = DWC3_DEPCFG_XFER_COMPLETE_EN
		| DWC3_DEPCFG_XFER_NOT_READY_EN;
	/*
	 * We are doing 1:1 mapping for endpoints, meaning
	 * Physical Endpoints 2 maps to Logical Endpoint 2 and
	 * so on. We consider the direction bit as part of the physical
	 * endpoint number. So USB endpoint 0x81 is 0x03.
	 */
	params.param1 |= DWC3_DEPCFG_EP_NUMBER(dep->number);

	/*
	 * We must use the lower 16 TX FIFOs even though
	 * HW might have more
	 */
	if (dep->direction)
	{
		params.param0 |= DWC3_DEPCFG_FIFO_NUMBER(dep->number >> 1);
	}

	return dwc3_send_gadget_ep_cmd(dwc, dep->number,
			DWC3_DEPCMD_SETEPCONFIG, &params);
}


/* inlined */
static int dwc3_gadget_set_xfer_resource(struct dwc3 *dwc, struct dwc3_ep *dep)
{
	struct dwc3_gadget_ep_cmd_params params;

	memset(&params, 0x00, sizeof(params));

	params.param0 = DWC3_DEPXFERCFG_NUM_XFER_RES(1);

	return dwc3_send_gadget_ep_cmd(dwc, dep->number,
			DWC3_DEPCMD_SETTRANSFRESOURCE, &params);
}


/* a8fc - complete */
int __dwc3_gadget_ep_enable(struct dwc3_ep* dep, struct usb_endpoint_descriptor* desc)
{
	struct dwc3* dwc = dep->dwc;
	unsigned int reg;
	int ret;

	if (!(dep->flags & DWC3_EP_ENABLED))
	{
		ret = dwc3_gadget_start_config(dwc, dep);
		if (ret)
		{
			return ret;
		}
	}

	ret = dwc3_gadget_set_ep_config(dwc, dep, desc);
	if (ret != 0)
	{
		prints("ep enable fail\n");
		return ret;
	}

	if (!(dep->flags & DWC3_EP_ENABLED))
	{
		ret = dwc3_gadget_set_xfer_resource(dwc, dep);
		if (ret != 0)
		{
			return ret;
		}

		dep->endpoint.desc = desc;
		dep->type = usb_endpoint_type(desc);
		dep->flags |= DWC3_EP_ENABLED;

		reg = dwc3_readl(DWC3_DALEPENA);
		reg |= DWC3_DALEPENA_EP(dep->number);
		dwc3_writel(DWC3_DALEPENA, reg);
	}

	return 0;
}


static inline int dwc3_ep0_start_control_status(struct dwc3_ep *dep)
{
	struct dwc3		*dwc = dep->dwc;
	unsigned int			type;

	type = dwc->three_stage_setup ? DWC3_TRBCTL_CONTROL_STATUS3
		: DWC3_TRBCTL_CONTROL_STATUS2;

	return dwc3_ep0_start_trans(dwc, dep->number,
			dwc->/*ctrl_req_addr*/Data_0, 0, type); //, 0);
}


static int dwc3_ep0_set_config(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
	int ret;

	if (Data_80005950.Data_488 != 0)
	{
		//0xade0
		struct dwc3_ep* x21;
		char w22;

		prints("ENUM - stop ep4/ep3\n");

		x21 = dwc->eps[4];
		w22 = x21->resource_index;

		if (w22 == 0)
		{
			//0xaea0
			prints("no resource.\n");
			//->0xae3c
		}
		else
		{
			//adf8
			struct dwc3_gadget_ep_cmd_params sp_0x30;
			memset(&sp_0x30, 0, 12);

			dwc3_send_gadget_ep_cmd(dwc, x21->number, 0x908 | (w22 << 16), &sp_0x30);

			x21->resource_index = 0;
			x21->flags &= ~0x10;

			udelay(0, 100);
		}
		//ae3c
		func_a2d4(dwc->eps[3]);
		func_a2d4(dwc->eps[4]);

		Data_80005950.Data_488 = 0;
	}
	//ac60
	bData_800058B9 = 4;

	Data_80005010.bLength = 7;
	Data_80005010.bDescriptorType = 0;
	Data_80005010.bmAttributes = 3;

	ret = __dwc3_gadget_ep_enable(dwc->eps[3], &Data_80005010);
	if (ret != 0)
	{
		//0xadd0
		prints("ep3 eanble fail return\n");
	}
	//0xac98
	ret = __dwc3_gadget_ep_enable(dwc->eps[4], &Data_80005010);
	if (ret != 0)
	{
		//0xadc0
		prints("ep4 eanble fail return\n");
	}
	//aca8
	Data_80005950.Data_492 = 1;

#if 0
	enum usb_device_state state = dwc->gadget.state;
	u32 cfg;
	int ret;
	u32 reg;

	dwc->start_config_issued = false;
	cfg = le16_to_cpu(ctrl->wValue);

	switch (state) {
	case USB_STATE_DEFAULT:
		return -EINVAL;

	case USB_STATE_ADDRESS:
		ret = dwc3_ep0_delegate_req(dwc, ctrl);
		/* if the cfg matches and the cfg is non zero */
		if (cfg && (!ret || (ret == USB_GADGET_DELAYED_STATUS))) {

			/*
			 * only change state if set_config has already
			 * been processed. If gadget driver returns
			 * USB_GADGET_DELAYED_STATUS, we will wait
			 * to change the state on the next usb_ep_queue()
			 */
			if (ret == 0)
				usb_gadget_set_state(&dwc->gadget,
						USB_STATE_CONFIGURED);

			/*
			 * Enable transition to U1/U2 state when
			 * nothing is pending from application.
			 */
			reg = dwc3_readl(dwc->regs, DWC3_DCTL);
			reg |= (DWC3_DCTL_ACCEPTU1ENA | DWC3_DCTL_ACCEPTU2ENA);
			dwc3_writel(dwc->regs, DWC3_DCTL, reg);

			dwc->resize_fifos = true;
			dev_dbg(dwc->dev, "resize FIFOs flag SET");
		}
		break;

	case USB_STATE_CONFIGURED:
		ret = dwc3_ep0_delegate_req(dwc, ctrl);
		if (!cfg && !ret)
			usb_gadget_set_state(&dwc->gadget,
					USB_STATE_ADDRESS);
		break;
	default:
		ret = -EINVAL;
	}
	return ret;
#endif
}


/* inlined */
static int dwc3_ep0_set_address(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
	unsigned int addr;
	unsigned int reg;

	addr = ctrl->wValue;
	if (addr > 127)
	{
#if 0
		dev_dbg(dwc->dev, "invalid device address %d", addr);
		return -EINVAL;
#else
		return -1;
#endif
	}

#if 0
	if (state == USB_STATE_CONFIGURED) {
		dev_dbg(dwc->dev, "trying to set address when configured");
		return -EINVAL;
	}
#endif

	reg = dwc3_readl(DWC3_DCFG);
	reg &= ~(DWC3_DCFG_DEVADDR_MASK);
	reg |= DWC3_DCFG_DEVADDR(addr);
	dwc3_writel(DWC3_DCFG, reg);

#if 0
	if (addr)
		usb_gadget_set_state(&dwc->gadget, USB_STATE_ADDRESS);
	else
		usb_gadget_set_state(&dwc->gadget, USB_STATE_DEFAULT);
#else
	dwc->Data_440/*ep0state*/ = 3; //EP0_STATUS_PHASE
#endif
	return 0;
}


/* inlined */
static int dwc3_ep0_handle_status(struct dwc3 *dwc,
		struct usb_ctrlrequest *ctrl)
{
	dwc->Data_440 = 2;
	bData_800058BA = 0;

	return dwc3_ep0_start_trans(dwc, 1, Data_800058B0, 2, 0x50);
}


static int dwc3_ep0_std_request(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
	int ret;

	switch (ctrl->bRequest)
	{
	case USB_REQ_SET_CONFIGURATION:
		//AC50
		ret = dwc3_ep0_set_config(dwc, ctrl);
		break;

	case USB_REQ_GET_DESCRIPTOR:
		//ACB8
		{
			//		prints("USB_REQ_GET_DESCRIPTOR: TODO");

			Data_800058B0[0] = 1;

			//(ctrl->wValue >> 8)

			//ad28
			dwc3_ep0_start_trans(dwc, 1, 42, 42, 0x50);

			dwc->Data_440/*ep0state*/ = 2; //EP0_DATA_PHASE
		}
		break;

	case USB_REQ_SET_ADDRESS:
		//AD38
		ret = dwc3_ep0_set_address(dwc, ctrl);
		break;

	case USB_REQ_GET_STATUS:
		//AD68
		ret = dwc3_ep0_handle_status(dwc, ctrl);
		break;
#if 0
	case USB_REQ_GET_STATUS:
//		dev_vdbg(dwc->dev, "USB_REQ_GET_STATUS");
		//AD68
		ret = dwc3_ep0_handle_status(dwc, ctrl);
		break;
	case USB_REQ_CLEAR_FEATURE:
		dev_vdbg(dwc->dev, "USB_REQ_CLEAR_FEATURE");
		ret = dwc3_ep0_handle_feature(dwc, ctrl, 0);
		break;
	case USB_REQ_SET_FEATURE:
		dev_vdbg(dwc->dev, "USB_REQ_SET_FEATURE");
		ret = dwc3_ep0_handle_feature(dwc, ctrl, 1);
		break;
	case USB_REQ_SET_ADDRESS:
//		dev_vdbg(dwc->dev, "USB_REQ_SET_ADDRESS");
		//AD38
		ret = dwc3_ep0_set_address(dwc, ctrl);
		break;
	case USB_REQ_SET_CONFIGURATION:
//		dev_vdbg(dwc->dev, "USB_REQ_SET_CONFIGURATION");
		//AC50
		ret = dwc3_ep0_set_config(dwc, ctrl);
		break;
	case USB_REQ_SET_SEL:
		dev_vdbg(dwc->dev, "USB_REQ_SET_SEL");
		ret = dwc3_ep0_set_sel(dwc, ctrl);
		break;
	case USB_REQ_SET_ISOCH_DELAY:
		dev_vdbg(dwc->dev, "USB_REQ_SET_ISOCH_DELAY");
		ret = dwc3_ep0_set_isoch_delay(dwc, ctrl);
		break;
	default:
		dev_vdbg(dwc->dev, "Forwarding to gadget driver");
		ret = dwc3_ep0_delegate_req(dwc, ctrl);
		break;
#endif
	}

	return ret;
}


static void dwc3_ep0_inspect_setup(struct dwc3 *dwc,
		const struct dwc3_event_depevt *event)
{
	struct usb_ctrlrequest *ctrl = dwc->/*ctrl_req*/Data_0;
	int ret;
	unsigned int len;

	len = ctrl->wLength;
	if (!len)
	{
		dwc->three_stage_setup = 0; //false;
		dwc->ep0_expect_in = 0; //false;
//		dwc->ep0_next_event = DWC3_EP0_NRDY_STATUS;
	}
	else
	{
		dwc->three_stage_setup = 1; //true;
		dwc->ep0_expect_in = !!(ctrl->bRequestType & USB_DIR_IN);
//		dwc->ep0_next_event = DWC3_EP0_NRDY_DATA;
	}

	if ((ctrl->bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD)
		ret = dwc3_ep0_std_request(dwc, ctrl);

#if 0
	struct usb_ctrlrequest *ctrl = dwc->ctrl_req;
	int ret = -EINVAL;
	u32 len;

	if (!dwc->gadget_driver)
		goto out;

	len = le16_to_cpu(ctrl->wLength);
	if (!len) {
		dwc->three_stage_setup = false;
		dwc->ep0_expect_in = false;
		dwc->ep0_next_event = DWC3_EP0_NRDY_STATUS;
	} else {
		dwc->three_stage_setup = true;
		dwc->ep0_expect_in = !!(ctrl->bRequestType & USB_DIR_IN);
		dwc->ep0_next_event = DWC3_EP0_NRDY_DATA;
	}

	if ((ctrl->bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD)
		ret = dwc3_ep0_std_request(dwc, ctrl);
	else
		ret = dwc3_ep0_delegate_req(dwc, ctrl);

	if (ret == USB_GADGET_DELAYED_STATUS)
		dwc->delayed_status = true;

out:
	if (ret < 0)
		dwc3_ep0_stall_and_restart(dwc);
#endif
}


void dwc3_ep0_out_start(struct dwc3 *dwc)
{
	int				ret;

	ret = dwc3_ep0_start_trans(dwc, 0, dwc->/*ctrl_req_addr*/Data_0, 8,
				   DWC3_TRBCTL_CONTROL_SETUP); //, 0);
//	WARN_ON(ret < 0);
}


static void dwc3_ep0_complete_status(struct dwc3 *dwc,
		const struct dwc3_event_depevt *event)
{
#if 0
	struct dwc3_request	*r;
	struct dwc3_ep		*dep;
	struct dwc3_trb		*trb;
	u32			status;

	dep = dwc->eps[0];
	trb = dwc->ep0_trb;

	if (!list_empty(&dep->request_list)) {
		r = next_request(&dep->request_list);

		dwc3_gadget_giveback(dep, r, 0);
	}

	if (dwc->test_mode) {
		int ret;

		ret = dwc3_gadget_set_test_mode(dwc, dwc->test_mode_nr);
		if (ret < 0) {
			dev_dbg(dwc->dev, "Invalid Test #%d",
					dwc->test_mode_nr);
			dwc3_ep0_stall_and_restart(dwc);
			return;
		}
	}

	status = DWC3_TRB_SIZE_TRBSTS(trb->size);
	if (status == DWC3_TRBSTS_SETUP_PENDING)
		dev_dbg(dwc->dev, "Setup Pending received");
#endif

	dwc->/*ep0state*/Data_440 = EP0_SETUP_PHASE;
	dwc3_ep0_out_start(dwc);

	struct dwc3* x19 = &Data_80005950;
	int w21 = x19->Data_492;

	if (w21 == 2)
	{
		//0xad94
		x19->Data_496++;
	}
	else if (w21 == 1)
	{
		//abb4
		struct Struct_80005748_* x22 = &Data_80005748_;

		func_a7f8(dwc, 4, x22->Data_80005750, 512);

		x19->Data_488 = 1;
		x19->Data_492 = 2;

		((char*)x22->Data_80005750)[15] = 15;
	}
}


static inline void dwc3_ep0_xfer_complete(struct dwc3 *dwc,
			const struct dwc3_event_depevt *event)
{
	struct dwc3_ep		*dep = dwc->eps[event->endpoint_number];

	dep->flags &= ~DWC3_EP_BUSY;
	dep->resource_index = 0;
	dwc->setup_packet_pending = 0; //false;

	switch (dwc->/*ep0state*/Data_440)
	{
	case EP0_SETUP_PHASE:
		//dev_vdbg(dwc->dev, "Setup Phase");
		//abec
		dwc3_ep0_inspect_setup(dwc, event);
		break;
#if 0
	case EP0_DATA_PHASE:
		dev_vdbg(dwc->dev, "Data Phase");
		dwc3_ep0_complete_data(dwc, event);
		break;
#endif
	case EP0_STATUS_PHASE:
		//dev_vdbg(dwc->dev, "Status Phase");
		//ab70
		prints("ST\n");
		dwc3_ep0_complete_status(dwc, event);
		break;
#if 0
	default:
		WARN(true, "UNKNOWN ep0state %d\n", dwc->ep0state);
#endif
	}
}


static void __dwc3_ep0_do_control_status(struct dwc3 *dwc, struct dwc3_ep *dep)
{
#if 0
	if (dwc->resize_fifos)
	{
		dev_dbg(dwc->dev, "Resizing FIFOs");
		dwc3_gadget_resize_tx_fifos(dwc);
		dwc->resize_fifos = 0;
	}
#endif

	dwc3_ep0_start_control_status(dep);
}


static int dwc3_ep0_do_control_status(struct dwc3 *dwc,
		const struct dwc3_event_depevt *event)
{
	struct dwc3_ep		*dep = dwc->eps[event->endpoint_number];

	__dwc3_ep0_do_control_status(dwc, dep);
}


/* inlined */
static inline void dwc3_ep0_xfernotready(struct dwc3 *dwc,
		const struct dwc3_event_depevt *event)
{
	dwc->setup_packet_pending = 1; //true;

	struct dwc3_ep		*dep = dwc->eps[event->endpoint_number];

	switch (event->status)
	{
#if 0
	case DEPEVT_STATUS_CONTROL_DATA:
		dev_vdbg(dwc->dev, "Control Data");

		/*
		 * We already have a DATA transfer in the controller's cache,
		 * if we receive a XferNotReady(DATA) we will ignore it, unless
		 * it's for the wrong direction.
		 *
		 * In that case, we must issue END_TRANSFER command to the Data
		 * Phase we already have started and issue SetStall on the
		 * control endpoint.
		 */
		if (dwc->ep0_expect_in != event->endpoint_number) {
			struct dwc3_ep	*dep = dwc->eps[dwc->ep0_expect_in];

			dev_vdbg(dwc->dev, "Wrong direction for Data phase");
			dwc3_ep0_end_control_data(dwc, dep);
			dwc3_ep0_stall_and_restart(dwc);
			return;
		}

		break;
#endif
	case DEPEVT_STATUS_CONTROL_STATUS:
#if 0
		if (dwc->ep0_next_event != DWC3_EP0_NRDY_STATUS)
			return;

		dev_vdbg(dwc->dev, "Control Status");
#endif

		dwc->/*ep0state*/Data_440 = EP0_STATUS_PHASE;

#if 0
		if (dwc->delayed_status) {
			WARN_ON_ONCE(event->endpoint_number != 1);
			dev_vdbg(dwc->dev, "Delayed Status");
			return;
		}
#endif

#if 0
		dwc3_ep0_do_control_status(dwc, event);
#else
		unsigned int			type;

		type = dwc->three_stage_setup ? DWC3_TRBCTL_CONTROL_STATUS3
			: DWC3_TRBCTL_CONTROL_STATUS2;

		dwc3_ep0_start_trans(dwc, dep->number,
				dwc->/*ctrl_req_addr*/Data_0, 0, type); //, 0);
#endif

		prints("[GO]\n");
		sync();
	}
}


/* aa94 - todo */
void dwc3_ep0_interrupt(struct dwc3 *dwc,
		const struct dwc3_event_depevt *event)
{
#if 0
	char			epnum = event->endpoint_number;

	dev_dbg(dwc->dev, "%s while ep%d%s in state '%s'",
			dwc3_ep_event_string(event->endpoint_event),
			epnum >> 1, (epnum & 1) ? "in" : "out",
			dwc3_ep0_state_string(dwc->ep0state));
#endif

	switch (event->endpoint_event)
	{
	case DWC3_DEPEVT_XFERCOMPLETE:
		dwc3_ep0_xfer_complete(dwc, event);
		break;

	case DWC3_DEPEVT_XFERNOTREADY:
		dwc3_ep0_xfernotready(dwc, event);
		break;

#if 0
	case DWC3_DEPEVT_XFERINPROGRESS:
	case DWC3_DEPEVT_RXTXFIFOEVT:
	case DWC3_DEPEVT_STREAMEVT:
	case DWC3_DEPEVT_EPCMDCMPLT:
		break;
#endif
	}
}


/* af2c - todo */
int func_af2c(struct dwc3* x19)
{
	int ret;
	unsigned int reg;

	x19->Data_0 = func_12abc(8);
	memset(x19->Data_0, 0, 8);

	x19->Data_8 = func_12abc(16);
	memset(x19->Data_8, 0, 16);

	x19->Data_16 = func_12abc(16);
	memset(x19->Data_16, 0, 16);

	x19->num_out_eps = 3;
	x19->num_in_eps = 3;

	ret = dwc3_gadget_init_hw_endpoints(x19, x19->num_out_eps, 0);
	if (ret < 0)
	{
		return ret;
	}

	ret = dwc3_gadget_init_hw_endpoints(x19, x19->num_in_eps, 1);
	if (ret < 0)
	{
		return ret;
	}

	reg = dwc3_readl(DWC3_DCFG);
	dwc3_writel(DWC3_DCFG, reg);

	Data_80005020.wMaxPacketSize = 64;
	Data_80005020.bLength = 7;
	Data_80005020.bDescriptorType = USB_DT_ENDPOINT;
	Data_80005020.bmAttributes = 0;

	__dwc3_gadget_ep_enable(x19->eps[0], &Data_80005020);
	__dwc3_gadget_ep_enable(x19->eps[1], &Data_80005020);

	x19->Data_440 = 1; //ep0state = EP0_SETUP_PHASE ?

	dwc3_ep0_start_trans(x19, 0, x19->Data_0, 8,
			DWC3_TRBCTL_CONTROL_SETUP);

	/* Enable all but Start and End of Frame IRQs */
	reg = (DWC3_DEVTEN_VNDRDEVTSTRCVEDEN |
			DWC3_DEVTEN_EVNTOVERFLOWEN |
			DWC3_DEVTEN_CMDCMPLTEN |
			DWC3_DEVTEN_ERRTICERREN |
			DWC3_DEVTEN_WKUPEVTEN |
			DWC3_DEVTEN_ULSTCNGEN |
			DWC3_DEVTEN_CONNECTDONEEN |
			DWC3_DEVTEN_USBRSTEN |
			DWC3_DEVTEN_DISCONNEVTEN);

	dwc3_writel(DWC3_DEVTEN, reg); //0x1e1f);

	return 0;
}


/* b04c - todo */
void func_b04c(void)
{
	unsigned int reg;
	struct dwc3_event_buffer* evt;

	prints("u3-1\n");

	Data_80005950.num_event_buffers = 1;

	Data_80005950.ev_buffs = func_12abc(8); //malloc
	memset(Data_80005950.ev_buffs, 0, 8);

	evt = func_12abc(sizeof(*evt)); //malloc
	memset(evt, 0, sizeof(*evt));

	evt->length = DWC3_EVENT_BUFFERS_SIZE;
	evt->dwc = &Data_80005950;
	evt->buf = func_12abc(DWC3_EVENT_BUFFERS_SIZE);
	memset(evt->buf, 0, DWC3_EVENT_BUFFERS_SIZE);

	Data_80005950.ev_buffs[0] = evt;

	dwc3_event_buffers_setup();

	func_af2c(&Data_80005950);

	reg = dwc3_readl(DWC3_DCTL);
	reg |= (1 << 31);
	dwc3_writel(DWC3_DCTL, reg);
}


/* b748 - todo */
void func_b748(int a)
{
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
	prints("func_b748");
}


/* c108 - todo */
void func_c108(struct dwc3 *dwc)
{
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
	prints("func_c108");
}


/* c200 - todo */
void func_c200(struct dwc3 *dwc)
{
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
	prints("func_c200");
}


/* inlined */
static int dwc3_check_event_buf(struct dwc3 *dwc, unsigned int buf)
{
	struct dwc3_event_buffer *evt;
	unsigned int count;
	unsigned int reg;

	evt = dwc->ev_buffs[buf];

	count = dwc3_readl(DWC3_GEVNTCOUNT(buf));
	count &= DWC3_GEVNTCOUNT_MASK;
	if (!count)
	{
		return 0; //IRQ_NONE;
	}

	evt->count = count;
	evt->flags |= DWC3_EVENT_PENDING;

	/* Mask interrupt */
	reg = dwc3_readl(DWC3_GEVNTSIZ(buf));
	reg |= DWC3_GEVNTSIZ_INTMASK;
	dwc3_writel(DWC3_GEVNTSIZ(buf), reg);

	return 2; //IRQ_WAKE_THREAD;
}


/* inlined */
static void dwc3_endpoint_interrupt(struct dwc3 *dwc,
		const struct dwc3_event_depevt *event)
{
	struct dwc3_ep		*dep;
	char			epnum = event->endpoint_number;

	dep = dwc->eps[epnum];

	if (!(dep->flags & DWC3_EP_ENABLED))
		return;

	if (epnum == 0 || epnum == 1)
	{
		dwc3_ep0_interrupt(dwc, event);
		return;
	}

	switch (event->endpoint_event)
	{
	case DWC3_DEPEVT_XFERCOMPLETE:
#if 0
		dep->resource_index = 0;

		if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
			dev_dbg(dwc->dev, "%s is an Isochronous endpoint\n",
					dep->name);
			return;
		}

		dwc3_endpoint_transfer_complete(dwc, dep, event);
#else
		if (epnum == 4)
		{
			//0xc704
			func_c200(dwc);
		}
		else if (epnum == 3)
		{
			//c6bc
			func_c108(dwc);
		}
#endif
		break;
#if 0
	case DWC3_DEPEVT_XFERINPROGRESS:
		dwc3_endpoint_transfer_complete(dwc, dep, event);
		break;
	case DWC3_DEPEVT_XFERNOTREADY:
		if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
			dwc3_gadget_start_isoc(dwc, dep, event);
		} else {
			int ret;

			dev_vdbg(dwc->dev, "%s: reason %s\n",
					dep->name, event->status &
					DEPEVT_STATUS_TRANSFER_ACTIVE
					? "Transfer Active"
					: "Transfer Not Active");

			ret = __dwc3_gadget_kick_transfer(dep, 0, 1);
			if (!ret || ret == -EBUSY)
				return;

			dev_dbg(dwc->dev, "%s: failed to kick transfers\n",
					dep->name);
		}

		break;
	case DWC3_DEPEVT_STREAMEVT:
		if (!usb_endpoint_xfer_bulk(dep->endpoint.desc)) {
			dev_err(dwc->dev, "Stream event for non-Bulk %s\n",
					dep->name);
			return;
		}

		switch (event->status) {
		case DEPEVT_STREAMEVT_FOUND:
			dev_vdbg(dwc->dev, "Stream %d found and started\n",
					event->parameters);

			break;
		case DEPEVT_STREAMEVT_NOTFOUND:
			/* FALLTHROUGH */
		default:
			dev_dbg(dwc->dev, "Couldn't find suitable stream\n");
		}
		break;
	case DWC3_DEPEVT_RXTXFIFOEVT:
		dev_dbg(dwc->dev, "%s FIFO Overrun\n", dep->name);
		break;
	case DWC3_DEPEVT_EPCMDCMPLT:
		dev_vdbg(dwc->dev, "Endpoint Command Complete\n");
		break;
#endif
	}
}


/* inlined */
static inline void dwc3_process_event_entry(struct dwc3 *dwc,
		const union dwc3_event *event)
{
	/* Endpoint IRQ, handle it and return early */
	if (event->type.is_devspec == 0)
	{
		/* depevt */
		return dwc3_endpoint_interrupt(dwc, &event->depevt);
	}

#if 0
	switch (event->type.type)
	{
	case DWC3_EVENT_TYPE_DEV:
		dwc3_gadget_interrupt(/*dwc,*/ &event->devt);
		break;
	/* REVISIT what to do with Carkit and I2C events ? */
	default:
		break; //dev_err(dwc->dev, "UNKNOWN IRQ type %d\n", event->raw);
	}
#endif
}


/* inlined */
static int dwc3_process_event_buf(struct dwc3 *dwc, unsigned int buf)
{
	struct dwc3_event_buffer *evt;
	/*irqreturn_t*/int ret = 0; //IRQ_NONE;
	int left;
	unsigned int reg;

	evt = dwc->ev_buffs[buf];
	left = evt->count;

	if (!(evt->flags & DWC3_EVENT_PENDING))
		return 0; //IRQ_NONE;

	while (left > 0)
	{
		union dwc3_event event;

		event.raw = *(unsigned int *) (evt->buf + evt->lpos);

		flush_cache(&event, &event + sizeof(event));

		dwc3_process_event_entry(dwc, &event);

		/*
		 * FIXME we wrap around correctly to the next entry as
		 * almost all entries are 4 bytes in size. There is one
		 * entry which has 12 bytes which is a regular entry
		 * followed by 8 bytes data. ATM I don't know how
		 * things are organized if we get next to the a
		 * boundary so I worry about that once we try to handle
		 * that.
		 */
		evt->lpos = (evt->lpos + 4) % DWC3_EVENT_BUFFERS_SIZE;
		left -= 4;

		dwc3_writel(DWC3_GEVNTCOUNT(buf), 4);
	}

	evt->count = 0;
	evt->flags &= ~DWC3_EVENT_PENDING;
	ret = 2; //IRQ_HANDLED;

	/* Unmask interrupt */
	reg = dwc3_readl(DWC3_GEVNTSIZ(buf));
	reg &= ~DWC3_GEVNTSIZ_INTMASK;
	dwc3_writel(DWC3_GEVNTSIZ(buf), reg);

	return ret;
}


/* c568 - todo */
void func_c568(void)
{
	int i, status;
	while (1)
	{
		for (i = 0; i < Data_80005950.num_event_buffers; i++)
		{
			struct dwc3 *dwc = get_dwc();
			status = dwc3_check_event_buf(dwc, i);
			if (status == 2)
			{
				dwc3_process_event_buf(dwc, i);
			}
		}
	}
}


/* c79c - complete */
void func_c79c(int a)
{
}


/* c7b8 - todo */
int swap_endian_volatile(volatile unsigned int data)
{
	data = ((data << 8) & 0xff00ff00) | ((data >> 8) & 0x00ff00ff);
	return (data << 16) | (data >> 16);
}


/* d724 - complete (-O2) */
void copy_memory(void *dst, void *src, unsigned int size)
{
	volatile unsigned int i;

	// word copy if all arguments are word-aligned
	if ( (((unsigned int)dst & 0x3) == 0) && (((unsigned int)src & 0x3) == 0) && ((size & 0x3) == 0) )
	{
		for (i = 0; i < size; i += 4)
			REG32(((unsigned int)dst) + i) = REG32(((unsigned int)src) + i);
	}
	else
	{  // byte copy
		for (i = 0; i < size; i++)
			REG8(((unsigned int)dst) + i) = REG8(((unsigned int)src) + i);
	}
}


/* d9b0 - complete */
int swap_endian(unsigned int input)
{
	unsigned int output;

	output = (input & 0xff000000)>>24|
					 (input & 0x00ff0000)>>8|
					 (input & 0x0000ff00)<<8|
					 (input & 0x000000ff)<<24;
	return output;
}


/* d910 - complete */
int reverse_rsa_signature(unsigned int addr)
{
    unsigned int backup_val[4],i;

    for(i=0;i<4;i++)
            backup_val[i] = swap_endian(REG32(addr+(i*4)));
    REG32(addr) = swap_endian(REG32(addr+28));
    REG32(addr+4) = swap_endian(REG32(addr+24));
    REG32(addr+8) = swap_endian(REG32(addr+20));
    REG32(addr+12) = swap_endian(REG32(addr+16));
    REG32(addr+16) = backup_val[3];
    REG32(addr+20) = backup_val[2];
    REG32(addr+24) = backup_val[1];
    REG32(addr+28) = backup_val[0];

    return 0;
}


/* d55c - todo */
void func_d55c(void)
{

}


/* d5e0 - todo */
void func_d5e0(void)
{

}


/* ec7c - todo */
void func_ec7c(void)
{

}


/* e4e8 - complete */
int func_e4e8(int a)
{
	if (*((volatile unsigned int*)PWDN_CTRL2) == a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/* 11250 - todo */
void func_11250(void)
{

}


/* 11394 - todo */
int func_11394(void)
{

}


/* 125a0 - todo */
void func_125a0(void)
{

}


/* 12784 - todo */
void func_12784(void)
{

}


