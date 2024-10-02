#ifndef ATA_H
#define ATA_H

#include "../libc/include/types.h"
#include "../isr.h"

#define ATA_PRIMARY_IO 0x1F0
#define ATA_SECONDARY_IO 0x170

#define ATA_REG_DATA 0x00
#define ATA_REG_ERROR 0x01
#define ATA_REG_FEATURES 0x01
#define ATA_REG_SECCOUNT0 0x02
#define ATA_REG_LBA0 0x03
#define ATA_REG_LBA1 0x04
#define ATA_REG_LBA2 0x05
#define ATA_REG_HDDEVSEL 0x06
#define ATA_REG_COMMAND 0x07
#define ATA_REG_STATUS 0x07
#define ATA_REG_CONTROL 0x0C

#define ATA_CMD_READ_PIO 0x20
#define ATA_CMD_WRITE_PIO 0x30

typedef struct {
    bool present;
    bool is_atapi;
    u16 signature;
    u16 capabilities;
    u32 command_sets;
    u32 size;
    char model[41];
} ata_device_t;

typedef struct {
    bool busy;
    bool data_ready;
    bool error;
} ata_status_t;

static ata_device_t ata_primary_master;
static ata_device_t ata_primary_slave;
static ata_device_t ata_secondary_master;
static ata_device_t ata_secondary_slave;
static ata_status_t ata_primary_status;
static ata_status_t ata_secondary_status;

void ata_wait_bsy();
void ata_wait_drq();
bool ata_read_sector(u8 *buf, u32 sector);
bool ata_write_sector(u8 *buf, u32 sector);
void ata_read_identify(u16 io_port, ata_device_t* device);
int ata_software_reset(u16 io_base);
void ata_probe_devices();
ata_status_t ata_read_status(u16 io_base);
void ata_interrupt_handler(registers_t *regs);
bool ata_init();

#endif // !ATA_H
