#pragma once


/**
 * @brief  see midiplay.c
 * @param  tickQnote: ticks per quarter note
 * @param  usec: micro-seconds per quarter note
 */
void Set_Tempo(unsigned tickQnote, long usec);

void Set_Original_Clock();