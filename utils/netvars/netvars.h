#include <cstdint>
#include <map>
#include "dt_recv.h"

namespace netvars {
  void init();
  void init_offsets();

  // Parsing netvars
  int get_netvar(const char* dt, const char* m);
  void dump_netvars();
  void print_offsets();

  // Obtaining offsets post-dump
  uint32_t get_offset(char* name);


  extern std::map<const char*, int> offsets_;
}
