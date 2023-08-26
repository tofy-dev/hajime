#include "c_base_combat_weapon.h"
#include "utils/utils.h"

int c_base_combat_weapon::get_weapon_id() {
  typedef int(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 449)(this); // index suspiciously high
}

bool c_base_combat_weapon::calc_is_attack_critical_helper_no_crits() {
  typedef int(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 465)(this);
}

bool c_base_combat_weapon::calc_is_attack_critical_helper() {
  typedef int(*fn)(void*);
  return utils::get_virtual_function<fn>(this, 466)(this);
}
