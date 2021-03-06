#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

// Structures

typedef struct ui_components
{
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* video_buffer;
} ui_components;

// Globals

extern ui_components ui;

// Functions

bool initialize_ui();
void free_ui();
