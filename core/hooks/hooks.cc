#include "hooks.h"
#include "hooks/altvmt.h"
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
  cmd_vmt = new vmt_hook(globals::g_pClientMode);

  *ofs << "Creating hooks..." << std::endl;
  *ofs << "hook successful: " << (panel_vmt->hook_function((void*)&implementations::hooked_paint_traverse, 42) ? "yes" : "no") << std::endl;
  // *ofs << "hook successful: " << (cmd_vmt->hook_function(hooks::cmd_vmt->get_original_function(22), 22) ? "yes" : "no") << std::endl;
  *ofs << "hook successful: " << (cmd_vmt->hook_function((void*)&implementations::hooked_create_move, 22) ? "yes" : "no") << std::endl;
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
