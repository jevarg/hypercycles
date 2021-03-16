#pragma once

#include <stdint.h>

// Functions

void play_again();
int play_song(char* song);
void free_buf();
void reset_buf();
void WaitEndMelo();
uint8_t* Read_Midi_File(char* file_name);
void Volume_OnOff(int flag);