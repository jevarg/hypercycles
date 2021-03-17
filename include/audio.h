#pragma once

// Globals

extern char musRunning; /**< != 0 if music is playing */
extern char music_toggle;
extern unsigned char music_cnt;
extern unsigned char next_song[15];
extern unsigned char curr_song[15];

// Functions

void cont_music();