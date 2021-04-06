#pragma once

#include <SDL2/SDL_events.h>

// Structures

typedef struct keyboard_event
{
  SDL_Keycode keycode;
  SDL_Keymod keymod;
} keyboard_event;

// Functions

void update_keyboard_events();
const keyboard_event read_keyboard_event();