#pragma once
#include "utils/utils.h"

class i_entity_list {
  void* get_client_entity(int index) {
    typedef void*(*fn)(void*, int);
    return utils::get_virtual_function<fn>(this, 3)(this, index);
  }
};
