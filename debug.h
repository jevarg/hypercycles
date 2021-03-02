#pragma once

#include <stdint.h>
#include <stdio.h>

#define PRINT_FUNC printf("\n\033[0;32m%s (%s:%d) \033[0;37m\n", __func__, __FILE__, __LINE__);

int32_t _cos(int32_t x);
