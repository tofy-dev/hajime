#pragma once
#include "utils/utils.h"

class iv_panel {
public:
const char* get_name(unsigned int vguipanel) {
  typedef const char* (*fn)(void*, unsigned int);
    return utils::get_virtual_function<fn>(this, 37)(this, vguipanel);
  }
};
