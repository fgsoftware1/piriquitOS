#ifndef _STDIO_H
#define _STDIO_H 1

#include "defines.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>

#define EOF (-1)
#define false 0
#define true 1

#define bool _Bool

#ifdef __cplusplus
extern "C"
{
#endif

    int printf_template(bool (*)(const char *, size_t), const char *__restrict, va_list);
    int printf(const char *__restrict, ...);
    int putchar(int);
    int puts(const char *);

#ifdef __cplusplus
}
#endif

void debug_console();
void serial_write(const char *msg);
int dprintf(const char *restrict format, ...);
int noprintf(const char *restrict format, ...);

#endif
