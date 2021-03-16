/**
 * @file audio.c
 * 
 * @author jevarg
 * @brief Audio, music and sfx
 */

#include "audio.h"
#include "midiplay.h"

char musRunning;
char music_toggle = 2;
unsigned char music_cnt = 4;
unsigned char next_song[15];
unsigned char curr_song[15];

void
cont_music()
{
  
  if (!musRunning && music_toggle == 2)
  {
    if (music_cnt == 4)
    {
      play_again();
      music_cnt--;
    }
  }
  if (music_toggle == 2 && music_cnt < 4)
  {
    music_cnt--;
    if (!music_cnt)
    {
      if (next_song[0])
      {
        play_song(next_song);
        strcpy(curr_song, next_song);
        next_song[0] = 0;
      }
      else
        play_again();
      music_cnt = 4;
    }
  }
}