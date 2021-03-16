/**
 * @file game_save.c
 * 
 * @author jevarg
 * @brief Game save
 */

#include "game_save.h"
#include "weapon.h"
#include <stdio.h>

#define SAVE_FILE_PATH "hyper.sav"

int
save_game(int slot)
{
  int z3, zz5;

  FILE* fp1;

  game_data[slot].level = level_num;
  game_data[slot].diff = diff_level_set;
  game_data[slot].score = score;
  game_data[slot].power = power_level;
  game_data[slot].shields = shield_level;
  game_data[slot].protons = weapon_list[0].qty;
  game_data[slot].neutrons = weapon_list[1].qty;
  game_data[slot].darts = weapon_list[3].qty;

  strcpy(game_data[slot].access, access_buf);

  for (z3 = 0; z3 < 30; z3++)
  {
    game_data[slot].access[z3] = ~game_data[slot].access[z3];
  }

  zz5 = 55;
  for (z3 = 0; z3 < 10000; z3++)
  {
    zz5 = (zz5 / 1234) * 32 * zz5;
  }

  fp1 = fopen(SAVE_FILE_PATH, "wb+");
  if (fp1 == NULL)
  {
    return (0);
  }

  for (z3 = 0; z3 < 10; z3++)
  {
    fwrite(&game_data[z3], sizeof(gm_one), 1, fp1);
  }

  fclose(fp1);
  return (1);
}

int
load_gamefile()
{
  int z3;

  FILE* fp1;

  fp1 = fopen(SAVE_FILE_PATH, "rb");
  if (fp1 == NULL)
  {
    return (0);
  }

  for (z3 = 0; z3 < 10; z3++)
  {
    fread(&game_data[z3], sizeof(gm_one), 1, fp1);
  }

  fclose(fp1);
  return (1);
}