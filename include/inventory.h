#pragma once

struct __attribute__((__packed__)) equip_str
{
  char item[32];
};

extern struct equip_str equipment[];