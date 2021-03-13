#pragma once

#define NUMBER_OF_DEGREES 4096
#define SHIFT 16
#define SHIFT_MULT 1 << SHIFT;

#include <stdlib.h>

//(NUMBER_OF_DEGREES-1)]
#define COS(X) fx_cos_table[X & 4095]
//(NUMBER_OF_DEGREES-1)]
#define SIN(X) fx_sin_table[X & 4095]

extern int32_t fx_cos_table[4096];
extern int32_t fx_sin_table[4096];
