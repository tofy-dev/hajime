#include "interfaces/interfaces.h"
#include "hooks/hooks.h"

#include "utils/timeutil.h"
#include "utils/netvars/netvars.h"
#include "utils/logger.h"

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
}

namespace logger {
  std::ofstream* ofs = nullptr;
}
