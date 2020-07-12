
#include "register.h"
#include "usb.h"



/* 8db0 - complete */
void func_8db0(unsigned int a)
{
	while ((REG32(RTD1295_USB_DWC3_XHCI_BASE_DRD + REG_GUSB2PHYACC0) & 0xc3500) == 0xc3500);

	REG32(RTD1295_USB_DWC3_XHCI_BASE_DRD + REG_GUSB2PHYACC0) = a;
}


/* 8ddc - complete */
int dwc3_readl(unsigned int offset)
{
	return REG32(RTD1295_USB_DWC3_XHCI_BASE_DRD + REG_USB3BASE + (offset - DWC3_GLOBALS_REGS_START)); //0x9801c000 + offset);
}


/* 8df0 - complete */
void dwc3_writel(unsigned int offset, unsigned int value)
{
	REG32(RTD1295_USB_DWC3_XHCI_BASE_DRD + REG_USB3BASE + (offset - DWC3_GLOBALS_REGS_START)) = value;
}


/* 8e04 - complete */
void dwc3_set_mode(unsigned int mode)
{
	unsigned int reg;

	reg = dwc3_readl(DWC3_GCTL);
	reg &= ~(DWC3_GCTL_PRTCAPDIR(DWC3_GCTL_PRTCAP_OTG));
	reg |= DWC3_GCTL_PRTCAPDIR(mode);
	dwc3_writel(DWC3_GCTL, reg);
}



void dwc3_gadget_disconnect_interrupt()
{

}


void dwc3_gadget_reset_interrupt()
{

}


void dwc3_gadget_conndone_interrupt()
{

}


void dwc3_gadget_wakeup_interrupt()
{

}




