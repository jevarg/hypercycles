/**
 * @file input.c
 * 
 * @author jevarg
 * @brief SDL input
 */

#include "input.h"

static keyboard_event event = { .keycode = 0, .keymod = 0 };

void
update_keyboard_events()
{
  SDL_Event e;

  while (SDL_PollEvent(&e))
  {
    if (e.type != SDL_KEYDOWN)
    {
      continue;
    }

    event.keycode = e.key.keysym.sym;
    event.keymod = e.key.keysym.mod;
  }
}

const keyboard_event
read_keyboard_event()
{
  keyboard_event event_copy = event;
  
  event.keycode = 0;
  event.keymod = 0;
  
  return event_copy;
}