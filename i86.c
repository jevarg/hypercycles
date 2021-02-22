#include "i86.h"
#include "debug.h"
#include <unistd.h>

void
_disable(void)
{
  PRINT_FUNC;
}
void
_enable(void)
{
  PRINT_FUNC;
}

unsigned int
delay(unsigned int milliseconds)
{
  PRINT_FUNC;
  usleep(milliseconds * 1000); // usleep is taking microseconds
}

unsigned
FP_SEG(void _far* far_ptr)
{
  PRINT_FUNC;
  return 0;
}

unsigned
FP_OFF(void _far* far_ptr)
{
  PRINT_FUNC;
  return 0;
}