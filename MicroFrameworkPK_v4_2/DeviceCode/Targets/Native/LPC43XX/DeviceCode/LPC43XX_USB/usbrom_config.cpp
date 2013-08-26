////////////////////////////////////////////////////////////////////////////////
// usbrom_config.cpp - USB ROM configuration for LPC43XX
//
// Simple USB custom class configuration
// Included by LPC43XX_USB.cpp
// Ported to NetMF by Micromint USA <support@micromint.com>

// String descriptor
#define     MANUFACTURER_NAME_SIZE  9   /* "Micromint" */
#define     PRODUCT_NAME_SIZE      10   /* "Bambino200" */
#define     SERIAL_NUMBER_SIZE     12   /* "0021a3000001" */
#define     DISPLAY_NAME_SIZE      10   /* "Bambino200" */
#define     FRIENDLY_NAME_SIZE      9   /* "Gadgeteer" */
// String indexes
#define     MANUFACTURER_NAME_INDEX 1
#define     PRODUCT_NAME_INDEX      2
#define     SERIAL_NUMBER_INDEX     3
// Device descriptor params
#define     VENDOR_ID               0x16D0
#define     PRODUCT_ID              0x085A
#define     BULK_IN_EP              1
#define     BULK_OUT_EP             2

// Configuration descriptor params
#define     USB_MAX_CURRENT         (200/USB_CURRENT_UNIT)
#define     USB_ATTRIBUTES          (USB_ATTRIBUTE_BASE | USB_ATTRIBUTE_SELF_POWER)

// Extended descriptor params
#define OS_DESCRIPTOR_EX_VERSION            0x0100

/* USB Standard Device Descriptor */
ALIGNED(4) const UINT8 USB_DeviceDescriptor[] =
{
  USB_DEVICE_DESCRIPTOR_LENGTH,      /* bLength */
  USB_DEVICE_DESCRIPTOR_TYPE,        /* bDescriptorType */
  WBVAL(0x0110), /* 1.10 */          /* bcdUSB */
  0x00,                              /* bDeviceClass */
  0x00,                              /* bDeviceSubClass */
  0x00,                              /* bDeviceProtocol */
  MAX_EP0_SIZE,                      /* bMaxPacketSize0 */
  WBVAL(VENDOR_ID),                  /* idVendor */
  WBVAL(PRODUCT_ID),                 /* idProduct */
  WBVAL(DEVICE_RELEASE_VERSION),     /* bcdDevice */
  MANUFACTURER_NAME_INDEX,           /* iManufacturer */
  PRODUCT_NAME_INDEX,                /* iProduct */
  SERIAL_NUMBER_INDEX,               /* iSerialNumber */
  0x01                               /* bNumConfigurations */
};

/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
ALIGNED(4) const UINT8 USB_ConfigDescriptor[] = {
/* Configuration 1 */
  USB_CONFIGURATION_DESCRIPTOR_LENGTH, /* bLength */
  USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType */
  WBVAL(                             /* wTotalLength */
    USB_CONFIGURATION_DESCRIPTOR_LENGTH
            + sizeof(USB_INTERFACE_DESCRIPTOR)
            + sizeof(USB_ENDPOINT_DESCRIPTOR)
            + sizeof(USB_ENDPOINT_DESCRIPTOR)
      ),
  0x01,                              /* bNumInterfaces */
  0x01,                              /* bConfigurationValue: 0x01 is used to select this configuration */
  0x00,                              /* iConfiguration: no string to describe this configuration */
  USB_ATTRIBUTES,                    /* bmAttributes */
  USB_MAX_CURRENT,                   /* bMaxPower, device power consumption is 100 mA */

/* Interface 0 descriptor */
  sizeof(USB_INTERFACE_DESCRIPTOR),  /* bLength */
  USB_INTERFACE_DESCRIPTOR_TYPE,     /* bDescriptorType */
  0,                                 /* bInterfaceNumber: Number of Interface */
  0x00,                              /* bAlternateSetting: Alternate setting */
  0x02,                              /* bNumEndpoints: Two endpoints used */
  USB_DEVICE_CLASS_VENDOR_SPECIFIC,  /* bInterfaceClass: Vendor */
  0x01,                              /* bInterfaceSubClass: Abstract Control Model */
  0x01,                              /* bInterfaceProtocol: no protocol used */
  0x00,                              /* iInterface: */

/* Endpoint 1 Descriptor - Bulk IN */
  sizeof(USB_ENDPOINT_DESCRIPTOR),   /* bLength: Endpoint Descriptor size */
  USB_ENDPOINT_DESCRIPTOR_TYPE,      /* bDescriptorType */
  USB_ENDPOINT_DIRECTION_IN + BULK_IN_EP,
  USB_ENDPOINT_ATTRIBUTE_BULK,
  WBVAL(MAX_EP_SIZE),                /* Endpoint 1 packet size */
  0,                                 /* Endpoint 1 interval    */

/* Endpoint 2 Descriptor - Bulk OUT */
  sizeof(USB_ENDPOINT_DESCRIPTOR),   /* bLength: Endpoint Descriptor size */
  USB_ENDPOINT_DESCRIPTOR_TYPE,      /* bDescriptorType */
  USB_ENDPOINT_DIRECTION_OUT + BULK_OUT_EP,
  USB_ENDPOINT_ATTRIBUTE_BULK,
  WBVAL(MAX_EP_SIZE),                /* Endpoint 2 packet size */
  0,                                 /* Endpoint 2 interval    */

#ifdef USB_DEVICE_ROM_DRIVER
  /* Terminator */
  0                                  /* bLength: Indicates to ROM stack the end of descriptor array */
#endif
};

/* USB FS Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
ALIGNED(4) const UINT8 USB_FSConfigDescriptor[] = {
/* Configuration 1 */
  USB_CONFIGURATION_DESCRIPTOR_LENGTH, /* bLength */
  USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType */
  WBVAL(                             /* wTotalLength */
    USB_CONFIGURATION_DESCRIPTOR_LENGTH
            + sizeof(USB_INTERFACE_DESCRIPTOR)
            + sizeof(USB_ENDPOINT_DESCRIPTOR)
            + sizeof(USB_ENDPOINT_DESCRIPTOR)
      ),
  0x01,                              /* bNumInterfaces */
  0x01,                              /* bConfigurationValue: 0x01 is used to select this configuration */
  0x00,                              /* iConfiguration: no string to describe this configuration */
  USB_ATTRIBUTES,                    /* bmAttributes */
  USB_MAX_CURRENT,                   /* bMaxPower, device power consumption is 100 mA */

/* Interface 0 descriptor */
  sizeof(USB_INTERFACE_DESCRIPTOR),  /* bLength */
  USB_INTERFACE_DESCRIPTOR_TYPE,     /* bDescriptorType */
  0,                                 /* bInterfaceNumber: Number of Interface */
  0x00,                              /* bAlternateSetting: Alternate setting */
  0x02,                              /* bNumEndpoints: Two endpoints used */
  USB_DEVICE_CLASS_VENDOR_SPECIFIC,  /* bInterfaceClass: Vendor */
  0x01,                              /* bInterfaceSubClass: Abstract Control Model */
  0x01,                              /* bInterfaceProtocol: no protocol used */
  0x00,                              /* iInterface: */

/* Endpoint 1 Descriptor - Bulk IN */
  sizeof(USB_ENDPOINT_DESCRIPTOR),   /* bLength: Endpoint Descriptor size */
  USB_ENDPOINT_DESCRIPTOR_TYPE,      /* bDescriptorType */
  USB_ENDPOINT_DIRECTION_IN + BULK_IN_EP,
  USB_ENDPOINT_ATTRIBUTE_BULK,
  WBVAL(MAX_EP_SIZE),                /* Endpoint 1 packet size */
  0,                                 /* Endpoint 1 interval    */

/* Endpoint 2 Descriptor - Bulk OUT */
  sizeof(USB_ENDPOINT_DESCRIPTOR),   /* bLength: Endpoint Descriptor size */
  USB_ENDPOINT_DESCRIPTOR_TYPE,      /* bDescriptorType */
  USB_ENDPOINT_DIRECTION_OUT + BULK_OUT_EP,
  USB_ENDPOINT_ATTRIBUTE_BULK,
  WBVAL(MAX_EP_SIZE),                /* Endpoint 2 packet size */
  0,                                 /* Endpoint 2 interval    */

#ifdef USB_DEVICE_ROM_DRIVER
  /* Terminator */
  0                                  /* bLength: Indicates to ROM stack the end of descriptor array */
#endif
};

/* USB String Descriptor (optional) */
ALIGNED(4) const UINT8 USB_StringDescriptor[] = {
  /* Index 0x00: LANGID Codes */
  0x04,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  WBVAL(0x0409), /* US English */    /* wLANGID */

  /* Index 0x01: Manufacturer */
  (MANUFACTURER_NAME_SIZE * 2 + 2),  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'M',0,
  'i',0,
  'c',0,
  'r',0,
  'o',0,
  'm',0,
  'i',0,
  'n',0,
  't',0,

  /* Index 0x02: Product */
  (PRODUCT_NAME_SIZE * 2 + 2),       /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'B',0,
  'a',0,
  'm',0,
  'b',0,
  'i',0,
  'n',0,
  'o',0,
  '2',0,
  '0',0,
  '0',0,

  /* Index 0x03: Serial number */
  (SERIAL_NUMBER_SIZE * 2 + 2),      /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  '0',0,
  '0',0,
  '2',0,
  '1',0,
  'A',0,
  '3',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '1',0,

   /* Index 0x04: Display name */
  (DISPLAY_NAME_SIZE * 2 + 2),       /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'B',0,
  'a',0,
  'm',0,
  'b',0,
  'i',0,
  'n',0,
  'o',0,
  '2',0,
  '0',0,
  '0',0,

  /* Index 0x05: Friendly name */
  (FRIENDLY_NAME_SIZE * 2 + 2),      /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'G',0,
  'a',0,
  'd',0,
  'g',0,
  'e',0,
  't',0,
  'e',0,
  'e',0,
  'r',0,

  /* Index 0x06: OS name */
  (OS_DESCRIPTOR_STRING_SIZE * 2 + 2),  /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'M',0,
  'S',0,
  'F',0,
  'T',0,
  '1',0,
  '0',0,
  '0',0,
  OS_DESCRIPTOR_STRING_VENDOR_CODE, 0,
  0,0,

#ifdef USB_DEVICE_ROM_DRIVER
  /* Terminator */
  0                                  /* bLength: Indicates to ROM stack the end of descriptor array */
#endif
};

/* USB Device Qualifier */
ALIGNED(4) const UINT8 USB_DeviceQualifier[] = {
  USB_DEVICE_QUALI_SIZE,              /* bLength */
  USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE, /* bDescriptorType */
  WBVAL(0x0200), /* 2.00 */          /* bcdUSB */
  0x00,                              /* bDeviceClass */
  0x00,                              /* bDeviceSubClass */
  0x00,                              /* bDeviceProtocol */
  MAX_EP0_SIZE,                      /* bMaxPacketSize0 */
  0x01,                              /* bNumOtherSpeedConfigurations */
  0x00                               /* bReserved */
};
