#include "memory.h"
#include "utils/logger.h"

#include <cassert>
#include <dlfcn.h>
#include <math.h>
#include <stdio.h>
#include <link.h>
#include <string.h>

unsigned long memory::get_base_address(int pid, std::string moduleName) {
  //sanity check
  assert(!moduleName.substr(moduleName.length() - 3, 3 ).compare(".so"));
  
  //may have to use double '/'
  std::ifstream infile( "/proc/" + std::to_string(pid) + "/maps" );
  std::string sLineIn = "";
  
  while(std::getline(infile, sLineIn)) {
    if( sLineIn.find(moduleName) != std::string::npos ) {
      return std::stoul(sLineIn.substr(0, 8), 0, 16);
    }
  }

  return 0;
}
