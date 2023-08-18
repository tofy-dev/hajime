#include "hooks.h"
#include "altvmt.h"
#include "implements/paint_traverse.h"
#include "interfaces/interfaces.h"
#include "utils/logger.h"

#include <functional>
#include <cassert>

void hooks::init() {
  using logger::ofs;

  *ofs << "Creating vmts..." << std::endl;
  client_vmt = new altvmt(interfaces::client);
  engine_vmt = new altvmt(interfaces::engine);
  panel_vmt = new altvmt(interfaces::panel);
  surface_vmt = new altvmt(interfaces::surface);
  entitylist_vmt = new altvmt(interfaces::entitylist);

  *ofs << client_vmt << " size " << client_vmt->size << std::endl;
  *ofs << engine_vmt << " size " << engine_vmt->size << std::endl;
  *ofs << panel_vmt << " size " << panel_vmt->size << std::endl;
  *ofs << surface_vmt << " size " << surface_vmt->size << std::endl;
  *ofs << entitylist_vmt << " size " << entitylist_vmt->size << std::endl;

  *ofs << "Creating hooks..." << std::endl;
  hooks::create_hook(hooks::panel_vmt, 42, (void*)&hooked_paint_traverse);
}

void hooks::create_hook(altvmt *vmt, int index, void* func) {
  using logger::ofs;

  *ofs << "hooking function at index " << index << "..." << std::endl;
  vmt->fake[index] = func;
  *ofs << "hook successful." << std::endl;
}

namespace hooks {
  altvmt *client_vmt = nullptr;
  altvmt *engine_vmt = nullptr;
  altvmt *panel_vmt = nullptr;
  altvmt *surface_vmt = nullptr;
  altvmt *entitylist_vmt = nullptr;
}
