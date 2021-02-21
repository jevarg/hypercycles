#pragma once

#include "watcom.h"

// http://www.delorie.com/djgpp/doc/libc/libc_486.html

struct DWORDREGS {
  unsigned long edi;
  unsigned long esi;
  unsigned long ebp;
  unsigned long cflag;
  unsigned long ebx;
  unsigned long edx;
  unsigned long ecx;
  unsigned long eax;
  unsigned short eflags;
};

struct DWORDREGS_W {
  unsigned long di;
  unsigned long si;
  unsigned long bp;
  unsigned long cflag;
  unsigned long bx;
  unsigned long dx;
  unsigned long cx;
  unsigned long ax;
  unsigned short flags;
};

struct WORDREGS {
  unsigned short di, _upper_di;
  unsigned short si, _upper_si;
  unsigned short bp, _upper_bp;
  unsigned short cflag, _upper_cflag;
  unsigned short bx, _upper_bx;
  unsigned short dx, _upper_dx;
  unsigned short cx, _upper_cx;
  unsigned short ax, _upper_ax;
  unsigned short flags;
};

struct BYTEREGS {
  unsigned short di, _upper_di;
  unsigned short si, _upper_si;
  unsigned short bp, _upper_bp;
  unsigned long cflag;
  unsigned char bl;
  unsigned char bh;
  unsigned short _upper_bx;
  unsigned char dl;
  unsigned char dh;
  unsigned short _upper_dx;
  unsigned char cl;
  unsigned char ch;
  unsigned short _upper_cx;
  unsigned char al;
  unsigned char ah;
  unsigned short _upper_ax;
  unsigned short flags;
};

union REGS {
  struct DWORDREGS d;
#ifdef _NAIVE_DOS_REGS
  struct WORDREGS x;
#else
#ifdef _BORLAND_DOS_REGS
  struct DWORDREGS x;
#else
  struct DWORDREGS_W x;
#endif
#endif
  struct WORDREGS w;
  struct BYTEREGS h;
};

struct SREGS {
  unsigned short es;
  unsigned short ds;
  unsigned short fs;
  unsigned short gs;
  unsigned short cs;
  unsigned short ss;
};

int int386(int ivec, union REGS *in, union REGS *out);
int int386x(int ivec, union REGS *in, union REGS *out, struct SREGS *seg);

/**
 * @note   https://www.stanislavs.org/helppc/_dos_setvect.html
 * @param  intnum: interrupt vector to set  (0..255)
 * @param  *handler: new interrupt routine
 */
void  _dos_setvect( unsigned intnum, void (interrupt far *handler)());

/**
 * @note   https://www.stanislavs.org/helppc/_dos_getvect.html
 * @param  intnum: interrupt to get address of (0..255)
 * @retval Far pointer to interrupt handler routine
 */
void interrupt far *_dos_getvect(unsigned intnum);


void _chain_intr(void (interrupt far *target)());