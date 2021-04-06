#include "debug.h"

long int
filelength(int filedes)
{
  long length = 0;
  FILE* file = fdopen(filedes, "r");
  if (file == 0)
  {
    return length;
  }

  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fclose(file);

  return length;
}