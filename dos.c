#include "dos.h"

int int386(int ivec, union REGS *in, union REGS *out)
{
    return 0;
}

int int386x(int ivec, union REGS *in, union REGS *out, struct SREGS *seg)
{
    return 0;
}

void  _dos_setvect( unsigned intnum, void (interrupt far *handler)())
{
    return;
}

void interrupt far *_dos_getvect( unsigned intnum )
{
    return 0;
}

void _chain_intr(void (interrupt far *target)()) {}