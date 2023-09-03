#include <string>
#include <cstdint>

namespace memory {
unsigned long get_base_address(int pid, std::string moduleName);

inline bool compare(const uint8_t* data, const uint8_t* pattern, const char* mask);

uintptr_t find_pattern(const char* library, const char* pattern_string, const char* mask);
}
