#pragma once

#include <stdint.h>
#include <stdbool.h>

// Functions

void display_text(int x, int y, char* txt, int color);
int difflvl();

uint32_t get_current_timestamp();

// Globals

extern bool g_use_adt_files;
extern int level_num;
extern int old_level_num;
extern short int curr_weapon;
extern unsigned int* vga_ram;
extern unsigned int* double_buffer_l;
extern unsigned int* equip;
extern unsigned char wall_ht_map[4150];
extern char dead;
extern short int eq_gotit;
extern int demo_mode;
extern int demo_ctr;
extern char rings;
extern char controls;
extern char digi_flag;