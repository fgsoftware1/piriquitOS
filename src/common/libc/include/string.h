#pragma once

#include <stdint.h>
#include <stdarg.h>

#include "memory.h"

int strlen(char *ptr);
char *strcat(char *dest, const char *source);
int strncmp(const char *s1, const char *s2, size_t n);

void strncpy(char *ptr_dest, char *ptr_src, int n);

int putchar(int);

int sprintf(char *buffer, const char *fmt, ...);
int vsprintf(char *buffer, const char *format, va_list parameters);

ldiv_t ldiv(unsigned long numerator, unsigned long denominator);
char *ltoa(unsigned long long value, char *buffer, int radix);

int itoa(int value, char *sp, int radix);
int atoi(char *str);
