
#define DWC3_ENDPOINTS_NUM	32

#define DWC3_EVENT_SIZE		4
#define DWC3_EVENT_MAX_NUM	64
#define DWC3_EVENT_BUFFERS_SIZE	(DWC3_EVENT_SIZE * DWC3_EVENT_MAX_NUM)

#define RTD1295_USB_DWC3_XHCI_BASE_DRD		0x98020000
#define REG_USB3BASE		0x8100//(0x18028100)

#define REG_GUSB2PHYACC0			0x180 + REG_USB3BASE//(0x18028280)

#define DWC3_GEVNTCOUNT_MASK	0xfffc
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
#define DWC3_DALEPENA		0xc720
#define DWC3_DEPCMDPAR2(n)	(0xc800 + (n * 0x10))
#define DWC3_DEPCMDPAR1(n)	(0xc804 + (n * 0x10))
#define DWC3_DEPCMDPAR0(n)	(0xc808 + (n * 0x10))
#define DWC3_DEPCMD(n)		(0xc80c + (n * 0x10))

#define DWC3_GUSB2PHYCFG(n)		(0xc200 + (n * 0x04))
#define DWC3_GUSB3PIPECTL(n)	(0xc2c0 + (n * 0x04))

#define DWC3_GEVNTADRLO(n)	(0xc400 + (n * 0x10))
#define DWC3_GEVNTADRHI(n)	(0xc404 + (n * 0x10))
#define DWC3_GEVNTSIZ(n)	(0xc408 + (n * 0x10))
#define DWC3_GEVNTCOUNT(n)	(0xc40c + (n * 0x10))

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

/* Device Endpoint Command Register */
#define DWC3_DEPCMD_PARAM_SHIFT		16
#define DWC3_DEPCMD_PARAM(x)		((x) << DWC3_DEPCMD_PARAM_SHIFT)
#define DWC3_DEPCMD_GET_RSC_IDX(x)	(((x) >> DWC3_DEPCMD_PARAM_SHIFT) & 0x7f)
#define DWC3_DEPCMD_CMDACT			(1 << 10)

#define DWC3_DEPCMD_SETEPCONFIG			(0x01 << 0)
#define DWC3_DEPCMD_SETTRANSFRESOURCE	(0x02 << 0)
#define DWC3_DEPCMD_STARTTRANSFER		(0x06 << 0)
#define DWC3_DEPCMD_DEPSTARTCFG			(0x09 << 0)

/* DEPCFG parameter 1 */
#define DWC3_DEPCFG_XFER_COMPLETE_EN	(1 << 8)
#define DWC3_DEPCFG_XFER_NOT_READY_EN	(1 << 10)
#define DWC3_DEPCFG_EP_NUMBER(n)		((n) << 25)

/* DEPCFG parameter 0 */
#define DWC3_DEPCFG_EP_TYPE(n)			((n) << 1)
#define DWC3_DEPCFG_MAX_PACKET_SIZE(n)	((n) << 3)
#define DWC3_DEPCFG_FIFO_NUMBER(n)		((n) << 17)
#define DWC3_DEPCFG_BURST_SIZE(n)		((n) << 22)

/* The EP number goes 0..31 so ep0 is always out and ep1 is always in */
#define DWC3_DALEPENA_EP(n)		(1 << n)

/* DEPXFERCFG parameter 0 */
#define DWC3_DEPXFERCFG_NUM_XFER_RES(n)	((n) & 0xffff)

#define DWC3_GEVNTSIZ_INTMASK		(1 << 31)

/* TRB Control */
#define DWC3_TRB_CTRL_HWO		(1 << 0)
#define DWC3_TRB_CTRL_LST		(1 << 1)
#define DWC3_TRB_CTRL_CHN		(1 << 2)
#define DWC3_TRB_CTRL_CSP		(1 << 3)
#define DWC3_TRB_CTRL_TRBCTL(n)		(((n) & 0x3f) << 4)
#define DWC3_TRB_CTRL_ISP_IMI		(1 << 10)
#define DWC3_TRB_CTRL_IOC		(1 << 11)
#define DWC3_TRB_CTRL_SID_SOFN(n)	(((n) & 0xffff) << 14)

#define DWC3_TRBCTL_NORMAL			DWC3_TRB_CTRL_TRBCTL(1)
#define DWC3_TRBCTL_CONTROL_SETUP	DWC3_TRB_CTRL_TRBCTL(2)
#define DWC3_TRBCTL_CONTROL_STATUS2	DWC3_TRB_CTRL_TRBCTL(3)
#define DWC3_TRBCTL_CONTROL_STATUS3	DWC3_TRB_CTRL_TRBCTL(4)
#define DWC3_TRBCTL_CONTROL_DATA	DWC3_TRB_CTRL_TRBCTL(5)
#define DWC3_TRBCTL_ISOCHRONOUS_FIRST	DWC3_TRB_CTRL_TRBCTL(6)
#define DWC3_TRBCTL_ISOCHRONOUS		DWC3_TRB_CTRL_TRBCTL(7)
#define DWC3_TRBCTL_LINK_TRB		DWC3_TRB_CTRL_TRBCTL(8)


#define DWC3_EVENT_TYPE_DEV		0


#define DWC3_DEVICE_EVENT_DISCONNECT		0
#define DWC3_DEVICE_EVENT_RESET			1
#define DWC3_DEVICE_EVENT_CONNECT_DONE		2
#define DWC3_DEVICE_EVENT_LINK_STATUS_CHANGE	3
#define DWC3_DEVICE_EVENT_WAKEUP		4
#define DWC3_DEVICE_EVENT_HIBER_REQ		5
#define DWC3_DEVICE_EVENT_EOPF			6
#define DWC3_DEVICE_EVENT_SOF			7
#define DWC3_DEVICE_EVENT_ERRATIC_ERROR		9
#define DWC3_DEVICE_EVENT_CMD_CMPL		10
#define DWC3_DEVICE_EVENT_OVERFLOW		11

/* Device Configuration Register */
#define DWC3_DCFG_DEVADDR(addr)	((addr) << 3)
#define DWC3_DCFG_DEVADDR_MASK	DWC3_DCFG_DEVADDR(0x7f)

struct dwc3_gadget_ep_cmd_params
{
	unsigned int	param2;
	unsigned int	param1;
	unsigned int	param0;
};


struct usb_ep
{
	void			*driver_data;
	const char		*name;
	int fill_16[2]; //16
	const struct usb_endpoint_descriptor	*desc; //24
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
	int fill_32[4]; //32
	struct dwc3* dwc; //48
	unsigned int flags; //56
#define DWC3_EP_ENABLED		(1 << 0)
#define DWC3_EP_STALL		(1 << 1)
#define DWC3_EP_WEDGE		(1 << 2)
#define DWC3_EP_BUSY		(1 << 4)
#define DWC3_EP_PENDING_REQUEST	(1 << 5)
#define DWC3_EP_MISSED_ISOC	(1 << 6)

	/* This last one is specific to EP0 */
#define DWC3_EP0_DIR_IN		(1 << 31)

	int fill_60; //60
	char number; //64
	char type; //65
	char resource_index; //66
	int fill_68; //68
	char name[20]; //72
	unsigned direction:1; //92
	//96
};


enum dwc3_ep0_state {
	EP0_UNCONNECTED		= 0,
	EP0_SETUP_PHASE,
	EP0_DATA_PHASE,
	EP0_STATUS_PHASE, //3
};


struct dwc3_event_buffer {
	void			*buf; //0
	unsigned		length; //8
	unsigned int		lpos; //12
	unsigned int		count; //16
	unsigned int		flags; //20

#define DWC3_EVENT_PENDING	(1UL << 0)

	/*dma_addr_t*/void*		dma;

	/*struct dwc3*/void		*dwc;
};


/**
 * struct dwc3_trb - transfer request block (hw format)
 * @bpl: DW0-3
 * @bph: DW4-7
 * @size: DW8-B
 * @trl: DWC-F
 */
struct dwc3_trb {
	unsigned int		bpl; //0
	unsigned int		bph; //4
	unsigned int		size; //8
	unsigned int		ctrl; //12
	//16
} /*__packed*/;


struct dwc3
{
	void** Data_0; //0
	void* Data_8; //8
	void* Data_16; //16
	int fill_24[26]; //24
	struct dwc3_event_buffer** ev_buffs; //128 800059D0
	struct dwc3_ep* eps[DWC3_ENDPOINTS_NUM]; //136
	int fill_392[5]; //392
	unsigned int num_event_buffers; //412 80005AEC
	int fill_416[4]; //416

#if 0
	char bData_432; //432
#else
	unsigned		three_stage_setup:1; //0x02
	unsigned		setup_packet_pending:1;	//0x20

	unsigned		ep0_expect_in:1;
	unsigned		needs_fifo_resize:1;	//432:0x01 //TODO
	unsigned		pullups_connected:1;	//432:0x02 //TODO
	unsigned		resize_fifos:1;			//432:0x04 //TODO
	unsigned		start_config_issued:1;	//432:0x10 //TODO
#endif
	int fill_436; //436
	int Data_440; //440 ep0state?
	int fill_444[3]; //444
	char fill_456; //456
	char num_out_eps; //457
	char num_in_eps; //458

	int Data_488; //488
	int Data_492; //492
	int Data_496; //496
};


struct dwc3_event_type
{
	unsigned int	is_devspec:1;
	unsigned int	type:7;
	unsigned int	reserved8_31:24;
} __attribute__ ((packed)); //__packed;


#define DWC3_DEPEVT_XFERCOMPLETE	0x01
#define DWC3_DEPEVT_XFERINPROGRESS	0x02
#define DWC3_DEPEVT_XFERNOTREADY	0x03
#define DWC3_DEPEVT_RXTXFIFOEVT		0x04
#define DWC3_DEPEVT_STREAMEVT		0x06
#define DWC3_DEPEVT_EPCMDCMPLT		0x07


struct dwc3_event_depevt
{
	unsigned int	one_bit:1; //0
	unsigned int	endpoint_number:5; //1...5
	unsigned int	endpoint_event:4; //6...9
	unsigned int	reserved11_10:2; //10...11
	unsigned int	status:4; //12..15

/* Within XferNotReady */
#define DEPEVT_STATUS_TRANSFER_ACTIVE	(1 << 3)

/* Within XferComplete */
#define DEPEVT_STATUS_BUSERR	(1 << 0)
#define DEPEVT_STATUS_SHORT	(1 << 1)
#define DEPEVT_STATUS_IOC	(1 << 2)
#define DEPEVT_STATUS_LST	(1 << 3)

/* Stream event only */
#define DEPEVT_STREAMEVT_FOUND		1
#define DEPEVT_STREAMEVT_NOTFOUND	2

/* Control-only Status */
#define DEPEVT_STATUS_CONTROL_DATA	1
#define DEPEVT_STATUS_CONTROL_STATUS	2

	unsigned int	parameters:16;
} __attribute__ ((packed)); //__packed;


struct dwc3_event_devt
{
	unsigned int	one_bit:1;
	unsigned int	device_event:7;
	unsigned int	type:4;
	unsigned int	reserved15_12:4;
	unsigned int	event_info:9;
	unsigned int	reserved31_25:7;
} __attribute__ ((packed)); //__packed;


union dwc3_event
{
	unsigned int				raw;
	struct dwc3_event_type		type;
	struct dwc3_event_depevt	depevt;
	struct dwc3_event_devt		devt;
#if 0
	struct dwc3_event_gevt		gevt;
#endif
};






