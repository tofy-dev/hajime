#include <fstream>
#include "utils/timeutil.h"
#include "interfaces/interfaces.h"

int __attribute__((constructor)) main() {
  std::ofstream ofs{"/tmp/hajime <初め> "+timeutil::now()+".txt", std::ios::app};
  ofs << "Opening file..." << std::endl;

  ofs << "Initing InterfaceMgr..." << std::endl;
  interfaces::init();
  
  int w, h;
  interfaces::engine->get_screen_size(w, h);
  ofs << w << " " << h << std::endl;
}
