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
  if (!g_debug_ignore_delay)
  {
    usleep(milliseconds * 500); // usleep is taking microseconds
  }

  return milliseconds;
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
