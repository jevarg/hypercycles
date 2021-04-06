// Builder for HyperCycles
// Builds level definitions

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include "io.h"
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "unistd_watcom.h"
#include "stdlib_watcom.h"
#include "conio.h"

#define UCHAR unsigned char
#define SHORT short int

static int level_num = 1;
static int total_level_def = 0;
bool g_debug_ignore_delay = false;

int ctr1 = 0;

struct __attribute__((__packed__)) level_def_struc
{
  unsigned char level_type;
  char description[26];
  char wall_map_fname[13];
  char floor_map_fname[13];
  char ceiling_map_fname[13];
  int x, y, view_angle;
  int exit_xmaze_sq, exit_ymaze_sq;
  char voice_intro_fname[13];
  char music_fname[13];
  char pcx_tile1_fname[13];
  char tile1_assign[16];
  char pcx_tile2_fname[13];
  char tile2_assign[16];
  char pcx_tile3_fname[13];
  char tile3_assign[16];
  char pcx_tile4_fname[13];
  char tile4_assign[16];
  int skycolor;
  int rings_req;
  int max_sim_riders;
  int max_tot_riders;
  int opt1, opt2, opt3, opt4, opt5, opt6, opt7, opt8;

} level_def;

struct __attribute__((__packed__)) obj_def
{
  int level_num;
  int image_num; // Which pic_num
  int map_letter;
  int x, y, xcell, ycell, view_angle; // Locations
  int xinc, yinc, xdest, ydest;
  int actx, acty, deactx, deacty; //squares that activate & deactivate object
  int objtype;
  int status;
  int opt1, opt2, opt3, opt4;
} object[152];

struct obj_def single;

int getns(char* str, int maxchars);
void set_vmode(int vmode);
void gotoxy(int row, int column);
void clrscrn(void);

void
clear_level_def()
{
  char* cptr;
  int a;
  cptr = (char*)&level_def;
  for (a = 0; a < sizeof(level_def); a++)
    cptr[a] = 0;
}

void
clear_object_def()
{
  char* cptr;
  int a, b;
  cptr = (char*)&object;
  b = sizeof(single);
  b = b * 150;
  for (a = 0; a < b; a++)
    cptr[a] = 0;
}

void
num_of_records()
{
  int handle;
  /* open a file & find # of records              */
  handle = open("level.def", O_RDONLY /* | O_BINARY */);
  if (handle != -1)
  {
    total_level_def = filelength(handle) / sizeof(level_def);
    close(handle);
  }
}

void
object_def_show(int a)
{
  clrscrn();
  printw("Level #%i  Object #%i\n", level_num, a + 1);
  printw(" Object Type > %i\n", object[a].objtype);
  printw("     Image # > %i\n", object[a].image_num);
  printw("  Map Letter > %i\n", object[a].map_letter);
  printw("           X > %i\n", object[a].x);
  printw("           Y > %i\n", object[a].y);
  printw("  View Angle > %i\n", object[a].view_angle);
  printw("      X Cell > %i\n", object[a].xcell);
  printw("      Y Cell > %i\n", object[a].ycell);
  printw(" X Increment > %i\n", object[a].xinc);
  printw(" Y Increment > %i\n", object[a].yinc);
  printw("X Dest. Cell > %i\n", object[a].xdest);
  printw("Y Dest. Cell > %i\n", object[a].ydest);
  printw("Activ X Cell > %i\n", object[a].actx);
  printw("Activ Y Cell > %i\n", object[a].acty);
  printw("DeAct X Cell > %i\n", object[a].deactx);
  printw("DeAct Y Cell > %i\n", object[a].deacty);
  printw("      Status > %i\n", object[a].status);
  printw("    Option 1 > %i\n", object[a].opt1);
  printw("    Option 2 > %i\n", object[a].opt2);
  printw("    Option 3 > %i\n", object[a].opt3);
  printw("    Option 4 > %i\n", object[a].opt4);
}

void
level_def_show()
{
  clrscrn();
  printw("Level #%i Definition\n", level_num);
  printw("Type (1=Grid 2=Rooms) > %i\n", level_def.level_type);
  printw("          Description > %s\n", level_def.description);
  printw("    Wall Map Filename > %s\n", level_def.wall_map_fname);
  printw("   Floor Map Filename > %s\n", level_def.floor_map_fname);
  printw(" Ceiling Map Filename > %s\n", level_def.ceiling_map_fname);
  printw("  Start X (Fine Grid) > %i\n", level_def.x);
  printw("  Start Y (Fine Grid) > %i\n", level_def.y);
  printw("  View Angle (0-4095) > %i\n", level_def.view_angle);
  printw("Exit X Maze Sqr. 0-63 > %i\n", level_def.exit_xmaze_sq);
  printw("Exit Y Maze Sqr. 0-63 > %i\n", level_def.exit_ymaze_sq);
  printw(" Voice Intro Filename > %s\n", level_def.voice_intro_fname);
  printw("Music (.MID) Filename > %s\n", level_def.music_fname);
  printw(" PCX Tile 1 Filename  > %s\n", level_def.pcx_tile1_fname);
  printw("      Tile 1 Assigns  > %s\n", level_def.tile1_assign);
  printw(" PCX Tile 2 Filename  > %s\n", level_def.pcx_tile2_fname);
  printw("      Tile 2 Assigns  > %s\n", level_def.tile2_assign);
  printw(" PCX Tile 3 Filename  > %s\n", level_def.pcx_tile3_fname);
  printw("      Tile 3 Assigns  > %s\n", level_def.tile3_assign);
  printw(" PCX Tile 4 Filename  > %s\n", level_def.pcx_tile4_fname);
  printw("      Tile 4 Assigns  > %s\n", level_def.tile4_assign);
  printw("            Sky Color > %i\n", level_def.skycolor);
  printw("            # of Keys > %i\n", level_def.rings_req);
  gotoxy(1, 40);
  printw("Max Simul Riders > %i\n", level_def.max_sim_riders);
  gotoxy(2, 40);
  printw("Max Total Riders > %i\n", level_def.max_tot_riders);
  gotoxy(3, 40);
  printw("        Option 1 > %i\n", level_def.opt1);
  gotoxy(4, 40);
  printw("        Option 2 > %i\n", level_def.opt2);
  gotoxy(5, 40);
  printw("        Option 3 > %i\n", level_def.opt3);
  gotoxy(6, 40);
  printw("        Option 4 > %i\n", level_def.opt4);
  gotoxy(7, 40);
  printw("        Option 5 > %i\n", level_def.opt5);
  gotoxy(8, 40);
  printw("        Option 6 > %i\n", level_def.opt6);
  gotoxy(9, 40);
  printw("        Option 7 > %i\n", level_def.opt7);
  gotoxy(10, 40);
  printw("        Option 8 > %i\n", level_def.opt8);
}

void
save_level_def()
{
  FILE* fp;

  if (level_num - 1 < total_level_def)
    fp = fopen("level.def", "rb+");
  else
    fp = fopen("level.def", "ab");
  if (fp != NULL)
  {
    if (level_num - 1 < total_level_def)
      fseek(fp, (level_num - 1) * sizeof(level_def), SEEK_SET);

    fwrite(&level_def, sizeof(level_def), 1, fp);
    fclose(fp);
    num_of_records();
  }
}

void
save_object_def()
{
  FILE *fp1, *fp2;
  int z1, z2, z3;

  z1 = rename("object.def", "temp.$$$");
  fp1 = fopen("object.def", "wb");

  if (!z1)
  {
    fp2 = fopen("temp.$$$", "rb");
    z2 = 0;
    while (!z2 && !feof(fp2))
    {
      fread(&single, sizeof(single), 1, fp2);
      if (!feof(fp2) && single.level_num < level_num)
        fwrite(&single, sizeof(single), 1, fp1);
      else
        z2++;
    }
  }

  for (z3 = 0; z3 < 100; z3++)
  {
    if (object[z3].objtype > 0)
    {
      object[z3].level_num = level_num;
      fwrite(&object[z3], sizeof(single), 1, fp1);
    }
  }

  if (!z1)
  {
    z2 = 0;
    while (!z2 && !feof(fp2))
    {
      fread(&single, sizeof(single), 1, fp2);
      if (!feof(fp2) && single.level_num > level_num)
        fwrite(&single, sizeof(single), 1, fp1);
    }
    fclose(fp2);
    remove("temp.$$$");
  }
  fclose(fp1);
}

void
load_object_def()
{
  FILE* fp1;
  int z2, z3;

  fp1 = fopen("object.def", "rb");

  if (fp1 == NULL)
    return;

  z2 = 0;
  while (!z2 && !feof(fp1))
  {
    fread(&object[0], sizeof(single), 1, fp1);
    if (object[0].level_num == level_num)
      z2++;
  }

  if (feof(fp1) || object[0].level_num != level_num)
  {
    char* cptr;
    int a;
    cptr = (char*)&object[0];
    for (a = 0; a < sizeof(single); a++)
      cptr[a] = 0;
    fclose(fp1);
    return;
  }

  for (z3 = 1; z3 < 100; z3++)
  {
    if (feof(fp1))
    {
      fclose(fp1);
      return;
    }
    fread(&object[z3], sizeof(single), 1, fp1);
    if (!feof(fp1) && object[z3].objtype > 0)
    {
      if (object[z3].level_num != level_num)
      {
        char* cptr;
        int a;
        cptr = (char*)&object[z3];
        for (a = 0; a < sizeof(single); a++)
          cptr[a] = 0;
        fclose(fp1);
        return;
      }
    }
  }
}

void
object_def_edit()
{
  char inpbuf[80];
  int a, f;
  ctr1 = 0;
  f = 0;
  if (level_num > total_level_def)
    clear_object_def();
  object_def_show(f);
  while (1)
  {
    switch (ctr1)
    {
    case 0:
      itoa(object[f].objtype, inpbuf, 10);
      gotoxy(1, 15);
      a = getns(inpbuf, 5);
      object[f].objtype = atoi(inpbuf);
      break;
    case 1:
      itoa(object[f].image_num, inpbuf, 10);
      gotoxy(2, 15);
      a = getns(inpbuf, 5);
      object[f].image_num = atoi(inpbuf);
      break;
    case 2:
      itoa(object[f].map_letter, inpbuf, 10);
      gotoxy(3, 15);
      a = getns(inpbuf, 5);
      object[f].map_letter = atoi(inpbuf);
      break;
    case 3:
      itoa(object[f].x, inpbuf, 10);
      gotoxy(4, 15);
      a = getns(inpbuf, 5);
      object[f].x = atoi(inpbuf);
      break;
    case 4:
      itoa(object[f].y, inpbuf, 10);
      gotoxy(5, 15);
      a = getns(inpbuf, 5);
      object[f].y = atoi(inpbuf);
      break;
    case 5:
      itoa(object[f].view_angle, inpbuf, 10);
      gotoxy(6, 15);
      a = getns(inpbuf, 5);
      object[f].view_angle = atoi(inpbuf);
      break;
    case 6:
      itoa(object[f].xcell, inpbuf, 10);
      gotoxy(7, 15);
      a = getns(inpbuf, 5);
      object[f].xcell = atoi(inpbuf);
      object[f].x = object[f].xcell * 64 + 32;
      break;
    case 7:
      itoa(object[f].ycell, inpbuf, 10);
      gotoxy(8, 15);
      a = getns(inpbuf, 5);
      object[f].ycell = atoi(inpbuf);
      object[f].y = object[f].ycell * 64 + 32;
      break;
    case 8:
      itoa(object[f].xinc, inpbuf, 10);
      gotoxy(9, 15);
      a = getns(inpbuf, 5);
      object[f].xinc = atoi(inpbuf);
      break;
    case 9:
      itoa(object[f].yinc, inpbuf, 10);
      gotoxy(10, 15);
      a = getns(inpbuf, 5);
      object[f].yinc = atoi(inpbuf);
      break;
    case 10:
      itoa(object[f].xdest, inpbuf, 10);
      gotoxy(11, 15);
      a = getns(inpbuf, 5);
      object[f].xdest = atoi(inpbuf);
      break;
    case 11:
      itoa(object[f].ydest, inpbuf, 10);
      gotoxy(12, 15);
      a = getns(inpbuf, 5);
      object[f].ydest = atoi(inpbuf);
      break;
    case 12:
      itoa(object[f].actx, inpbuf, 10);
      gotoxy(13, 15);
      a = getns(inpbuf, 5);
      object[f].actx = atoi(inpbuf);
      break;
    case 13:
      itoa(object[f].acty, inpbuf, 10);
      gotoxy(14, 15);
      a = getns(inpbuf, 5);
      object[f].acty = atoi(inpbuf);
      break;
    case 14:
      itoa(object[f].deactx, inpbuf, 10);
      gotoxy(15, 15);
      a = getns(inpbuf, 5);
      object[f].deactx = atoi(inpbuf);
      break;
    case 15:
      itoa(object[f].deacty, inpbuf, 10);
      gotoxy(16, 15);
      a = getns(inpbuf, 5);
      object[f].deacty = atoi(inpbuf);
      break;
    case 16:
      itoa(object[f].status, inpbuf, 10);
      gotoxy(17, 15);
      a = getns(inpbuf, 5);
      object[f].status = atoi(inpbuf);
      break;
    case 17:
      itoa(object[f].opt1, inpbuf, 10);
      gotoxy(18, 15);
      a = getns(inpbuf, 5);
      object[f].opt1 = atoi(inpbuf);
      break;
    case 18:
      itoa(object[f].opt2, inpbuf, 10);
      gotoxy(19, 15);
      a = getns(inpbuf, 5);
      object[f].opt2 = atoi(inpbuf);
      break;
    case 19:
      itoa(object[f].opt3, inpbuf, 10);
      gotoxy(20, 15);
      a = getns(inpbuf, 5);
      object[f].opt3 = atoi(inpbuf);
      break;
    case 20:
      itoa(object[f].opt4, inpbuf, 10);
      gotoxy(21, 15);
      a = getns(inpbuf, 5);
      object[f].opt4 = atoi(inpbuf);
      break;
    }
    if (!a)
      ctr1++;
    if (a == 3) //pageup
    {
      if (f > 0)
        f--;
      else
        ctr1--;
    }
    if (a == 4) //pagedwn
    {
      if (f < 100)
        f++;
      else
        ctr1++;
    }
    if (a == 2)
      ctr1--;
    if (a == 2)
      ctr1--;
    if (ctr1 < 0)
      ctr1 = 20;
    if (ctr1 > 20)
      ctr1 = 0;
    if (a == 1)
    {
      gotoxy(20, 20);
      printw("Save Entry(s) - Confirmation ([Y]/N) ?");
      a = getche();
      if (a == 'Y' || a == 'y' || a == 13)
        save_object_def();

      return;
    }
    object_def_show(f);
  }
}

void
load_level_def()
{
  FILE* fp;
  int a, b;

  a = (level_num - 1) * sizeof(level_def);
  b = sizeof(level_def);
  fp = fopen("level.def", "rb");
  if (fp != NULL)
  {
    fseek(fp, a, SEEK_SET);
    fread(&level_def, b, 1, fp);
    fclose(fp);
  }
}

void
level_def_edit()
{
  char inpbuf[80];
  int a;
  ctr1 = 0;
  if (level_num > total_level_def)
    clear_level_def();
  level_def_show();
  while (1)
  {
    switch (ctr1)
    {
    case 0:
      itoa(level_def.level_type, inpbuf, 10);
      gotoxy(1, 24);
      a = getns(inpbuf, 5);
      level_def.level_type = atoi(inpbuf);
      break;
    case 1:
      gotoxy(2, 24);
      a = getns(level_def.description, 25);
      break;
    case 2:
      gotoxy(3, 24);
      a = getns(level_def.wall_map_fname, 12);
      break;
    case 3:
      gotoxy(4, 24);
      a = getns(level_def.floor_map_fname, 12);
      break;
    case 4:
      gotoxy(5, 24);
      a = getns(level_def.ceiling_map_fname, 12);
      break;
    case 5:
      itoa(level_def.x, inpbuf, 10);
      gotoxy(6, 24);
      a = getns(inpbuf, 5);
      level_def.x = atoi(inpbuf);
      break;
    case 6:
      itoa(level_def.y, inpbuf, 10);
      gotoxy(7, 24);
      a = getns(inpbuf, 5);
      level_def.y = atoi(inpbuf);
      break;
    case 7:
      itoa(level_def.view_angle, inpbuf, 10);
      gotoxy(8, 24);
      a = getns(inpbuf, 5);
      level_def.view_angle = atoi(inpbuf);
      break;
    case 8:
      itoa(level_def.exit_xmaze_sq, inpbuf, 10);
      gotoxy(9, 24);
      a = getns(inpbuf, 5);
      level_def.exit_xmaze_sq = atoi(inpbuf);
      break;
    case 9:
      itoa(level_def.exit_ymaze_sq, inpbuf, 10);
      gotoxy(10, 24);
      a = getns(inpbuf, 5);
      level_def.exit_ymaze_sq = atoi(inpbuf);
      break;
    case 10:
      gotoxy(11, 24);
      a = getns(level_def.voice_intro_fname, 12);
      break;
    case 11:
      gotoxy(12, 24);
      a = getns(level_def.music_fname, 12);
      break;
    case 12:
      gotoxy(13, 24);
      a = getns(level_def.pcx_tile1_fname, 12);
      break;
    case 13:
      gotoxy(14, 24);
      a = getns(level_def.tile1_assign, 15);
      break;
    case 14:
      gotoxy(15, 24);
      a = getns(level_def.pcx_tile2_fname, 12);
      break;
    case 15:
      gotoxy(16, 24);
      a = getns(level_def.tile2_assign, 15);
      break;
    case 16:
      gotoxy(17, 24);
      a = getns(level_def.pcx_tile3_fname, 12);
      break;
    case 17:
      gotoxy(18, 24);
      a = getns(level_def.tile3_assign, 15);
      break;
    case 18:
      gotoxy(19, 24);
      a = getns(level_def.pcx_tile4_fname, 12);
      break;
    case 19:
      gotoxy(20, 24);
      a = getns(level_def.tile4_assign, 15);
      break;
    case 20:
      itoa(level_def.skycolor, inpbuf, 10);
      gotoxy(21, 24);
      a = getns(inpbuf, 5);
      level_def.skycolor = atoi(inpbuf);
      break;
    case 21:
      itoa(level_def.rings_req, inpbuf, 10);
      gotoxy(22, 24);
      a = getns(inpbuf, 5);
      level_def.rings_req = atoi(inpbuf);
      break;
    case 22:
      itoa(level_def.max_sim_riders, inpbuf, 10);
      gotoxy(1, 59);
      a = getns(inpbuf, 5);
      level_def.max_sim_riders = atoi(inpbuf);
      break;
    case 23:
      itoa(level_def.max_tot_riders, inpbuf, 10);
      gotoxy(2, 59);
      a = getns(inpbuf, 5);
      level_def.max_tot_riders = atoi(inpbuf);
      break;
    case 24:
      itoa(level_def.opt1, inpbuf, 10);
      gotoxy(3, 59);
      a = getns(inpbuf, 5);
      level_def.opt1 = atoi(inpbuf);
      break;
    case 25:
      itoa(level_def.opt2, inpbuf, 10);
      gotoxy(4, 59);
      a = getns(inpbuf, 5);
      level_def.opt2 = atoi(inpbuf);
      break;
    case 26:
      itoa(level_def.opt3, inpbuf, 10);
      gotoxy(5, 59);
      a = getns(inpbuf, 5);
      level_def.opt3 = atoi(inpbuf);
      break;
    case 27:
      itoa(level_def.opt4, inpbuf, 10);
      gotoxy(6, 59);
      a = getns(inpbuf, 5);
      level_def.opt4 = atoi(inpbuf);
      break;
    case 28:
      itoa(level_def.opt5, inpbuf, 10);
      gotoxy(7, 59);
      a = getns(inpbuf, 5);
      level_def.opt5 = atoi(inpbuf);
      break;
    case 29:
      itoa(level_def.opt6, inpbuf, 10);
      gotoxy(8, 59);
      a = getns(inpbuf, 5);
      level_def.opt6 = atoi(inpbuf);
      break;
    case 30:
      itoa(level_def.opt7, inpbuf, 10);
      gotoxy(9, 59);
      a = getns(inpbuf, 5);
      level_def.opt7 = atoi(inpbuf);
      break;
    case 31:
      itoa(level_def.opt8, inpbuf, 10);
      gotoxy(10, 59);
      a = getns(inpbuf, 5);
      level_def.opt8 = atoi(inpbuf);
      break;
    }
    if (!a)
      ctr1++;
    if (a == 3)
      ctr1 = 0; //pageup
    if (a == 4)
      ctr1 = 31; //pagedwn
    if (a == 2)
      ctr1--;
    if (ctr1 < 0)
      ctr1 = 31;
    if (ctr1 > 31)
      ctr1 = 0;
    if (a == 1)
    {
      gotoxy(23, 20);
      printw("Save Entry - Confirmation ([Y]/N) ?");
      a = getche();
      if (a == 'Y' || a == 'y' || a == 13)
        save_level_def();

      return;
    }
    level_def_show();
  }
}

void
mainmenu(void)
{
  int a, mmloop;
  char inpbuf[80];

  if (total_level_def > 0)
  {
    load_level_def();
    load_object_def();
  }

  while (1)
  {
    clrscrn();
    gotoxy(0, 11);
    printw("HyperCycles Level Builder - (c) 1995 Aclypse Corporation ");
    gotoxy(1, 11);
    printw("             For Aclypse Internal Use Only");

    gotoxy(3, 11);
    printw("      ***************** Main Menu *****************");
    gotoxy(5, 32);
    printw("<<< Level # %i of %i %i>>>", level_num, total_level_def, sizeof(single));
    gotoxy(7, 20);
    printw("  1 - Level Definitions");
    gotoxy(9, 20);
    printw("  2 - Object Definitions for Levels");
    gotoxy(11, 20);
    printw("  S - Select Level");
    gotoxy(12, 20);
    printw("  A - Add Level");
    gotoxy(13, 20);
    printw("  C - Clear Object Definitions");
    gotoxy(15, 20);
    printw("  X - Exit");

    mmloop = 0;
    while (!mmloop)
    {
      gotoxy(17, 20);
      printw("  Enter Selection -->        ");
      gotoxy(17, 41);
      a = getche();
      switch (a)
      {
      case '1':
        level_def_edit();
        mmloop++;
        break;
      case '2':
        object_def_edit();
        mmloop++;
        break;
      case 'A':
      case 'a':
        total_level_def++;
        level_num = total_level_def;
        clear_level_def();
        clear_object_def();
        level_def.level_type = 1;
        strcpy(level_def.music_fname, "RMH2001.MDI");
        strcpy(level_def.pcx_tile1_fname, "PANELS1.PCX");
        strcpy(level_def.tile1_assign, "abcdefghijklm  ");
        strcpy(level_def.pcx_tile2_fname, "PANELS2.PCX");
        strcpy(level_def.tile2_assign, "BCZEA Q   P Y T");
        strcpy(level_def.pcx_tile3_fname, "PANELS4.PCX");
        strcpy(level_def.tile3_assign, " D             ");
        level_def_edit();
        mmloop++;
        break;
      case 'S':
      case 's':
        gotoxy(19, 20);
        printw("Enter Level # > ");
        inpbuf[0] = 0;
        getns(inpbuf, 4);
        a = atoi(inpbuf);
        if (a > 0 && a <= total_level_def)
        {
          level_num = a;
          clear_level_def();
          load_level_def();
          clear_object_def();
          load_object_def();
        }
        mmloop++;
        break;
      case 'X':
      case 'x':
        gotoxy(19, 20);
        printw("Exit Confirmation (Y/N) ?");
        a = getche();
        if (a == 'Y' || a == 'y')
          return;
        mmloop++;
        break;
      case 'C':
      case 'c':
        gotoxy(19, 20);
        printw("Clear Confirmation (Y/N) ?");
        a = getche();
        if (a == 'Y' || a == 'y')
        {
          clear_level_def();
          clear_object_def();
        }
        mmloop++;
        break;
      }
    }
  }
}

int
main()
{
  initscr();
  cbreak();
  noecho();

  num_of_records();
  clrscrn();
  clear_level_def();
  clear_object_def();
  level_num = 1;
  mainmenu();

  endwin();

  return 0;
}
