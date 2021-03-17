/**
 * @file config.c
 * 
 * @author jevarg
 * @brief Game configuration
 */

#include "config.h"
#include "hyper6.h"
#include "ctv.h"

#include <stdio.h>

#define CONFIG_FILE_PATH "hyper.cfg"

void
save_config()
{
  FILE* fp;

  fp = fopen(CONFIG_FILE_PATH, "wb+");
  if (fp != NULL)
  {
    fwrite(&hc_setup, sizeof(hc_setup), 1, fp);
    fclose(fp);
  }
}

int
load_config()
{
  FILE* fp1;

  fp1 = fopen(CONFIG_FILE_PATH, "rb");

  if (fp1 == NULL)
    return (0);

  fread(&hc_setup, sizeof(hc_setup), 1, fp1);
  fclose(fp1);

  DMA_Channel = hc_setup.dma_num;
  intr_num = hc_setup.intr_num;
  io_addr = hc_setup.port;
  Music_Address = hc_setup.music_addr;

  controls = hc_setup.contr;

  if (hc_setup.mct)
    music_toggle = 2;
  else
    music_toggle = 0;

  if (hc_setup.sct)
    digi_flag = 2;
  else
    digi_flag = 0;
  return (1);
}