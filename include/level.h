#pragma once

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