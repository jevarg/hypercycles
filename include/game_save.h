#pragma once

// Globals

extern int level_num;
extern short int diff_level_set;
extern int score;
extern int power_level;
extern int shield_level;
extern unsigned char access_buf[44];

// Structures

struct __attribute__((__packed__)) save_game_struc
{
  unsigned char games[15];
  int level;
  int diff;
  int score;
  int power;
  int shields;
  char access[32];
  int protons;
  int neutrons;
  int darts;
  int chksum;
} game_data[10];

struct __attribute__((__packed__)) save_game_struc gm_one;

// Functions

int save_game(int slot);
int load_gamefile();