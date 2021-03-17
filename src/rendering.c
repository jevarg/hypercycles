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
