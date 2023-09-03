#include "hooks.h"
#include "vmt_hook.h"
#include "implements/implementations.h"
#include "interfaces/interfaces.h"
#include "features/esp/glow.h"
#include "utils/logger.h"
#include "globals/globals.h"

#include <cstdint>
#include <functional>
#include <cassert>

using logger::ofs;
void hooks::init() {
  *ofs << "Creating vmts..." << std::endl;
  panel_vmt = new vmt_hook(interfaces::panel);
  client_vmt = new vmt_hook(interfaces::client);
  *ofs << globals::g_pClientMode << std::endl;
  *ofs << **reinterpret_cast<void***>((*reinterpret_cast<unsigned int**>(interfaces::client))[10]+1) << std::endl;
  cmd_vmt = new vmt_hook(**reinterpret_cast<void***>((*reinterpret_cast<unsigned int**>(interfaces::client))[10]+1));
  // cmd_vmt = new vmt_hook((void*)(*(reinterpret_cast<uintptr_t**>(interfaces::client))[10]+1));


  *ofs << "Creating hooks..." << std::endl;
  panel_vmt->hook_function((void*)&implementations::hooked_paint_traverse, 42);
  cmd_vmt->hook_function((void*)&implementations::hooked_create_move, 22);
}

void hooks::reset() {
  *ofs << "Reseting hooks..." << std::endl;
  delete panel_vmt;
  delete client_vmt;
  delete cmd_vmt;
}

namespace hooks {
  vmt_hook *panel_vmt = nullptr;
  vmt_hook *client_vmt = nullptr;
  vmt_hook *cmd_vmt = nullptr;
}
