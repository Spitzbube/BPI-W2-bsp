

typedef unsigned char		__u8;
typedef unsigned short		__le16;



#define USB_DT_ENDPOINT			0x05



/* USB_DT_ENDPOINT: Endpoint descriptor */
struct usb_endpoint_descriptor
{
	__u8  bLength;
	__u8  bDescriptorType;

	__u8  bEndpointAddress;
	__u8  bmAttributes; //3
	__le16 wMaxPacketSize;
	__u8  bInterval;

	/* NOTE:  these two are _only_ in audio endpoints. */
	/* use USB_DT_ENDPOINT*_SIZE in bLength, not sizeof. */
	__u8  bRefresh;
	__u8  bSynchAddress;
} __attribute__ ((packed));



#define USB_ENDPOINT_XFERTYPE_MASK	0x03	/* in bmAttributes */



static inline int usb_endpoint_type(const struct usb_endpoint_descriptor *epd)
{
	return epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
}



