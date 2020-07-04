
#define DWC3_EVENT_SIZE		4
#define DWC3_EVENT_MAX_NUM	64
#define DWC3_EVENT_BUFFERS_SIZE	(DWC3_EVENT_SIZE * DWC3_EVENT_MAX_NUM)

#define RTD1295_USB_DWC3_XHCI_BASE_DRD		0x98020000
#define REG_USB3BASE		0x8100//(0x18028100)

#define REG_GUSB2PHYACC0			0x180 + REG_USB3BASE//(0x18028280)

#define DWC3_GSNPSID_MASK	0xffff0000

#define DWC3_GLOBALS_REGS_START		0xc100
#define DWC3_GTXTHRCFG		0xc108
#define DWC3_GRXTHRCFG		0xc10c
#define DWC3_GCTL			0xc110
#define DWC3_GSNPSID		0xc120
#define DWC3_GUCTL			0xc12c
#define DWC3_DCFG			0xc700
#define DWC3_DCTL			0xc704

#define DWC3_GUSB2PHYCFG(n)		(0xc200 + (n * 0x04))
#define DWC3_GUSB3PIPECTL(n)	(0xc2c0 + (n * 0x04))

#define DWC3_DCTL_CSFTRST	(1 << 30)

#define DWC3_GCTL_PRTCAP(n)	(((n) & (3 << 12)) >> 12)
#define DWC3_GCTL_PRTCAPDIR(n)	((n) << 12)
#define DWC3_GCTL_PRTCAP_HOST	1
#define DWC3_GCTL_PRTCAP_DEVICE	2
#define DWC3_GCTL_PRTCAP_OTG	3

#define DWC3_GCTL_CORESOFTRESET		(1 << 11)
#define DWC3_GCTL_SOFITPSYNC		(1 << 10)
#define DWC3_GCTL_SCALEDOWN(n)		((n) << 4)
#define DWC3_GCTL_SCALEDOWN_MASK	DWC3_GCTL_SCALEDOWN(3)
#define DWC3_GCTL_DISSCRAMBLE		(1 << 3)
#define DWC3_GCTL_U2EXIT_LFPS		(1 << 2)
#define DWC3_GCTL_GBLHIBERNATIONEN	(1 << 1)
#define DWC3_GCTL_DSBLCLKGTNG		(1 << 0)

/* Global USB2 PHY Configuration Register */
#define DWC3_GUSB2PHYCFG_PHYSOFTRST	(1 << 31)

/* Global USB3 PIPE Control Register */
#define DWC3_GUSB3PIPECTL_PHYSOFTRST	(1 << 31)


struct dwc3_event_buffer {
	void			*buf; //0
	unsigned		length; //8
	unsigned int		lpos;
	unsigned int		count;
	unsigned int		flags;

#define DWC3_EVENT_PENDING	(1UL << 0)

	/*dma_addr_t*/void*		dma;

	/*struct dwc3*/void		*dwc;
};






