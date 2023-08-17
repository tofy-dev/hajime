#pragma once
#include "utils/utils.h"

class iv_engine_client {
public:
  void get_screen_size(int& width, int& height) {
	typedef void(*fn)(void*, int&, int&);
    utils::get_virtual_function<fn>(this, 5)(this, width, height);
  }
  int get_local_player() {
	typedef int(*fn)(void*);
    return utils::get_virtual_function<fn>(this, 12)(this);
  }
  int get_max_clients() {
    typedef int(*fn)(void*);
    return utils::get_virtual_function<fn>(this, 21)(this);
  }
};
