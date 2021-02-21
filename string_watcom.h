#pragma once

#if __APPLE__

#include <ctype.h>

// char *strlwr(char *s) {
//     unsigned c;
//     unsigned char *p = (unsigned char *)s;

//     while (c = *p) *p++ = tolower(c);
// }

char *strupr(char *s);
#endif