#pragma once
#include <string>
#include <sstream>
#include <chrono>

using namespace std::chrono;

namespace timeutil {
  static std::string now() {
    zoned_time zt{current_zone(), floor<seconds>(system_clock::now())};
    auto lt = zt.get_local_time();
    auto tod = lt - floor<days>(lt);

    std::stringstream ss;
    ss << hh_mm_ss{tod};
    return ss.str();
  }
}
