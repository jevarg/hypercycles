#include "rendering.h"
#include "window.h"

void
render_frame()
{
  SDL_Texture* buffer_texture = SDL_CreateTextureFromSurface(ui_components.renderer, ui_components.video_buffer);

  SDL_RenderClear(ui_components.renderer);
  SDL_RenderCopy(ui_components.renderer, buffer_texture, 0, 0);
  SDL_RenderPresent(ui_components.renderer);

  SDL_DestroyTexture(buffer_texture);
}