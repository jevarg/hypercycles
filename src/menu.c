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
#include "audio.h"
#include "assets.h"
#include "hyper6.h"
#include "picture.h"
#include "world.h"
#include "demo.h"
#include "ctv.h"
#include "input.h"

char menu_mode = 0;

int
main_menu(int ck)
{
  int a, b, c, d, e, f, curr;
  unsigned int tmr9;
  short int mn1_flap = 0;

  int cheat_ctr = 0;
  //ck=0; // ****Take out
  b = 0;
  c = 0;
  d = 0;
  curr = 131;
  e = 0;
  f = 0;
  main_menu_load();

  while (!c)
  {
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
    PCX_Show_Image(270, 178, 140, picture[140].width);

    if (!ck)
    {
      for (a = 131; a <= 139; a++)
      {
        if (a != curr)
          PCX_Show_Image(160, 20 * (a - 131) + 15, a, picture[a].width - 10);
      }
      for (a = 131; a <= 139; a++)
      {
        if (a == curr)
          PCX_Show_Image(160, 20 * (a - 131) + 15, a, picture[a].width + 80);
      }
    }
    else
    { //no demo mode
      for (a = 131; a <= 138; a++)
      {
        if (a != curr)
        {
          if (a < 138)
            PCX_Show_Image(160, 20 * (a - 131) + 15, a, picture[a].width - 10);
          else
            PCX_Show_Image(160, 20 * (a - 131) + 15, 139, picture[139].width - 10);
        }
      }
      for (a = 131; a <= 139; a++)
      {
        if (a == curr)
        {
          if (a < 138)
            PCX_Show_Image(160, 20 * (a - 131) + 15, a, picture[a].width + 80);
          else
            PCX_Show_Image(160, 20 * (a - 131) + 15, 139, picture[139].width + 80);
        }
      }
    }

    render_frame();

    int level_jump = 0;
    // keyboard_input input;

    tmr9 = timerval() + 270; //15 seconds
    e = 0;
    while (!e)
    {
      update_keyboard_events();

      if (!ck && timerval() > tmr9)
      {
        if (!mn1_flap)
          curr = 138; // Run demo
        else
          curr = 137; // Credits
        new_key = 13;
      }

      switch (read_keyboard_event().keycode)
      {
        {
          // case 'A':
          //   if (cheat_ctr == 0)
          //     cheat_ctr++;
          //   else
          //     cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'H':
          //   if (cheat_ctr == 1)
          //     cheat_ctr++;
          //   else
          //     cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'C':
          //   if (cheat_ctr == 2)
          //     cheat_ctr++;
          //   else
          //     cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'R':
          //   if (cheat_ctr == 3)
          //     cheat_ctr++;
          //   else
          //     cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'P':
          //   if (ck && cheat_ctr == 4)
          //   {
          //     shieldit(5000);
          //     powerit(5000);
          //     digital_speed = 9500;
          //     play_vox("allkeys.raw");
          //     digital_speed = 11025;
          //   }
          //   cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // /*case 'I':
          //      if(ck && cheat_ctr==4)
          //      {
          //        if(!invun) invun=1;
          //        else invun=0;
          //        digital_speed=9500;
          //        play_vox("allkeys.raw");
          //        digital_speed=11025;
          //      }
          //      cheat_ctr=0;
          //      new_key=0;
          //      break;*/
          // case 'O':
          //   if (ck && cheat_ctr == 4)
          //   {
          //     for (d = 0, a = 0; a < 64; a++, d += 64)
          //     {
          //       for (b = 0; b < 64; b++)
          //       {
          //         // Alter so all doors start falling
          //         if (g_wall_map[a][b] == 'Y' || g_wall_map[a][b] == 'Z')
          //           wall_ht_map[d + b] = (wall_ht_map[d + b] & 63) | 128;
          //       }
          //     }
          //     digital_speed = 9500;
          //     play_vox("allkeys.raw");
          //     digital_speed = 11025;
          //   }
          //   cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'G':
          //   if (ck && cheat_ctr == 4)
          //     cheat_ctr++;
          //   level_jump = 0;
          //   new_key = 0;
          //   break;
          // case '0':
          // case '1':
          // case '2':
          // case '3':
          // case '4':
          // case '5':
          // case '6':
          // case '7':
          // case '8':
          // case '9':
          //   if (ck && cheat_ctr > 4)
          //   {
          //     if (cheat_ctr == 5)
          //     {
          //       level_jump = (new_key - '0');
          //       cheat_ctr++;
          //     }
          //     else
          //     {
          //       level_jump *= 10;
          //       level_jump += (new_key - '0');
          //       if (level_jump > 0 && level_jump <= 30)
          //       {
          //         level_num = level_jump;
          //         dead = 1;
          //         digital_speed = 9500;
          //         play_vox("allkeys.raw");
          //         digital_speed = 11025;
          //       }
          //       cheat_ctr = 0;
          //     }
          //   }
          //   else
          //     cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'E':
          //   if (ck && cheat_ctr == 4)
          //   {
          //     for (a = 0; a < 30; a++)
          //     {
          //       if (access_buf[a] >= 'A')
          //       {
          //         if (access_buf[a] == 'C')
          //         {
          //           curr_weapon = 0;
          //           weapon_list[0].qty = 50;
          //         }
          //         if (access_buf[a] == 'F')
          //           shield_level = 512;
          //         if (access_buf[a] == 'L')
          //           shield_level = 1024;
          //         b = access_buf[a] - 'A';
          //         access_buf[a] = ' ';
          //         digital_speed = 9500;
          //         play_vox("allkeys.raw");
          //         digital_speed = 11025;
          //         eq_gotit = 0;
          //         break;
          //       }
          //     }
          //   }
          //   cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'W':
          //   if (ck && cheat_ctr == 4)
          //   {
          //     weapon_list[0].qty += 500;
          //     weapon_list[1].qty += 500;
          //     weapon_list[3].qty += 500;
          //     digital_speed = 9500;
          //     play_vox("allkeys.raw");
          //     digital_speed = 11025;
          //   }
          //   cheat_ctr = 0;
          //   new_key = 0;
          //   break;
          // case 'J':
          //   calibrate_stick();
          //   new_key = 0;
          //   e++;
          //   break;
        }
      case SDLK_ESCAPE:
        if (ck)
        {
          main_menu_unload();
          menu_mode = 0;
          memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
          new_key = 0;
          return (0);
        }
        break;
      case SDLK_RETURN:
        switch (curr)
        {
        case 131: // New game
          main_menu_unload();
          b = difflvl();
          if (!b)
          {
            main_menu_load();
            e++;
          }
          else
          {
            //main_menu_unload();
            menu_mode = 0;
            level_num = 1;
            power_level = 1024;
            shield_level = 256;
            old_level_num = -1;
            memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
            diff_level_set = b;
            curr_weapon = -1;
            for (b = 0; b < 8; b++)
              weapon_list[b].qty = 0;
            rings = 0;
            //   123456789012345678901234567890
            strcpy(access_buf, "AB C  D  E F  G H I J K L  M  ");
            //AB C  D  E F  G H I J K L  M
            return (1);
          }
          break;
        case 132: // Load game
          main_menu_unload();
          b = save_load(1);
          if (b)
          {
            menu_mode = 0;
            old_level_num = -1;
            memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
            rings = 0;
            return (1);
          }
          else
            main_menu_load();
          e++;
          break;
        case 133: // Save game
          if (ck)
          {
            main_menu_unload();
            save_load(0);
            main_menu_load();
            e++;
          }
          break;
        case 134: // Options
          options_menu();
          e++;
          break;
        case 135: // Readme
          main_menu_unload();
          read_me();
          main_menu_load();
          e++;
          new_key = 0;
          break;
        case 136: // How to order
          main_menu_unload();
          how_to_order();
          main_menu_load();
          e++;
          new_key = 0;
          break;
        case 137: // Credits
          mn1_flap = 0;
          credits();
          e++;
          new_key = 0;
          break;
        case 138: // Run demo
          if (ck)
          {
            main_menu_unload();
            menu_mode = 0;
            memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
            return (2);
          }
          mn1_flap = 1;
          main_menu_unload();
          menu_mode = 0;

          demo_mode = 1;
          demo_ctr = 0;
          menu_mode = 0;

          power_level = 1024;
          shield_level = 256;
          old_level_num = -1;
          diff_level_set = 2;
          curr_weapon = 0;
          weapon_list[0].qty = 26;
          weapon_list[1].qty = 11;
          weapon_list[3].qty = 14;
          for (b = 0; b < 23; b++)
            demo[b].stat = 1;

          rings = 0;
          //   123456789012345678901234567890
          //strcpy(access_buf,"AB C  D  E F  G H I J K L  M  ");
          strcpy(access_buf, "                              ");
          //AB C  D  E F  G H I J K L  M
          //list_levels();

          level_num = 4;

          memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
          rings = 0;
          return (1);
          break;
        case 139: // Exit
          main_menu_unload();
          menu_mode = 0;
          memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
          return (2);
          break;
        }
        break;
      case SDLK_DOWN:
        curr++;
        if (curr > 139)
          curr = 131;
        if (ck && curr > 138)
          curr = 131;
        new_key = 0;
        e++;
        break;
      case SDLK_UP:
        curr--;
        if (curr < 131)
        {
          if (!ck)
            curr = 139;
          else
            curr = 138;
        }
        new_key = 0;
        e++;
        break;
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
  }
  return (0);
}

int
options_menu()
{
  int a, b, c, d, e, f, curr;
  b = 0;
  c = 0;
  d = 0;
  curr = 131;
  e = 0;
  f = 0;

  new_key = 0;
  main_menu_unload();
  options_menu_load();

  while (!c)
  {
    memcpy(vga_ram, double_buffer_l, SCREEN_BUFFER_SIZE);
    for (a = 131; a <= 133; a++)
    {
      if (a == curr)
        PCX_Show_Image(160, 50 * (a - 131) + 15, a, picture[a].width + 60);
      else
        PCX_Show_Image(160, 50 * (a - 131) + 15, a, picture[a].width);
    }
    switch (music_toggle)
    {
    case 0:
      PCX_Show_Image(160, 44, 141, picture[141].width);
      break;
    case 1:
      PCX_Show_Image(160, 44, 142, picture[142].width);
      break;
    case 2:
      PCX_Show_Image(160, 44, 143, picture[143].width);
      break;
    }
    switch (digi_flag)
    {
    case 0:
      PCX_Show_Image(160, 89, 141, picture[141].width);
      break;
    case 1:
      PCX_Show_Image(160, 89, 142, picture[142].width);
      break;
    case 2:
      PCX_Show_Image(160, 89, 143, picture[143].width);
      break;
    }
    switch (controls)
    {
    case 0:
      PCX_Show_Image(160, 141, 135, picture[135].width);
      break;
    case 1:
    case 2:
      PCX_Show_Image(160, 141, 137, picture[137].width);
      break;
    }

    render_frame();

    e = 0;
    while (!e)
    {
      update_keyboard_events();
      keyboard_event event = read_keyboard_event();

      switch (event.keycode)
      {
      case 'J':
        calibrate_stick();
        new_key = 0;
        e++;
        break;
      case SDLK_ESCAPE:
        options_menu_unload();
        main_menu_load();
        new_key = 0;
        return (0);
        break;
      case SDLK_RETURN:
        switch (curr)
        {
        case 131: // Music
          e++;
          if (music_toggle == 1)
            music_toggle = 2;
          else if (music_toggle == 2)
            music_toggle = 1;
          else
            e = 0;
          break;
        case 132: // Sound
          e++;
          if (digi_flag == 1)
            digi_flag = 2;
          else if (digi_flag == 2)
            digi_flag = 1;
          else
            e = 0;
          break;
        case 133: // Joystick
          if (controls == 2)
            controls = 0;
          else
          {
            controls = 2;
          }
          e++;
          break;
        }
        new_key = 0;
        break;
      case SDLK_DOWN:
        curr++;
        if (curr > 133)
          curr = 131;
        new_key = 0;
        e++;
        break;
      case SDLK_UP:
        curr--;
        if (curr < 131)
          curr = 133;
        new_key = 0;
        e++;
        break;
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
  }
  return (0);
}

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

  clear_screen(clr, SCREEN_BUFFER_SIZE);

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

  render_frame();

  c = 0;
  new_key = 0;
  while (!c)
  {
    update_keyboard_events();
    keyboard_event event = read_keyboard_event();

    if (event.keycode == SDLK_ESCAPE)
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
        render_frame();
        delay(250);
      }
    }
    else if (event.keycode == SDLK_RETURN)
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

      render_frame();
    }
    else if (!ready && event.keycode == SDLK_UP)
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
      render_frame();

      delay(150);
      new_key = 0;
    }
    else if (!ready && event.keycode == SDLK_DOWN)
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
      render_frame();
      
      delay(150);
      new_key = 0;
    }
    else if (ready && event.keycode == SDLK_BACKSPACE && entry[0] >= '0') //BackSpace
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
      render_frame();
      
      delay(150);
      new_key = 0;
    }
    else if (ready && isalnum(event.keycode))
    {
      for (a = 0; a < 14; a++)
      {
        if (!entry[a])
        {
          entry[a] = event.keycode;
          entry[a + 1] = 0;
          break;
        }
      }

      e = 13;
      Display2(160, pick * 14 + 50, 159);
      display_text(104, pick * 14 + 53, entry, 255);
      display_text(a * 8 + 112, pick * 14 + 53, "@", 255);
      render_frame();
      
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