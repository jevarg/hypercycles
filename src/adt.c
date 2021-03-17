/**
 * @file adt.c
 * 
 * @brief ADT2 File Builders
 */

#include "adt.h"

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int GFL2 = 0;
int GFL1B = 0;

int
adt1_init()
{
  FILE* fp1;
  int a, b;

  if (!(fp1 = fopen("assets/hyper1r.adt", "rb")))
    return (1);

  for (a = 0; a < 135; a++)
  {
    fread(&adt1[a], sizeof(adt_single), 1, fp1);
    if (adt1[a].fname[0] == '*')
      break;
    else
    {
      b = 0;
      while (adt1[a].fname[b])
      {
        adt1[a].fname[b] = ~adt1[a].fname[b];
        b++;
      }
    }
  }

  fclose(fp1);
  return (0);
}

int
adt2_init()
{
  FILE* fp1;
  int a, b;

  if (!(fp1 = fopen("assets/hyper2r.adt", "rb")))
    return (1);

  for (a = 0; a < 120; a++)
  {
    fread(&adt2[a], sizeof(adt_single), 1, fp1);
    if (adt2[a].fname[0] == '*')
      break;
    else
    {
      b = 0;
      while (adt2[a].fname[b])
      {
        adt2[a].fname[b] = ~adt2[a].fname[b];
        b++;
      }
    }
  }
  fclose(fp1);
  return (0);
}

int
open_adt1(unsigned char* fname, bool is_binary)
{
  int fpf = 0;
  int a = 0;
  int b = 0;
  unsigned char fn2[20];

  strcpy(fn2, fname);
  strupr(fn2);

  for (a = 0; a < 135; a++)
  {

    if (adt1[a].fname[0] == '*')
      break;

    if (fn2[0] == adt1[a].fname[0])
    {
      if (!strcmp(fn2, adt1[a].fname))
      {
        b++;
        break;
      }
    }
  }
  if (!b)
    return (-1);

  int start = adt1[a].start;
  GFL1B = start + adt1[a].length - 768;

  fpf = open("assets/hyper1r.adt", O_RDONLY);
  if (fpf == -1)
  {
    return (-1);
  }

  a = lseek(fpf, start, SEEK_SET);
  if (a < 0)
  {
    return (-1);
  }

  return (fpf);
}

int
open_adt2(unsigned char* fname)
{
  int fpf = 0;
  int a = 0;
  int b = 0;
  int start = 0;

  unsigned char fn2[20];

  strcpy(fn2, fname);
  strupr(fn2);

  for (a = 0; a < 120; a++)
  {

    if (adt2[a].fname[0] == '*')
      break;

    if (fn2[0] == adt2[a].fname[0])
    {
      if (!strcmp(fn2, adt2[a].fname))
      {
        b++;
        break;
      }
    }
  }
  if (!b)
    return (-1);

  GFL2 = adt2[a].length;
  start = adt2[a].start;

  fpf = open("assets/hyper2r.adt", O_RDONLY);
  if (fpf == -1)
  {
    return (-1);
  }

  a = lseek(fpf, start, SEEK_SET);
  if (a < 0)
  {
    return (-2);
  }

  return (fpf);
}
