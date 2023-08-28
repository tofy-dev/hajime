#include "i_entity_list.h"

c_base_entity* i_entity_list::get_client_entity(int index) {
  typedef void*(*fn)(void*, int);
  return static_cast<c_base_entity*>(utils::get_virtual_function<fn>(this, 3)(this, index));
}

c_base_entity* i_entity_list::get_client_entity_from_handle(c_base_handle handle) {
  typedef void*(*fn)(void*, c_base_handle);
  return static_cast<c_base_entity*>(utils::get_virtual_function<fn>(this, 4)(this, handle));
}

int i_entity_list::get_highest_entity_index() {
  typedef int(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 6)(this);
}

int i_entity_list::get_max_entities() {
  typedef int(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 8)(this);
}
