#include <cstdint>
#include "globals.h"
#include "source-sdk/c_glow_object_manager.h"
#include "utils/memory/memory.h"

void globals::init() {
  std::uintptr_t pat;

  pat = memory::find_pattern("tf/bin/client.so", "\xC7\x04\x24\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x10\x89\xD8\x5B\x5E\x5D\xC3\x8D\xB6\x00\x00\x00\x00", "xxx????x????xxxxxxxxxxxxxxx");
  g_GlowObjectManager = *reinterpret_cast<CGlowObjectManager**>(pat+3);
}

namespace globals {
  CGlowObjectManager* g_GlowObjectManager = nullptr;
}
