#pragma once

#include <stdint.h>

/**
 * @brief  see midiplay.c
 * @param  tickQnote: ticks per quarter note
 * @param  usec: micro-seconds per quarter note
 */
void Set_Tempo(unsigned tickQnote, int32_t usec);

void Set_Original_Clock();
