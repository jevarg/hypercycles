#pragma once

#include <stdio.h>

// Structures

struct __attribute__((__packed__)) adt_struc
{
  unsigned char fname[15];
  int start;
  int length;
} adt1[145], adt2[85], adt_single;

// Globals

extern int GFL1B;
extern int GFL2;