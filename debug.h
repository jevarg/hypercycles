#pragma once

#include <error.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define PRINT_FUNC error(0, 0, "Unimplemented function %s (%s:%d)", __func__, __FILE__, __LINE__);

extern bool debug_ignore_delay;

int32_t _cos(int32_t x);