#ifndef IO_H
#define IO_H

#include "libc/include/types.h"

u8 inportb(u16 port);
u16 inports(u16 port);
u32 inportl(u16 port);

void outportb(u16 port, u8 val);
void outports(u16 port, u16 data);
void outportl(u16 port, u32 data);

void insw(u16 port, void *buffer, u32 count);

#endif
