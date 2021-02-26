#include <stdint.h>

#include "debug.h"

int32_t
fixmul(int32_t a, int32_t b)
{
  return (int32_t)((int64_t)a * (int64_t)b) >> 16;
}

int32_t
fixmul2(int32_t a, int32_t b)
{
  return (int32_t)((int64_t)a * (int64_t)b) >> 24;
}

int32_t
fixdiv(int32_t a, int32_t b)
{
  if (!b)
  {
    error(0, 0, "Division by zero!");
    return 0;
  }

  return ((int64_t)a * (1 << 16)) / b;
}

int32_t
shf1(int32_t a)
{
  return a >> 22;
}

int32_t
qrshift(int32_t a, int32_t b)
{
  return a >> b;
}
