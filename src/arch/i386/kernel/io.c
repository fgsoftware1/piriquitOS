#include "./include/libc/include/types.h"
#include "./include/libc/include/defines.h"
#include "include/io.h"

u8 inportb(u16 port)
{
    u8 ret;
    asmv("inb %1, %0"
         : "=a"(ret)
         : "Nd"(port));
    return ret;
}

void outportb(u16 port, u8 val)
{
    asmv("outb %1, %0" ::"dN"(port), "a"(val));
}

u16 inports(u16 port)
{
    u16 rv;
    asmv("inw %1, %0"
         : "=a"(rv)
         : "dN"(port));
    return rv;
}

void outports(u16 port, u16 data)
{
    asmv("outw %1, %0"
         :
         : "dN"(port), "a"(data));
}

u32 inportl(u16 port)
{
    u32 rv;
    asmv("inl %%dx, %%eax"
         : "=a"(rv)
         : "dN"(port));
    return rv;
}

void outportl(u16 port, u32 data)
{
    asmv("outl %%eax, %%dx"
         :
         : "dN"(port), "a"(data));
}

void insw(u16 port, void *buffer, u32 count)
{
    asmv("cld; rep insw"
         : "+D"(buffer), "+c"(count)
         : "d"(port)
         : "memory");
}
