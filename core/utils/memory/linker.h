#pragma once
#include <cstdint>
using std::uint8_t;
using std::size_t;

namespace linker {
	// Iterate loaded shared libraries and optionally return base address and size.
	bool get_library_information(const char*, uintptr_t* = nullptr, size_t* = nullptr);
}
