#ifndef ATA_H
#define ATA_H

#define ATA_NUM_DEVICES         2
#define ATA_DATA_REGISTER    0x1F0
#define ATA_ERROR_REGISTER   0x1F1
#define ATA_SECTOR_COUNT     0x1F2
#define ATA_LBA_LOW          0x1F3
#define ATA_LBA_MID          0x1F4
#define ATA_LBA_HIGH         0x1F5
#define ATA_DEVICE_REGISTER  0x1F6
#define ATA_COMMAND_REGISTER 0x1F7
//ATA I/O
#define ATA_CONTROLLER_BASE_PORT 0x1F0
#define ATA_CONTROLLER_CTRL_PORT 0x3F6
//ATA commands
#define ATA_CMD_IDENTIFY     0xEC
#define ATA_CMD_READ_SECTOR  0x20
#define ATA_CMD_WRITE_SECTOR 0x30
//ATA device types
#define ATA_DEVICE_TYPE_ATA  0x00
#define ATA_DEVICE_TYPE_ATAPI 0x01
//ATA protocols
#define ATA_PROTOCOL_PIO   0x00
#define ATA_PROTOCOL_DMA   0x01
#define ATA_PROTOCOL_UDMA  0x02
//ATA errors
#define ATA_ERROR_NONE               0
#define ATA_ERROR_DEVICE_NOT_READY   1
#define ATA_ERROR_DATA_CRC           2
#define ATA_ERROR_MEDIA_CHANGED      3
// ATA device selectors
#define ATA_DEVICE_MASTER   0x00
#define ATA_DEVICE_SLAVE    0x10
// ATA status register bits
#define ATA_STATUS_BSY      0x80
#define ATA_STATUS_DRDY     0x40
#define ATA_STATUS_DF       0x20
#define ATA_STATUS_DSC      0x10
#define ATA_STATUS_DRQ      0x08
#define ATA_STATUS_CORR     0x04
#define ATA_STATUS_IDX      0x02
#define ATA_STATUS_ERR      0x01
#define ATA_SECTOR_SIZE 512


#include "../libc/include/types.h"

const char *ata_error_messages[] = {
    "No error",
    "Device not ready",
    "Data CRC error",
    "Media changed"
};


typedef struct {
    u16    cylinders;
    u16    heads;
    u16    sectors;
    u16    vendor_id[8];
    u16    product_id[16];
    u16    revision[4];
} ata_device_info_t;

typedef struct {
    u8 mode;
    u8 cycle_time;
} ata_protocol_t;

ata_device_info_t ata_device_info;

int ata_identify(void);
int ata_init(void);
int ata_read(u16 device, u32 lba, u8 *buffer, u16 count);
int ata_write(u16 device, u32 lba, u8 *buffer, u16 count);

#endif
