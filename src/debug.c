#include <math.h>
#include <stdint.h>
#include "debug.h"

bool debug_ignore_delay = true;

int32_t
_cos(int32_t x)
{
  return (int32_t)floor(cos(2048 / M_PI) * UINT16_MAX);
}
