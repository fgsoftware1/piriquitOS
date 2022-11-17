#include <stddef.h>

#include "include/string.h"

int strlen(char *ptr)
{
    int len = 0;
    char *p = ptr;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    for (; n > 0; s1++, s2++, --n)
        if (*s1 != *s2)
            return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
        else if (*s1 == '\0')
            return 0;
    return 0;
}

char tolower(char upper)
{
    if (upper <= 'Z' && upper >= 'A')
        return upper - ('Z' - 'z');
    return upper;
}

char *strcat(char *dest, const char *src)
{
    char *rdest = dest;

    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
    return rdest;
}

char *strpbrk(const char *s, const char *accept)
{
    while (*s != '\0')
    {
        const char *a = accept;

        while (*a != '\0')
            if (*a++ == *s)
                return (char *)s;
        ++s;
    }
    return NULL;
}

size_t strspn(const char *s, const char *accept)
{
    const char *p;
    const char *a;
    size_t count = 0;

    for (p = s; *p != '\0'; ++p)
    {
        for (a = accept; *a != '\0'; ++a)
            if (*p == *a)
                break;
        if (*a == '\0')
            return count;
        else
            ++count;
    }

    return count;
}

char *strtok(char *str, const char *delim)
{
    static char *nxt;
    static int size;

    int i;

    if (str != NULL)
    {
        nxt = str;
        size = strlen(str);
    }

    else if (size > 0)
    {
        nxt++;
        size--;
        str = nxt;
    }

    else
    {
        str = NULL;
    }

    while (*nxt)
    {
        i = strspn(nxt, delim);
        while (i > 1)
        {
            *nxt = '\0';
            nxt++;
            size--;
            i--;
        }
        if (1 == i) 
        {
            *nxt = '\0';
            if (size > 1)
            {
                nxt--;
                size++;
            }
        }
        nxt++;
        size--;
    }
    return str;
}

void strncpy(char *ptr_dest, char *ptr_src, int n)
{
    for (int i = 0; i < n; i++)
        ptr_dest[i] = ptr_src[i];
}

string operator+(const string &s1, const string &s2)
{
    string res;
    res.length = s1.length + s2.length;
    res.buff = new char[res.length];
    strncpy(res.buff, s1.buff, s1.length);
    strncpy(res.buff + s1.length, s2.buff, s2.length);
    return res;
}
