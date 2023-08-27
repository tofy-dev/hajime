#include "hooks.h"
#include "altvmt.h"
#include "implements/implementations.h"
#include "interfaces/interfaces.h"
#include "utils/logger.h"

#include <functional>
#include <cassert>

void hooks::init() {
  using logger::ofs;

  *ofs << "Creating vmts..." << std::endl;
  panel_vmt = new altvmt(interfaces::panel);
  clientmode_vmt = new altvmt((void*)(interfaces::client_addr+0x2061f60));

  *ofs << "Creating hooks..." << std::endl;
  hooks::create_hook(hooks::panel_vmt, 42, (void*)&implementations::hooked_paint_traverse);
}

void hooks::create_hook(altvmt *vmt, int index, void* func) {
  using logger::ofs;

  *ofs << "hooking function at index " << index << "..." << std::endl;
  vmt->fake[index] = func;
  *ofs << "hook successful." << std::endl;
}

namespace hooks {
  altvmt *panel_vmt = nullptr;
  altvmt *clientmode_vmt = nullptr;
}
