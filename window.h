#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

struct ui_components
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* video_buffer;
} ui_components;

bool initialize_ui();
void free_ui();