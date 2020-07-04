
#define DWC3_ENDPOINTS_NUM	32

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
#define DWC3_DEVTEN			0xc708

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

/* Device Event Enable Register */
#define DWC3_DEVTEN_VNDRDEVTSTRCVEDEN	(1 << 12)
#define DWC3_DEVTEN_EVNTOVERFLOWEN	(1 << 11)
#define DWC3_DEVTEN_CMDCMPLTEN		(1 << 10)
#define DWC3_DEVTEN_ERRTICERREN		(1 << 9)
#define DWC3_DEVTEN_SOFEN		(1 << 7)
#define DWC3_DEVTEN_EOPFEN		(1 << 6)
#define DWC3_DEVTEN_HIBERNATIONREQEVTEN	(1 << 5)
#define DWC3_DEVTEN_WKUPEVTEN		(1 << 4)
#define DWC3_DEVTEN_ULSTCNGEN		(1 << 3)
#define DWC3_DEVTEN_CONNECTDONEEN	(1 << 2)
#define DWC3_DEVTEN_USBRSTEN		(1 << 1)
#define DWC3_DEVTEN_DISCONNEVTEN	(1 << 0)


struct usb_ep
{
	void			*driver_data;
	const char		*name;
#if 0
	const struct usb_ep_ops	*ops;
	struct list_head	ep_list;
	unsigned		maxpacket:16;
	unsigned		maxpacket_limit:16;
	unsigned		max_streams:16;
	unsigned		maxburst:5;
	const struct usb_endpoint_descriptor	*desc;
	const struct usb_ss_ep_comp_descriptor	*comp_desc;
#endif
};

struct dwc3_ep
{
	struct usb_ep endpoint;
	int fill_16[8]; //16
	struct dwc3* dwc; //48
	int fill_56[2]; //56
	char number; //64
	int fill_68; //68
	char name[20]; //72
	unsigned direction:1; //92
	//96
};


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


struct dwc3
{
	void* Data_0; //0
	void* Data_8; //8
	void* Data_16; //16
	int fill_24[26]; //24
	struct dwc3_event_buffer** ev_buffs; //128 800059D0
	struct dwc3_ep* eps[DWC3_ENDPOINTS_NUM]; //136
	int fill_392[5]; //392
	int Data_412; //412 80005AEC
	int fill_416[6]; //416
	int Data_440; //440
	int fill_444[3]; //444
	char fill_456; //456
	char num_out_eps; //457
	char num_in_eps; //458
};






