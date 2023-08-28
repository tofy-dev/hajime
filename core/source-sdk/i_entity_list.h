#pragma once

#include "i_entity.h"
#include "c_base_handle.h"
#include "utils/utils.h"
#include "utils/logger.h"
#include <cstdint>

class i_entity_list {
public:
  c_base_entity* get_client_entity(int index);

  c_base_entity* get_client_entity_from_handle(c_base_handle handleptr);

  int get_highest_entity_index();

  int get_max_entities();
};
