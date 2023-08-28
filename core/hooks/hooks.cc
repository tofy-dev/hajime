#include "hooks.h"
#include "vmt_hook.h"
#include "implements/implementations.h"
#include "interfaces/interfaces.h"
#include "utils/logger.h"

#include <cstdint>
#include <functional>
#include <cassert>

using logger::ofs;
void hooks::init() {
  *ofs << "Creating vmts..." << std::endl;
  panel_vmt = new vmt_hook(interfaces::panel);
  client_vmt = new vmt_hook(interfaces::client);

  *ofs << "Creating hooks..." << std::endl;
  panel_vmt->hook_function((void*)&implementations::hooked_paint_traverse, 42);
}

void hooks::reset() {
  *ofs << "Reseting hooks..." << std::endl;
  *ofs << "Deleting panel_vmt..." << std::endl;
  delete panel_vmt;
  *ofs << "Deleting client_vmt..." << std::endl;
  delete client_vmt;
}

namespace hooks {
  vmt_hook *panel_vmt = nullptr;
  vmt_hook *client_vmt = nullptr;
  vmt_hook *clientmode_vmt = nullptr;
}
