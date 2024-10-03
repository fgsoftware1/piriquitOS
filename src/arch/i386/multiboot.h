#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "types.h"

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MBALIGN (1 << 0)
#define MEMINFO (1 << 1)
#define MULTIBOOT_HEADER_FLAGS (MBALIGN | MEMINFO)
#define MULTIBOOT_HEADER_CHECKSUM (-(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS))

struct MultibootHeader {
    u32 magic;
    u32 flags;
    u32 checksum;
    u32 padding;
} __attribute__((packed));

#endif // !MULTIBOOT_H
