/**
 * @file menu.c
 * 
 * @author jevarg
 * @brief Main menu
 */

#include "menu.h"
#include "rendering.h"
#include "screen.h"
#include "game_save.h"
#include "weapon.h"

int
save_load(int which) //0=save 1=load
{
  int a, b, c, pick = 0, ready = 0, clr, e;
  char entry[25];

  PCX_Load("pointer.pcx", 157, 1);
  PCX_Load("poster1.pcx", 159, 1);
  load_gamefile();

  if (!which)
  {
    PCX_Load("savegame.pcx", 158, 1);
    clr = 249;
  }
  else
  {
    PCX_Load("loadgame.pcx", 158, 1);
    clr = 6;
  }

//   clear_screen(clr, SCREEN_BUFFER_SIZE);

  Display2(160, 6, 158);
  Display2(60, 49, 157);
  b = 50;
  for (a = 0; a < 10; a++)
  {
    Display2(160, b, 159);
    if (!game_data[a].games[0])
      display_text(104, b + 3, "EMPTY", 255);
    else
      display_text(104, b + 3, game_data[a].games, 255);
    b += 14;
  }
  c = 0;
  new_key = 0;
  while (!c)
  {
    if (new_key == 27)
    {
      if (!ready)
        c++;
      else
      {
        ready = 0;
        Display2(160, pick * 14 + 50, 159);
        if (!game_data[pick].games[0])
          display_text(104, pick * 14 + 53, "EMPTY", 255);
        else
          display_text(104, pick * 14 + 53, game_data[pick].games, 255);
        delay(250);
        new_key = 0;
      }
    }
    else if (new_key == 13)
    {
      if (!which)
      {
        if (!ready)
        {
          e = 0;
          ready++;
          Display2(160, pick * 14 + 50, 159);
          display_text(104, pick * 14 + 53, "@", 255);
          entry[0] = 0;
        }
        else
        {

          ready = 0;
          //Save game call
          if (entry[0])
          {
            strcpy(game_data[pick].games, entry);
            save_game(pick);
          }
          Display2(160, pick * 14 + 50, 159);
          display_text(104, pick * 14 + 53, entry, 255);
        }
      }
      else
      {
        level_num = game_data[pick].level;
        old_level_num = -1;
        diff_level_set = game_data[pick].diff;
        score = game_data[pick].score;
        power_level = game_data[pick].power;
        shield_level = game_data[pick].shields;
        weapon_list[0].qty = game_data[pick].protons;
        weapon_list[1].qty = game_data[pick].neutrons;
        weapon_list[3].qty = game_data[pick].darts;
        strcpy(access_buf, game_data[pick].access);
        for (a = 0; a < 30; a++)
          access_buf[a] = ~access_buf[a];
        if (access_buf[1] == ' ')
          curr_weapon = 0;
        new_key = 0;
        return (1);
      }
      delay(250);
      new_key = 0;
    }
    else if (!ready && new_key == 5)
    {
      pick--;
      if (pick < 0)
        pick = 9;
      
      clear_screen(clr, SCREEN_BUFFER_SIZE);
      Display2(160, 6, 158);
      b = 50;
      for (a = 0; a < 10; a++)
      {
        Display2(160, b, 159);
        if (!game_data[a].games[0])
          display_text(104, b + 3, "EMPTY", 255);
        else
          display_text(104, b + 3, game_data[a].games, 255);
        b += 14;
      }
      Display2(60, pick * 14 + 49, 157);
      delay(150);
      new_key = 0;
    }
    else if (!ready && new_key == 8)
    {
      pick++;
      if (pick > 9)
        pick = 0;
      
      clear_screen(clr, SCREEN_BUFFER_SIZE);
      Display2(160, 6, 158);
      b = 50;
      for (a = 0; a < 10; a++)
      {
        Display2(160, b, 159);
        if (!game_data[a].games[0])
          display_text(104, b + 3, "EMPTY", 255);
        else
          display_text(104, b + 3, game_data[a].games, 255);
        b += 14;
      }
      Display2(60, pick * 14 + 49, 157);
      delay(150);
      new_key = 0;
    }
    else if (ready && new_key == 14 && entry[0] >= '0') //BackSpace
    {
      for (a = 0; a < 14; a++)
      {
        if (!entry[a])
        {
          entry[a - 1] = 0;
          break;
        }
      }
      e = 13;
      Display2(160, pick * 14 + 50, 159);
      display_text(104, pick * 14 + 53, entry, 255);
      display_text(a * 8 + 96, pick * 14 + 53, "@", 255);
      delay(150);
      new_key = 0;
    }
    else if (ready && new_key >= '0')
    {
      for (a = 0; a < 14; a++)
      {
        if (!entry[a])
        {
          entry[a] = new_key;
          entry[a + 1] = 0;
          break;
        }
      }
      e = 13;
      Display2(160, pick * 14 + 50, 159);
      display_text(104, pick * 14 + 53, entry, 255);
      display_text(a * 8 + 112, pick * 14 + 53, "@", 255);
      delay(100);
      new_key = 0;
    }

    
    if (!musRunning && music_toggle == 2)
    {
      if (music_cnt == 4)
      {
        play_again();
        music_cnt--;
      }
    }
    if (music_toggle == 2 && music_cnt < 4)
    {
      music_cnt--;
      if (!music_cnt)
      {
        if (next_song[0])
        {
          play_song(next_song);
          strcpy(curr_song, next_song);
          next_song[0] = 0;
        }
        else
          play_again();
        music_cnt = 4;
      }
    }
  }
  PCX_Unload(158);
  PCX_Unload(159);
  PCX_Unload(157);
  new_key = 0;
  return (0);
}