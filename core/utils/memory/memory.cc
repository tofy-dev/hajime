#include "memory.h"
#include "linker.h"
#include "utils/logger.h"

#include <cassert>
#include <dlfcn.h>
#include <math.h>
#include <stdio.h>
#include <link.h>
#include <string.h>

using logger::ofs;

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

inline bool memory::compare(const uint8_t* data, const uint8_t* pattern, const char* mask) {
	for (; *mask; ++mask, ++data, ++pattern) {
		if (*mask == 'x' && *data != *pattern) {
			return false;
		}
	}

	return *mask == 0;
}

uintptr_t memory::find_pattern(const char* library, const char* pattern_string, const char* mask) {
  size_t address = 0, length = 0;
	
	if (!linker::get_library_information(library, &address, &length))
		return 0;

    *ofs << "address: " << address << std::endl;
    *ofs << "length: " << length << std::endl;

	const uint8_t* pattern = reinterpret_cast<const uint8_t*>(pattern_string);

	for (size_t i = 0; i < length; i++) {
		if (compare(reinterpret_cast<uint8_t*>(address + i), pattern, mask)) {
            *ofs << "pattern found @ " << address+i << std::endl;
			return address + i;
		}
	}

	return 0;
}
