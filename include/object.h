#pragma once

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

struct __attribute__((__packed__)) obj_def single;