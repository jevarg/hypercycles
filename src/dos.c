#include "dos.h"
#include "debug.h"

int
int386(int ivec, union REGS* in, union REGS* out)
{
  // PRINT_FUNC;
  return 0;
}

int
int386x(int ivec, union REGS* in, union REGS* out, struct SREGS* seg)
{
  // PRINT_FUNC;
  return 0;
}

void
_dos_setvect(unsigned intnum, void(interrupt far* handler)())
{
  // PRINT_FUNC;
  return;
}

void interrupt far*
_dos_getvect(unsigned intnum)
{
  // PRINT_FUNC;
  return 0;
}

void
_chain_intr(void(interrupt far* target)())
{
  // PRINT_FUNC;
}