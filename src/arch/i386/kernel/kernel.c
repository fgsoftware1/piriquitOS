#include "./include/libc/include/string.h"
#include "./include/libc/include/defines.h"
#include "include/drivers/pic.h"
#include "include/drivers/keyboard.h"
#include "include/drivers/cmos.h"
#include "include/kernel.h"
#include "include/console.h"
#include "include/gdt.h"
#include "include/idt.h"
#include "include/io.h"

void cpuid(u32 type, u32 *eax, u32 *ebx, u32 *ecx, u32 *edx)
{
    asmv("cpuid"
         :  "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx)
         :  "0"(type));
}

int cpuid_info(int print)
{
    u32 brand[12];
    u32 eax, ebx, ecx, edx;
    u32 type;

    memset(brand, 0, sizeof(brand));
    cpuid(0x80000002, (u32 *)brand + 0x0, (u32 *)brand + 0x1, (u32 *)brand + 0x2, (u32 *)brand + 0x3);
    cpuid(0x80000003, (u32 *)brand + 0x4, (u32 *)brand + 0x5, (u32 *)brand + 0x6, (u32 *)brand + 0x7);
    cpuid(0x80000004, (u32 *)brand + 0x8, (u32 *)brand + 0x9, (u32 *)brand + 0xa, (u32 *)brand + 0xb);

    if (print)
    {
        printf("Brand: %s\n", brand);
        for (type = 0; type < 4; type++)
        {
            cpuid(type, &eax, &ebx, &ecx, &edx);
            printf("type:0x%x, eax:0x%x, ebx:0x%x, ecx:0x%x, edx:0x%x\n", type, eax, ebx, ecx, edx);
        }
    }

    if (strstr(brand, "QEMU") != NULL)
        return BRAND_QEMU;

    return BRAND_VBOX;
}

BOOL is_echo(char *b)
{
    if ((b[0] == 'e') && (b[1] == 'c') && (b[2] == 'h') && (b[3] == 'o'))
        if (b[4] == ' ' || b[4] == '\0')
            return TRUE;
    return FALSE;
}

void shutdown()
{
    int brand = cpuid_info(0);

    if (brand == BRAND_QEMU)
        outports(0x604, 0x2000);
    else
        outports(0x4004, 0x3400);
}

void kmain()
{
    char buffer[255];
    const char *shell = "shell>";

    console_init(COLOR_WHITE, COLOR_BLACK);
    init_gdt();
    init_pic();
    init_idt();
    init_cmos();
    init_keyboard();

    while (1)
    {
        printf(shell);
        memset(buffer, 0, sizeof(buffer));
        getstr_bound(buffer, strlen(shell));

        if (strlen(buffer) == 0)
        {
            continue;
        }
        if (strcmp(buffer, "clear") == 0)
        {
            console_clear(COLOR_WHITE, COLOR_BLACK);
        }else if (strcmp(buffer, "cpuid") == 0)
        {
            cpuid_info(1);
        }else if (strcmp(buffer, "help") == 0)
        {
            printf("Commands: help, cpuid, echo, shutdown\n");
        }else if (is_echo(buffer))
        {
            printf("%s\n", buffer + 5);
        }else if (strcmp(buffer, "shutdown") == 0)
        {
            shutdown();
        }else if (strcmp(buffer, "time") == 0)
        {
            u8 seconds = cmos_read(RTC_SECONDS);
            u8 minutes = cmos_read(RTC_MINUTES);
            u8 hours   = cmos_read(RTC_HOURS);

            printf("Time: %d:%d:%d\n", hours, minutes, seconds);
        }else
        {
            printf("invalid command: %s\n", buffer);
        }
    }
}
