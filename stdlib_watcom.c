#include "stdlib.h"
#include <string.h>
#include <stdbool.h>

/**
 * Apple specific functions
 */

#if __APPLE__

char*
strrev(char* str)
{
  if (!str || !*str)
    return str;

  int i = strlen(str) - 1, j = 0;

  char ch;
  while (i > j)
    {
      ch = str[i];
      str[i] = str[j];
      str[j] = ch;
      i--;
      j++;
    }
  return str;
}

char*
itoa(int num, char* string, int radix)
{
  int i = 0;
  bool isNegative = false;

  /* Handle 0 explicitely, otherwise empty string is printed for 0 */
  if (num == 0)
    {
      string[i++] = '0';
      string[i] = '\0';

      return string;
    }

  // In standard itoa(), negative numbers are handled only with
  // base 10. Otherwise numbers are considered unsigned.
  if (num < 0 && radix == 10)
    {
      isNegative = true;
      num = -num;
    }

  // Process individual digits
  while (num != 0)
    {
      int rem = num % radix;

      string[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
      num = num / radix;
    }

  // If number is negative, append '-'
  if (isNegative)
    string[i++] = '-';

  string[i] = '\0'; // Append string terminator

  // Reverse the string
  return strrev(string);
}

#endif /* __APPLE__ */