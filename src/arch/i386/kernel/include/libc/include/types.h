#ifndef TYPES_H
#define TYPES_H

#define NULL ((void*)0)

#ifdef __x86_64__
    typedef unsigned long long size_t;
    typedef signed long long ssize_t;
#else
    typedef unsigned int size_t;
    typedef signed int ssize_t;
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef char wchar_t;
typedef u8 byte;
typedef u16 word;
typedef u32 dword;

typedef enum {
    false,
    true
} bool;

typedef struct file
{
    char *ptr;
    int cnt;
    char *base;
    int flag;
    int fd;
    int bufsize;
    char *tmpfname;
}file_t;

#endif
