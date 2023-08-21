#pragma once

#include "i_entity.h"
#include "utils/utils.h"
#include "utils/netvars/netvars.h"

bool c_base_entity::get_life_state() {
  return *(bool*)(this+netvars::get_offset("m_lifeState"));
}

int c_base_entity::get_health() {
  return *(int*)(this+netvars::get_offset("m_iHealth"));
}

int c_base_entity::get_team() {
  return *(int*)(this+netvars::get_offset("m_iTeamNum"));
}

bool c_base_entity::is_dormant() {
  typedef bool(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 75)(this);
}

void c_base_entity::update_glow_effect() {
  *(bool*)(this+netvars::get_offset("m_bGlowEnabled")) = true;
  typedef void(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 293)(this);
}
