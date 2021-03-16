/**
 * @file world.c
 * 
 * @author jevarg
 * @brief World
 */

#include "world.h"
#include "debug.h"

void
allocate_world(void)
{
  // this function allocates the memory for the world
  int index; // allocate each row
  for (index = 0; index < WORLD_ROWS; index++)
  {
    g_wall_map[index] = (char*)malloc(WORLD_COLUMNS + 1);
    g_floor_map[index] = (char*)malloc(WORLD_COLUMNS + 1);
    g_ceiling_map[index] = (unsigned char*)malloc(WORLD_COLUMNS + 1);
  } // end for index
} // end allocate_world

int
load_world(char* file, char* wptr[64])
{
  // this function opens the input file and loads the world data from it

  FILE *fp, *fopen();
  int row, column;
  char ch;

  // open the file
  //fp = fopen(file,"r");

  if (g_debug_enabled)
  {
    printf("loading world file: %s\n", file);
  }

  if (!g_use_adt_files)
  {
    strlwr(file);
    fp = fopen(file, "r");
  }
  else
  {
    open_adt1(file, false);
    fp = GFL1_FP;
  }

  if (fp == NULL)
  {
    // return(0);
    set_vmode(2);
    printf("File not found\n");
    exit(0);
  }

  // load in the data
  for (row = 0; row < WORLD_ROWS; row++)
  {
    // load in the next row
    for (column = 0; column < WORLD_COLUMNS; column++)
    {
      while ((ch = getc(fp)) == 10)
      {
      } // filter out CR

      // translate character to integer
      if (ch == ' ')
        ch = 0;

      // insert data into g_wall_map
      wptr[row][column] = ch;

    } // end for column
  }   // end for row
  
  // close the file
  fclose(fp);
  return (1);
} // end load_world