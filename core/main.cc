#include "interfaces/interfaces.h"
#include "hooks/hooks.h"
#include "globals/globals.h"
#include "menu/menu.h"

#include "utils/timeutil.h"
#include "utils/netvars/netvars.h"
#include "utils/logger.h"
#include "utils/memory/memory.h"

#include <cstdint>
#include <fstream>
#include <csignal>

using logger::ofs;

static void __attribute__((destructor)) destructor() {
  *ofs << "destructor called" << std::endl;
  hooks::reset();
  interfaces::reset();

  delete ofs;
}

static void __attribute__((constructor)) constructor() {
  ofs = new std::ofstream{"/tmp/hajめ.txt", std::ios::app};
  *ofs << "Opening file..." << std::endl;

  *ofs << "Initing InterfaceMgr..." << std::endl;
  interfaces::init();

  *ofs << "Initing menu..." << std::endl;
  menu::init();

  *ofs << "Initing NetvarMgr..." << std::endl;
  netvars::init();
  netvars::dump_netvars();

  *ofs << "Retrieving offsets..." << std::endl;
  netvars::init_offsets();
  netvars::print_offsets();

  *ofs << "Initing global vars..." << std::endl;
  globals::init();

  *ofs << "Initing hooks..." << std::endl;
  hooks::init();
}

namespace logger {
  std::ofstream* ofs = nullptr;
}
