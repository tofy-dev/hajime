#pragma once
#include <cstddef>

namespace utils {
inline void**& get_virtual_table(void* baseclass) {
   return *reinterpret_cast<void***>(baseclass);
}

inline void* get_virtual_function(void* vftable, int num, size_t index) {
   return reinterpret_cast<void*>(get_virtual_table(vftable)[index]);
}

template <typename Fn> inline Fn get_virtual_function(void* vftable, size_t index) {
   return reinterpret_cast<Fn>(get_virtual_table(vftable)[index]);
}
}
