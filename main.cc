#include "interfaces/interfaces.h"
#include "hooks/hooks.h"

#include "utils/timeutil.h"
#include "utils/netvars/netvars.h"
#include "utils/logger.h"
#include "utils/memory/FindPattern.h"

#include <fstream>

int __attribute__((constructor)) main() {
  using logger::ofs;
  ofs = new std::ofstream{"/tmp/haj初め["+timeutil::now()+"].txt", std::ios::app};
  *ofs << "Opening file..." << std::endl;

  *ofs << "Initing InterfaceMgr..." << std::endl;
  interfaces::init();

  *ofs << "Initing NetvarMgr..." << std::endl;
  netvars::init();
  netvars::dump_netvars();

  *ofs << "Retrieving offsets..." << std::endl;
  netvars::init_offsets();
  netvars::print_offsets();

  *ofs << "Initing hooks..." << std::endl;
  hooks::init();

  *ofs << "elist size " << hooks::entitylist_vmt->size << std::endl;
  *ofs << FindPattern("tf/bin/client.so", "\xC7\x04\x24\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x10\x89\xD8\x5B\x5E\x5D\xC3\x8D\xB6\x00\x00\x00\x00", "xxx????x????xxxxxxxxxxxxxxx") << std::endl;
}

namespace logger {
  std::ofstream* ofs = nullptr;
}
