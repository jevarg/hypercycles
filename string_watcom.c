#include <string.h>
#include <stddef.h>
#include "string_watcom.h"

char*
strupr(char* s)
{
  for (size_t i = 0; s[i] != '\0'; ++i)
  {
    s[i] = toupper(s[i]);
  }

  return s;
}

char*
strlwr(char* s)
{
  for (size_t i = 0; s[i] != '\0'; ++i)
  {
    s[i] = tolower(s[i]);
  }

  return s;
}
