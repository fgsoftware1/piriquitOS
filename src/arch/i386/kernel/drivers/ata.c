#include "../include/drivers/ata.h"
#include "../include/io.h"
#include "../include/console.h"
#include "../include/isr.h"

int ata_identify(void)
{
    outportb(ATA_COMMAND_REGISTER, ATA_CMD_IDENTIFY);

    // Wait for the device to become ready
    if (ata_wait_for_status(ATA_STATUS_BSY | ATA_STATUS_DRQ) != 0)
    {
        return -1;
    }

    // Send the IDENTIFY command
    outportb(ATA_COMMAND_REGISTER, ATA_CMD_IDENTIFY);

    // Wait for the device to become ready
    if (ata_wait_for_status(ATA_STATUS_BSY | ATA_STATUS_DRQ) != 0)
    {
        return -1;
    }

    // Read the device information
    insw(ATA_DATA_REGISTER, (u16 *)&ata_device_info, sizeof(ata_device_info_t) / 2);

    // Check for errors
    if (inb(ATA_ERROR_REGISTER) != 0)
    {
        return -1;
    }

    // Return success
    return 0;
}

void ata_select_device(u16 device)
{
    outportb(ATA_DEVICE_REGISTER, (device & 0x10) | ((device & 0x01) << 4));
}

ata_hadler(struct registers_t *r, u32 command, void *buffer, u32 count)
{
    switch (command)
    {
    case ATA_CMD_IDENTIFY:
        return ata_identify();
    case ATA_CMD_READ_SECTOR:
        return ata_read(buffer, count);
    case ATA_CMD_WRITE_SECTOR:
        return ata_write(buffer, count);
    default:
        return -1;
    }
}

int ata_init(void)
{
    printf("Initializing ATA...\n");
    outportb(ATA_CONTROLLER_BASE_PORT + 1, 0x00); // Disable all interrupts
    outportb(ATA_CONTROLLER_BASE_PORT + 2, 0x00); // No sector count
    outportb(ATA_CONTROLLER_BASE_PORT + 3, 0x00); // No LBA
    outportb(ATA_CONTROLLER_BASE_PORT + 4, 0x00); // No device
    outportb(ATA_CONTROLLER_BASE_PORT + 5, 0x00); // No command

    ata_select_device(ATA_DEVICE_MASTER);
    ata_identify();
    isr_register_interrupt_handler(IRQ_BASE + IRQ_ATA1, ata_hadler);
}

int ata_read(u16 device, u32 lba, u8 *buffer, u16 count)
{
    // Select the device
    ata_select_device(device);

    // Set the LBA and sector count
    outportb(ATA_LBA_LOW, (u8)(lba & 0xFF));
    outportb(ATA_LBA_MID, (u8)((lba >> 8) & 0xFF));
    outportb(ATA_LBA_HIGH, (u8)((lba >> 16) & 0xFF));
    outportb(ATA_SECTOR_COUNT, count);

    // Send the read command
    outportb(ATA_COMMAND_REGISTER, ATA_CMD_READ_SECTOR);

    // Wait for the device to become ready
    if (ata_wait_for_status(ATA_STATUS_BSY | ATA_STATUS_DRQ) != 0)
    {
        return -1;
    }

    // Read the data
    insw(ATA_DATA_REGISTER, buffer, count * ATA_SECTOR_SIZE / 2);

    // Check for errors
    if (inb(ATA_ERROR_REGISTER) != 0)
    {
        return -1;
    }

    // Return success
    return 0;
}

int ata_write(u32 lba, u8 *buffer, u16 count)
{
    outportb(ATA_COMMAND_REGISTER, ATA_CMD_WRITE_SECTOR);
    outportb(ATA_SECTOR_COUNT, count);
    outportb(ATA_LBA_LOW, (lba & 0x000000FF));
    outportb(ATA_LBA_MID, (lba & 0x0000FF00) >> 8);
    outportb(ATA_LBA_HIGH, (lba & 0x00FF0000) >> 16);
    outportb(ATA_DEVICE_REGISTER, (1 `oaicite
                                   : { "index" : 0, "invalid_reason" : "Malformed citation << 6) | ((lba & 0x0F000000) >>" }` 24));

    // Wait for the device to become ready
    if (ata_wait_for_status(ATA_STATUS_BSY | ATA_STATUS_DRQ) != 0)
    {
        return -1;
    }

    // Write the data
    outsw(ATA_DATA_REGISTER, buffer, ATA_SECTOR_SIZE / 2 * count);
    return 0;
}
