#include <fstream>
#include "utils/timeutil.h"
#include "interfaces/interfaces.h"
#include "utils/netvars/netvars.h"

int __attribute__((constructor)) main() {
  std::ofstream ofs{"/tmp/hajime <初め> "+timeutil::now()+".txt", std::ios::app};
  ofs << "Opening file..." << std::endl;

  ofs << "Initing InterfaceMgr..." << std::endl;
  interfaces::init();
  
  int w, h;
  interfaces::engine->get_screen_size(w, h);
  ofs << w << " " << h << std::endl;

  ofs << "Initing NetvarMgr..." << std::endl;
  netvars::init();

  netvars::dump_netvars();

  ofs << "Getting offsets..." << std::endl;
  netvars::get_netvar("DT_BasePlayer", "m_iHealth");
  netvars::get_netvar("DT_BasePlayer", "m_lifeState");
  netvars::get_netvar("DT_BaseEntity", "m_vecOrigin");
  netvars::get_netvar("DT_BaseEntity", "m_iTeamNum");
  netvars::get_netvar("DT_TFPlayer", "m_nForceTauntCam");
}
