
#include "uart.h"
#include "timer.h"
#include "usb.h"


extern int Data_80005080; //80005080 +128
int Data_800050B0; //800050B0 +176
int Data_800050B8; //800050B8 +184



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


/* de8 - todo */
void func_de8(int a)
{

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


/* 8fe4 - todo */
void func_8fe4(void)
{
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");
	prints("func_8fe4");

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


void* volatile Data_80005748; //80005748 0x80005000 +1864
void* volatile Data_80005750; //80005750
void* volatile Data_80005758; //80005758
char bData_800058B9; //800058B9 80005748 +369
char bData_800058BA; //800058BA
char bData_80005934; //80005934 80005748 +492

extern unsigned int func_12abc(unsigned int n_bytes);



/* 9f2c - todo */
void func_9f2c(char a)
{
	volatile unsigned int reg;

	if (a)
	{
		//9f40
		Data_80005748 = func_12abc(81); //malloc
		memset(Data_80005748, 0, 81);

		Data_80005750 = func_12abc(88);
		memset(Data_80005750, 0, 88);

		Data_80005758 = func_12abc(52);
		memset(Data_80005758, 0, 52);

		*((int*)Data_80005758) = 0x53425355;

		func_8fe4();
	}
	//0x9fb8
	bData_800058B9 = 0;
	bData_800058BA = 0;
	bData_80005934 = 0;

	REG32(0x981e8800) &= ~0x03;
	REG32(0x981e8800) &= 0xff7fe7fb;

	if ((dwc3_readl(DWC3_GSNPSID) & DWC3_GSNPSID_MASK) != 0x55330000)
	{
		prints("this is not a DesignWare USB3 DRD Core\n");
	}
	else
	{
		dwc3_writel(DWC3_DCTL, DWC3_DCTL_CSFTRST);

		while (dwc3_readl(DWC3_DCTL) & DWC3_DCTL_CSFTRST)
		{
		}

		reg = 0;

		dwc3_core_soft_reset();

		dwc3_writel(DWC3_GCTL, reg);
		dwc3_writel(DWC3_DCFG, dwc3_readl(DWC3_DCFG) & ~0x07);
		dwc3_writel(DWC3_GTXTHRCFG, 0x01010000);
		dwc3_writel(DWC3_GRXTHRCFG, 0x26300000);
		dwc3_writel(DWC3_GUCTL, dwc3_readl(DWC3_GUCTL) | (1<<14)); // enable auto retry
	}

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


/* a3f4 - todo */
void func_a3f4(void)
{
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
	prints("func_a3f4");
}


/* af2c - todo */
void func_af2c(void* a)
{
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
	prints("func_af2c");
}


int Data_80005950; //80005950
struct
{
	void* Data_0;
}* Data_800059D0; //800059D0 80005950 + 128
int Data_80005AEC; //80005AEC 80005950 + 412


/* func_b04c - todo */
void func_b04c(void)
{
	unsigned int reg;
	struct dwc3_event_buffer* evt; //x20

	prints("u3-1\n");

	Data_80005AEC = 1;

	Data_800059D0 = func_12abc(8); //malloc
	memset(Data_800059D0, 0, 8);

	evt = func_12abc(sizeof(*evt)); //malloc
	memset(evt, 0, sizeof(*evt));

	evt->length = DWC3_EVENT_BUFFERS_SIZE;
	evt->dwc = &Data_80005950;
	evt->buf = func_12abc(DWC3_EVENT_BUFFERS_SIZE);
	memset(evt->buf, 0, DWC3_EVENT_BUFFERS_SIZE);

	Data_800059D0->Data_0 = evt;

	func_a3f4();

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


/* func_c568 - todo */
void func_c568(void)
{
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
	prints("func_c568");
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


