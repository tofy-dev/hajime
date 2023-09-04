#include <cstdint>
#include <sys/types.h>
#include "globals.h"
#include "hooks/vmt_hook.h"
#include "source-sdk/c_glow_object_manager.h"
#include "source-sdk/i_base_client_dll.h"
#include "utils/memory/memory.h"
#include "utils/logger.h"
#include "interfaces/interfaces.h"

void globals::init() {
  std::uintptr_t pat;

  using logger::ofs;

  pat = memory::find_pattern("tf/bin/client.so", "\xC7\x04\x24\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x10\x89\xD8\x5B\x5E\x5D\xC3\x8D\xB6\x00\x00\x00\x00", "xxx????x????xxxxxxxxxxxxxxx");
  g_GlowObjectManager = *reinterpret_cast<CGlowObjectManager**>(pat+3);

  pat = memory::find_pattern("tf/bin/client.so", "\xA1\x00\x00\x00\x00\x55\x89\xE5\x0F\xB6\x4D\x0C\x8B\x10\x89\x45\x08\x89\x4D\x0C\x5D\x8B\x42\x2C", "x????xxxxxxxxxxxxxxxxxxx");
  g_pClientMode = *reinterpret_cast<void**>(pat+1);
};

namespace globals {
  CGlowObjectManager* g_GlowObjectManager = nullptr;
  void* g_pClientMode = nullptr;
}
