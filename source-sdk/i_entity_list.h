#pragma once
#include "utils/utils.h"

class i_entity_list {
public:
  void* get_client_entity(int index) {
    typedef void*(*fn)(void*, int);
    return utils::get_virtual_function<fn>(this, 3)(this, index);
  }

  int get_highest_entity_index() {
    typedef int(*fn)(void*);
    return utils::get_virtual_function<fn>(this, 6)(this);
  }

  int get_max_entities() {
    typedef int(*fn)(void*);
    return utils::get_virtual_function<fn>(this, 8)(this);
  }
};
