#pragma once

// Globals

extern char controls;
extern char music_toggle;
extern char digi_flag;

// Structures

struct __attribute__((__packed__)) setup_struc
{
  short int screen_size;
  short int port;
  short int intr_num;
  short int dma_num;
  short int music_addr;
  short int mct;
  short int sct;
  short int contr;
  short int left;
  short int right;
  short int top;
  short int bottom;
  short int switch_buttons;
} hc_setup;

// Functions

void save_config();
int load_config();