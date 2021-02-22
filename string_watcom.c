#include "string_watcom.h"

#if __APPLE__

char*
strupr(char* s)
{
  unsigned c;
  unsigned char* p = (unsigned char*)s;

  while (c = *p)
    *p++ = tolower(c);
}

#endif