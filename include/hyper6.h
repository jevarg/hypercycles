#pragma once

#include <stdint.h>
#include <stdbool.h>

// Functions

void display_text(int x, int y, char* txt, int color);
int difflvl();

uint32_t get_current_timestamp();

// Globals

extern bool g_use_adt_files;