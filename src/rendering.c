/**
 * @file rendering.c
 * 
 * @author jevarg
 * @brief SDL Rendering related
 */

#include "rendering.h"
#include "window.h"

void
render_frame()
{
  SDL_Texture* buffer_texture = SDL_CreateTextureFromSurface(ui.renderer, ui.video_buffer);

  SDL_RenderClear(ui.renderer);
  SDL_RenderCopy(ui.renderer, buffer_texture, 0, 0);
  SDL_RenderPresent(ui.renderer);

  SDL_DestroyTexture(buffer_texture);
}

void
clear_screen(int palette_index, size_t n)
{
  SDL_memset(ui.video_buffer->pixels, palette_index, n);
}