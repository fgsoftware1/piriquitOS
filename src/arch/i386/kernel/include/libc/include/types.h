#ifndef TYPES_H
#define TYPES_H

#ifndef NULL
    #define NULL 0
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef u8 byte;
typedef u16 word;
typedef u32 dword;

typedef enum {
    FALSE,
    TRUE
} BOOL;

#endif
