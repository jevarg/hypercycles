#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct ui_components ui_components;
struct ui_components
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* video_buffer;
};

extern ui_components ui;

bool initialize_ui();
void free_ui();
