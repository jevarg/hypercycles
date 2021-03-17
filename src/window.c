#include "screen.h"
#include "window.h"
#include "debug.h"

ui_components ui = { 0 };

void
free_ui()
{
  SDL_FreeSurface(ui.video_buffer);
  SDL_DestroyRenderer(ui.renderer);

  if (ui.window)
  {
    SDL_DestroyWindow(ui.window);
    ui.window = 0;
  }

  ui.video_buffer = 0;
  ui.renderer = 0;

  SDL_Quit();
}

bool
initialize_ui()
{
  SDL_Init(SDL_INIT_VIDEO);

  ui.window = SDL_CreateWindow("Hypercycles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
  if (!ui.window)
  {
    error(0, 0, "Could not create SDL_Window window: %s\n", SDL_GetError());
    return false;
  }

  ui.renderer = SDL_CreateRenderer(ui.window, -1, 0);
  if (!ui.renderer)
  {
    error(0, 0, "Could not create SDL_renderer renderer: %s\n", SDL_GetError());
    return false;
  }

  ui.video_buffer = SDL_CreateRGBSurfaceWithFormat(0, SCREEN_WIDTH, SCREEN_HEIGHT, 1, SDL_PIXELFORMAT_INDEX8);
  if (!ui.video_buffer)
  {
    error(0, 0, "Could not create SDL_Surface video_buffer: %s\n", SDL_GetError());
    return false;
  }

  if (SDL_SetRenderDrawColor(ui.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) == -1)
  {
    error(0, 0, "Could not set Renderer draw color: %s\n", SDL_GetError());
    return false;
  }

  return true;
}
