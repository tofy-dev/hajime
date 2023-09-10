#include <cstdint>

namespace menu {
  void init();
  // Pointer to 'SDL_GL_SwapWindow' in the jump table.
  extern uintptr_t* swapwindow_ptr;

  // Address of the original 'SDL_GL_SwapWindow'.
  extern uintptr_t swapwindow_original;
}
