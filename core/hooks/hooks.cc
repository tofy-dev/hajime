#include "hooks.h"
#include "altvmt.h"
#include "implements/implementations.h"
#include "interfaces/interfaces.h"
#include "utils/logger.h"

#include <cstdint>
#include <functional>
#include <cassert>

using logger::ofs;
void hooks::init() {
  *ofs << "Creating vmts..." << std::endl;
  panel_vmt = new altvmt(interfaces::panel);
  client_vmt = new altvmt(interfaces::client);

  *ofs << "Creating hooks..." << std::endl;
  hooks::create_hook(hooks::panel_vmt, 42, (void*)&implementations::hooked_paint_traverse);
}

void hooks::reset() {
  *ofs << "Reseting hooks..." << std::endl;
  *ofs << "Deleting panel_vmt..." << std::endl;
  delete panel_vmt;
  *ofs << "Deleting client_vmt..." << std::endl;
  delete client_vmt;
}

void hooks::create_hook(altvmt *vmt, int index, void* func) {
  *ofs << "hooking function at index " << index << "..." << std::endl;
  vmt->fake[index] = func;
  *ofs << "hook successful." << std::endl;
}

namespace hooks {
  altvmt *panel_vmt = nullptr;
  altvmt *client_vmt = nullptr;
  altvmt *clientmode_vmt = nullptr;
}
