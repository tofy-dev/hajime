#pragma once
#include <cstdint>
#include <SDL2/SDL.h>

namespace menu {
  void init();
  void reset();
  void swap_window(SDL_Window* window);

  // Pointer to 'SDL_GL_SwapWindow' in the jump table.
  extern uintptr_t* swapwindow_ptr;
  // Address of the original 'SDL_GL_SwapWindow'.
  extern uintptr_t swapwindow_original;

  extern SDL_GLContext user_context;
  extern SDL_Window* window;
}
