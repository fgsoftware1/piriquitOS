#ifndef GDT_H
#define GDT_H

#include "libc/include/types.h"
#include "libc/include/string.h"

#define NO_GDT_DESCRIPTORS     8

typedef struct {
    u16 segment_limit;
    u16 base_low;
    u8 base_middle;
    u8 access;
    u8 granularity;
    u8 base_high;
} __attribute__((packed)) GDT;

typedef struct {
    u16 limit;
    u32 base_address;
} __attribute__((packed)) GDT_PTR;


extern void load_gdt(u32 gdt_ptr);

void gdt_set_entry(int index, u32 base, u32 limit, u8 access, u8 gran);

void gdt_init();

#endif
