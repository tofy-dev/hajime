#include <cstdint>

namespace menu {
  void init();
  void destroy();

  // Pointer to 'SDL_GL_SwapWindow' in the jump table.
  extern uintptr_t* swapwindow_ptr;

  // Address of the original 'SDL_GL_SwapWindow'.
  extern uintptr_t swapwindow_original;
}
