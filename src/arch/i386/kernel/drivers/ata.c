#include "../include/drivers/ata.h"
#include "../include/io.h"
#include "../include/drivers/pic.h"
#include "../include/console.h"

void ata_wait_bsy() {
    while (inportb(ATA_PRIMARY_IO + ATA_REG_STATUS) & 0x80);
}

void ata_wait_drq() {
    while (!(inportb(ATA_PRIMARY_IO + ATA_REG_STATUS) & 0x08));
}

bool ata_read_sector(u8 *buffer, u32 lba) {
    ata_wait_bsy();

    outportb(ATA_PRIMARY_IO + ATA_REG_HDDEVSEL, 0xE0 | ((lba >> 24) & 0x0F));
    outportb(ATA_PRIMARY_IO + ATA_REG_FEATURES, 0);
    outportb(ATA_PRIMARY_IO + ATA_REG_SECCOUNT0, 1);
    outportb(ATA_PRIMARY_IO + ATA_REG_LBA0, (u8)lba);
    outportb(ATA_PRIMARY_IO + ATA_REG_LBA1, (u8)(lba >> 8));
    outportb(ATA_PRIMARY_IO + ATA_REG_LBA2, (u8)(lba >> 16));
    outportb(ATA_PRIMARY_IO + ATA_REG_COMMAND, ATA_CMD_READ_PIO);

    ata_wait_bsy();
    ata_wait_drq();

    for (int i = 0; i < 256; i++) {
        u16 data = *(u16*)(ATA_PRIMARY_IO + ATA_REG_DATA);
        buffer[i*2] = (u8)data;
        buffer[i*2+1] = (u8)(data >> 8);
    }

    ata_wait_bsy();

    return true;
}

bool ata_write_sector(u8 *buffer, u32 lba) {
    ata_wait_bsy();

    outportb(ATA_PRIMARY_IO + ATA_REG_HDDEVSEL, 0xE0 | ((lba >> 24) & 0x0F));
    outportb(ATA_PRIMARY_IO + ATA_REG_FEATURES, 0);
    outportb(ATA_PRIMARY_IO + ATA_REG_SECCOUNT0, 1);
    outportb(ATA_PRIMARY_IO + ATA_REG_LBA0, (u8)lba);
    outportb(ATA_PRIMARY_IO + ATA_REG_LBA1, (u8)(lba >> 8));
    outportb(ATA_PRIMARY_IO + ATA_REG_LBA2, (u8)(lba >> 16));
    outportb(ATA_PRIMARY_IO + ATA_REG_COMMAND, ATA_CMD_WRITE_PIO);

    ata_wait_bsy();
    ata_wait_drq();

    for (int i = 0; i < 256; i++) {
        u16 data = buffer[i*2] | (buffer[i*2+1] << 8);
        *(u16*)(ATA_PRIMARY_IO + ATA_REG_DATA) = data;
        io_wait();
    }

    ata_wait_bsy();

    return true;
}

void ata_read_identify(u16 io_port, ata_device_t* device) {
    u16 identify_data[256];
    for (int i = 0; i < 256; i++) {
        identify_data[i] = *(u16*)(io_port + ATA_REG_DATA);
    }

    device->present = true;
    device->signature = identify_data[0];
    device->capabilities = identify_data[49];
    device->command_sets = identify_data[82] | ((u32)identify_data[83] << 16);
    device->size = identify_data[60] | ((u32)identify_data[61] << 16);

    for (int i = 0; i < 20; i++) {
        u16 data = identify_data[27 + i];
        device->model[i*2] = (data >> 8) & 0xFF;
        device->model[i*2 + 1] = data & 0xFF;
    }
    device->model[40] = '\0';

    for (int i = 39; i >= 0 && device->model[i] == ' '; i--) {
        device->model[i] = '\0';
    }
}

int ata_software_reset(u16 io_base) {
    outportb(io_base + ATA_REG_COMMAND, 4);
    io_wait();
    outportb(io_base + ATA_REG_COMMAND, 0);
    io_wait();

    for (int i = 0; i < 1000; i++) {
        if ((inportb(io_base + ATA_REG_STATUS) & 0x80) == 0) {
            return 0;
        }
        io_wait();
    }

    return -1;
}

void ata_probe_devices() {
    outportb(ATA_PRIMARY_IO + ATA_REG_HDDEVSEL, 0xA0);
    io_wait();
    if (ata_software_reset(ATA_PRIMARY_IO) == 0) {
        ata_read_identify(ATA_PRIMARY_IO, &ata_primary_master);
    }

    outportb(ATA_PRIMARY_IO + ATA_REG_HDDEVSEL, 0xB0);
    io_wait();
    if (ata_software_reset(ATA_PRIMARY_IO) == 0) {
        ata_read_identify(ATA_PRIMARY_IO, &ata_primary_slave);
    }

    outportb(ATA_SECONDARY_IO + ATA_REG_HDDEVSEL, 0xA0);
    io_wait();
    if (ata_software_reset(ATA_SECONDARY_IO) == 0) {
        ata_read_identify(ATA_SECONDARY_IO, &ata_secondary_master);
    }

    outportb(ATA_SECONDARY_IO + ATA_REG_HDDEVSEL, 0xB0);
    io_wait();
    if (ata_software_reset(ATA_SECONDARY_IO) == 0) {
        ata_read_identify(ATA_SECONDARY_IO, &ata_secondary_slave);
    }
}

ata_status_t ata_read_status(u16 io_base) {
    u8 status = inportb(io_base + ATA_REG_STATUS);
    return (ata_status_t) {
        .busy = (status & 0x80) != 0,
        .data_ready = (status & 0x08) != 0,
        .error = (status & 0x01) != 0
    };
}

void ata_interrupt_handler(registers_t *regs) {
    ata_status_t primary_status = ata_read_status(ATA_PRIMARY_IO);
    ata_status_t secondary_status = ata_read_status(ATA_SECONDARY_IO);

    if (!primary_status.busy) {
        ata_primary_status = primary_status;
        if (primary_status.error) {
            u8 error = inportb(ATA_PRIMARY_IO + ATA_REG_ERROR);
        } else if (primary_status.data_ready) {
        }
    }

    if (!secondary_status.busy) {
        ata_secondary_status = secondary_status;
        if (secondary_status.error) {
            u8 error = inportb(ATA_SECONDARY_IO + ATA_REG_ERROR);
        } else if (secondary_status.data_ready) {
        }
    }

    inportb(ATA_PRIMARY_IO + ATA_REG_STATUS);
    inportb(ATA_SECONDARY_IO + ATA_REG_STATUS);
}

bool ata_init() {
    printf("Initializing ATA...\n");
    isr_register_interrupt_handler(IRQ_ATA1, ata_interrupt_handler);
    isr_register_interrupt_handler(IRQ_ATA2, ata_interrupt_handler);

    ata_primary_status = (ata_status_t){0};
    ata_secondary_status = (ata_status_t){0};

    ata_probe_devices();

    ata_software_reset(ATA_PRIMARY_IO);
    ata_software_reset(ATA_SECONDARY_IO);

    ata_probe_devices();

    unmask(IRQ_ATA1 - IRQ_BASE);
    unmask(IRQ_ATA2 - IRQ_BASE);

    return true;
}
