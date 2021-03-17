/**
 * @file input.c
 * 
 * @author jevarg
 * @brief SDL input
 */

#include "input.h"

void
update_input(keyboard_input* input)
{
  SDL_Event e;

  while (SDL_PollEvent(&e))
  {
    if (e.type != SDL_KEYDOWN)
    {
      continue;
    }

    input->keycode = e.key.keysym.sym;
    input->keymod = e.key.keysym.mod;

    printf("Pressed %d\n", input->keycode);
  }
}
