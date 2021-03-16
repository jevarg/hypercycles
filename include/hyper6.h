#pragma once

#include <stdint.h>

void Display_Text(int x, int y, char* txt, int color);
int difflvl();
int save_load(int which); // 0=save 1=load

uint32_t get_current_timestamp();