#pragma once

// Structures

struct __attribute__((__packed__)) weap_str
{
  short int eq;
  short int qty;
  char item[36];

};

// Globals

extern struct weap_str weapon_list[];