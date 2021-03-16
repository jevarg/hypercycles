#pragma once

#include "h3d_mdef.h"

#include <stdio.h>
#include <stdbool.h>

// Globals

unsigned char* g_wall_map[WORLD_ROWS + 5];   // pointer to matrix of cells that make up world of walls
unsigned char* g_floor_map[WORLD_ROWS + 5];  // pointer to matrix of cells that make up world of floor
unsigned char* g_ceiling_map[WORLD_ROWS + 5]; // pointer to matrix of cells that make up world of ceiling

extern bool g_use_adt_files;
extern int GFL1A, GFL1B;
extern FILE* GFL1_FP;

// Functions

void allocate_world();
int load_world(char* file, char* wptr[64]);