#include "screen.h"
#include "window.h"

#include <error.h>

void
free_ui()
{
    SDL_FreeSurface(ui_components.video_buffer);
    SDL_DestroyRenderer(ui_components.renderer);

    if (ui_components.window)
    {
        SDL_DestroyWindow(ui_components.window);
        ui_components.window = 0;
    }

    ui_components.video_buffer = 0;
    ui_components.renderer = 0;

    SDL_Quit();
}

bool
initialize_ui()
{
    SDL_Init(SDL_INIT_VIDEO);

    ui_components.window = SDL_CreateWindow("Hypercycles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    if (!ui_components.window)
    {
        error(0, 0, "Could not create SDL_Window window: %s", SDL_GetError());
        return false;
    }

    ui_components.renderer = SDL_CreateRenderer(ui_components.window, -1, 0);
    if (!ui_components.renderer)
    {
        error(0, 0, "Could not create SDL_renderer renderer: %s", SDL_GetError());
        return false;
    }

    ui_components.video_buffer = SDL_CreateRGBSurfaceWithFormat(0, SCREEN_WIDTH, SCREEN_HEIGHT, 1, SDL_PIXELFORMAT_INDEX8);
    if (!ui_components.video_buffer)
    {
        error(0, 0, "Could not create SDL_Surface video_buffer: %s", SDL_GetError());
        return false;
    }

    return true;
}