#include "memory.h"
#include "utils/logger.h"

#include <dlfcn.h>
#include <stdio.h>

void memory::print_base_address(void* handle) {
  using logger::ofs;

  Dl_info info;
  if (dladdr((void*)&print_base_address, &info)) {
    *ofs << info.dli_fbase << std::endl;
  } else {
    *ofs << "error retrieving base" << std::endl;
  }
}
