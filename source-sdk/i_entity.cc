#pragma once

#include "i_entity.h"
#include "c_base_combat_weapon.h"
#include "interfaces/interfaces.h"
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

c_base_combat_weapon* c_base_entity::get_weapon() {
  auto wep_handle = *reinterpret_cast< uintptr_t* >(this+netvars::get_offset("m_hActiveWeapon"));
  auto weapon = reinterpret_cast< c_base_combat_weapon* >(interfaces::entitylist->get_client_entity_from_handle(wep_handle));
  return weapon;
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
