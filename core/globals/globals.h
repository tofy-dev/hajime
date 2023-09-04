#include "source-sdk/c_glow_object_manager.h"
#include "source-sdk/i_base_client_dll.h"
#include "source-sdk/structs/structs.h"
#include <cstdint>

namespace globals {
  void init();
  extern CGlowObjectManager* g_GlowObjectManager;
  extern void* g_pClientMode;
}
