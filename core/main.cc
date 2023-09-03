#include "interfaces/interfaces.h"
#include "hooks/hooks.h"
#include "globals/globals.h"

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

  /*
  *ofs << "pattern: " << std::endl;
  *ofs << std::hex << interfaces::client << std::endl;
  *ofs << std::hex << interfaces::client_addr << std::endl;
  uintptr_t pat = memory::find_pattern("tf/bin/client.so", "\xC7\x04\x24\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x10\x89\xD8\x5B\x5E\x5D\xC3\x8D\xB6\x00\x00\x00\x00", "xxx????x????xxxxxxxxxxxxxxx");
  *ofs << pat << std::endl;
  *ofs << pat+3 << std::endl;
  *ofs << reinterpret_cast<int*>(pat) << std::endl;
  *ofs << *reinterpret_cast<int**>(pat+3) << std::endl;
  */

  *ofs << "pattern: " << std::endl;
  *ofs << std::hex << memory::find_pattern("tf/bin/client.so", "\x89\x45\x08\x89\x4D\x0C\x5D\x8B\x42\x2C", "xxxxxxxxxx") << std::endl; 
  *ofs << std::hex << *reinterpret_cast<void**>(memory::find_pattern("tf/bin/client.so", "\x89\x45\x08\x89\x4D\x0C\x5D\x8B\x42\x2C", "xxxxxxxxxx")) << std::endl;

  /*
  altvmt* clientmode_vmt = new altvmt(*reinterpret_cast<void**>(find_pattern("tf/bin/client.so", "\x89\x45\x08\x89\x4D\x0C\x5D\x8B\x42\x2C", "xxxxxxxxxx")));
  *ofs << "size: " << clientmode_vmt->size << std::endl;
  */
}

namespace logger {
  std::ofstream* ofs = nullptr;
}
