#pragma once

// Structures

/**
 * @brief Picture (texture) code definition
 */
struct __attribute__((__packed__)) pic_def
{
  unsigned int* image;
  int width;
  int height;
  int ratio;
};

// Globals

extern struct pic_def picture[192];