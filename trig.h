#pragma once

#define NUMBER_OF_DEGREES 4096
#define SHIFT 16
#define SHIFT_MULT 1 << SHIFT;

//(NUMBER_OF_DEGREES-1)]
#define SIN(X) fx_sin_table[X & 4095]

extern int fx_sin_table[4096];
