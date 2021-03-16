#pragma once

/**
 * @defgroup structures
 * @{
 */

/**
 * @brief 
 * 
 */
struct __attribute__((__packed__)) pic_def
{
  unsigned int* image;
  int width;
  int height;
  int ratio;
} picture[192];

/** @} */ // end of structures group