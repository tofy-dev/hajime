#pragma once

#include <cstdint>
#include "i_entity.h"
#include "utils/netvars/netvars.h"

class vector {};

bool c_base_entity::get_life_state() {
  return *(bool*)netvars::get_offset("m_lifeState");
}

int c_base_entity::get_health() {
  return *(int*)netvars::get_offset("m_iHealth");
}

int c_base_entity::get_team() {
  return *(int*)netvars::get_offset("m_iTeamNum");
}
