#include "interfaces/interfaces.h"
#include "hooks/hooks.h"

#include "utils/timeutil.h"
#include "utils/netvars/netvars.h"
#include "utils/memory/memory.h"
#include "utils/logger.h"

#include <fstream>

int __attribute__((constructor)) main() {
  using logger::ofs;
  ofs = new std::ofstream{"/tmp/haj初め["+timeutil::now()+"].txt", std::ios::app};
  *ofs << "Opening file..." << std::endl;

  *ofs << "Initing InterfaceMgr..." << std::endl;
  interfaces::init();

  // memory::print_base_address(interfaces::client);
  *ofs << "client " << interfaces::client;
  
  
  // *ofs << "Initing NetvarMgr..." << std::endl;
  // netvars::init();

  // *ofs << "Getting offsets..." << std::endl;
  // netvars::dump_netvars();
  // netvars::get_netvar("DT_BasePlayer", "m_iHealth");
  // netvars::get_netvar("DT_BasePlayer", "m_lifeState");
  // netvars::get_netvar("DT_BaseEntity", "m_vecOrigin");
  // netvars::get_netvar("DT_BaseEntity", "m_iTeamNum");
  // netvars::get_netvar("DT_TFPlayer", "m_nForceTauntCam");
  // netvars::print_offsets();

  // *ofs << "Initing hooks..." << std::endl;
  // hooks::init();
}

namespace logger {
  std::ofstream* ofs = nullptr;
}
