

typedef unsigned char		__u8;
typedef unsigned short		__le16;



/*
 * USB directions
 *
 * This bit flag is used in endpoint descriptors' bEndpointAddress field.
 * It's also one of three fields in control requests bRequestType.
 */
#define USB_DIR_OUT			0		/* to device */
#define USB_DIR_IN			0x80		/* to host */


/*
 * USB types, the second of three bRequestType fields
 */
#define USB_TYPE_MASK			(0x03 << 5)
#define USB_TYPE_STANDARD		(0x00 << 5)
#define USB_TYPE_CLASS			(0x01 << 5)
#define USB_TYPE_VENDOR			(0x02 << 5)
#define USB_TYPE_RESERVED		(0x03 << 5)


/*
 * Standard requests, for the bRequest field of a SETUP packet.
 *
 * These are qualified by the bRequestType field, so that for example
 * TYPE_CLASS or TYPE_VENDOR specific feature flags could be retrieved
 * by a GET_STATUS request.
 */
#define USB_REQ_GET_STATUS		0x00
#define USB_REQ_CLEAR_FEATURE		0x01
#define USB_REQ_SET_FEATURE		0x03
#define USB_REQ_SET_ADDRESS		0x05
#define USB_REQ_GET_DESCRIPTOR		0x06
#define USB_REQ_SET_DESCRIPTOR		0x07
#define USB_REQ_GET_CONFIGURATION	0x08
#define USB_REQ_SET_CONFIGURATION	0x09
#define USB_REQ_GET_INTERFACE		0x0A
#define USB_REQ_SET_INTERFACE		0x0B
#define USB_REQ_SYNCH_FRAME		0x0C
#define USB_REQ_SET_SEL			0x30
#define USB_REQ_SET_ISOCH_DELAY		0x31



struct usb_ctrlrequest
{
	__u8 bRequestType; //0
	__u8 bRequest; //1
	__le16 wValue; //2
	__le16 wIndex; //4
	__le16 wLength; //6
} __attribute__ ((packed));





/*-------------------------------------------------------------------------*/

/* USB_DT_DEVICE: Device descriptor */
struct usb_device_descriptor {
	__u8  bLength; //0
	__u8  bDescriptorType; //1

	__le16 bcdUSB; //2
	__u8  bDeviceClass; //4
	__u8  bDeviceSubClass; //5
	__u8  bDeviceProtocol; //6
	__u8  bMaxPacketSize0; //7
	__le16 idVendor; //8
	__le16 idProduct; //10
	__le16 bcdDevice; //12
	__u8  iManufacturer; //14
	__u8  iProduct; //15
	__u8  iSerialNumber; //16
	__u8  bNumConfigurations; //17
} __attribute__ ((packed));

#define USB_DT_DEVICE_SIZE		18



#define USB_DT_DEVICE			0x01
#define USB_DT_CONFIG			0x02
#define USB_DT_STRING			0x03
#define USB_DT_INTERFACE		0x04
#define USB_DT_ENDPOINT			0x05
#define USB_DT_DEVICE_QUALIFIER		0x06
#define USB_DT_OTHER_SPEED_CONFIG	0x07
#define USB_DT_OTG				0x09


/*-------------------------------------------------------------------------*/

/* USB_DT_CONFIG: Configuration descriptor information.
 *
 * USB_DT_OTHER_SPEED_CONFIG is the same descriptor, except that the
 * descriptor type is different.  Highspeed-capable devices can look
 * different depending on what speed they're currently running.  Only
 * devices with a USB_DT_DEVICE_QUALIFIER have any OTHER_SPEED_CONFIG
 * descriptors.
 */
struct usb_config_descriptor
{
	__u8  bLength; //0
	__u8  bDescriptorType; //1

	__le16 wTotalLength; //2
	__u8  bNumInterfaces; //4
	__u8  bConfigurationValue; //5
	__u8  iConfiguration; //6
	__u8  bmAttributes; //7
	__u8  bMaxPower; //8
} __attribute__ ((packed));

#define USB_DT_CONFIG_SIZE		9


/*-------------------------------------------------------------------------*/

/* USB_DT_INTERFACE: Interface descriptor */
struct usb_interface_descriptor
{
	__u8  bLength;
	__u8  bDescriptorType;

	__u8  bInterfaceNumber;
	__u8  bAlternateSetting;
	__u8  bNumEndpoints;
	__u8  bInterfaceClass;
	__u8  bInterfaceSubClass;
	__u8  bInterfaceProtocol;
	__u8  iInterface;
} __attribute__ ((packed));

#define USB_DT_INTERFACE_SIZE		9

/*-------------------------------------------------------------------------*/

/* USB_DT_ENDPOINT: Endpoint descriptor */
struct usb_endpoint_descriptor
{
	__u8  bLength; //0
	__u8  bDescriptorType; //1

	__u8  bEndpointAddress;
	__u8  bmAttributes; //3
	__le16 wMaxPacketSize;
	__u8  bInterval;

#if 0
	/* NOTE:  these two are _only_ in audio endpoints. */
	/* use USB_DT_ENDPOINT*_SIZE in bLength, not sizeof. */
	__u8  bRefresh;
	__u8  bSynchAddress;
#endif
} __attribute__ ((packed));

#define USB_DT_ENDPOINT_SIZE		7



#define USB_ENDPOINT_XFERTYPE_MASK	0x03	/* in bmAttributes */



static inline int usb_endpoint_type(const struct usb_endpoint_descriptor *epd)
{
	return epd->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
}


/*-------------------------------------------------------------------------*/

/* USB_DT_STRING: String descriptor */
struct usb_string_descriptor {
	__u8  bLength;
	__u8  bDescriptorType;

	__le16 wData[1];		/* UTF-16LE encoded */
} __attribute__ ((packed));

/* note that "string" zero is special, it holds language codes that
 * the device supports, not Unicode characters.
 */



/*-------------------------------------------------------------------------*/

/* USB_DT_DEVICE_QUALIFIER: Device Qualifier descriptor */
struct usb_qualifier_descriptor
{
	__u8  bLength; //0
	__u8  bDescriptorType; //1

	__le16 bcdUSB; //2
	__u8  bDeviceClass; //4
	__u8  bDeviceSubClass; //5
	__u8  bDeviceProtocol; //6
	__u8  bMaxPacketSize0; //7
	__u8  bNumConfigurations; //8
	__u8  bRESERVED; //9
} __attribute__ ((packed));


/*-------------------------------------------------------------------------*/

/* USB_DT_OTG (from OTG 1.0a supplement) */
struct usb_otg_descriptor
{
	__u8  bLength;
	__u8  bDescriptorType;

	__u8  bmAttributes;	/* support for HNP, SRP, etc */
} __attribute__ ((packed));

/* from usb_otg_descriptor.bmAttributes */
#define USB_OTG_SRP		(1 << 0)
#define USB_OTG_HNP		(1 << 1)	/* swap host/device roles */







