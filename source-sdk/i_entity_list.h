#pragma once
#include "c_base_handle.h"
#include "i_entity.h"
#include "utils/utils.h"

class i_entity_list {
public:
  void* get_client_entity(int index) {
    typedef void*(*fn)(void*, int);
    return static_cast<c_base_entity*>(utils::get_virtual_function<fn>(this, 3)(this, index));
  }

  void* get_client_entity_from_handle(const CBaseHandle& handle) {
    typedef void*(*fn)(void*, const CBaseHandle& handle);
    return static_cast<c_base_entity*>(utils::get_virtual_function<fn>(this, 4)(this, handle));
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
