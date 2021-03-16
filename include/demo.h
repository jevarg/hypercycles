#pragma once

// Structures 

struct __attribute__((__packed__)) demo_str
{
  int xc, yc;
  int speed;
  int side_mode;
  int curr_weapon;
  int command;
  int stat;
};

// Globals

extern struct demo_str demo[];