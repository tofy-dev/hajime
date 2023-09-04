#include "autostab.h"
#include "interfaces/interfaces.h"
#include "source-sdk/c_base_combat_weapon.h"
#include "source-sdk/i_entity.h"
#include "source-sdk/iv_engine_client.h"
#include "utils/logger.h"

bool autostab::is_backstab() {
  // *logger::ofs << "Getting localplayer..." << std::endl;
  c_base_entity* localPlayer = (c_base_entity*) interfaces::entitylist->get_client_entity(interfaces::engine->get_local_player());
  if (localPlayer == NULL) return false;

  // *logger::ofs << "Getting weapon..." << std::endl;
  c_base_combat_weapon* weapon = localPlayer->get_weapon();
  if (weapon == NULL) return false;

  // *logger::ofs << "If weaponid == 7" << std::endl;
  if (weapon->get_weapon_id() == 7) {
    // *logger::ofs << "If backstab" << std::endl;
    if (weapon->calc_is_attack_critical_helper_no_crits()) {
      // *logger::ofs << "Attack" << std::endl;
      return true;
    }
  }

  return false;
}
