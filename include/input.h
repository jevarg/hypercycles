#pragma once

#include <SDL2/SDL_events.h>

// Structures

typedef struct keyboard_input
{
  SDL_Keycode keycode;
  SDL_Keymod keymod;
} keyboard_input;

// Functions

void update_input(keyboard_input* input);