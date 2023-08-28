#include "autostab.h"
#include "interfaces/interfaces.h"
#include "source-sdk/c_base_combat_weapon.h"
#include "source-sdk/i_entity.h"
#include "source-sdk/iv_engine_client.h"
#include "utils/logger.h"

void autostab::check() {
  *logger::ofs << "Getting localplayer..." << std::endl;
  c_base_entity* localPlayer = (c_base_entity*) interfaces::entitylist->get_client_entity(interfaces::engine->get_local_player());
  if (localPlayer == NULL) return;

  *logger::ofs << "Getting weapon..." << std::endl;
  c_base_combat_weapon* weapon = localPlayer->get_weapon();
  if (weapon == NULL) return;

  /*
  *logger::ofs << "If weaponid == 7" << std::endl;
  if (weapon->get_weapon_id() == 7) {
    *logger::ofs << "If backstab" << std::endl;
    if (weapon->calc_is_attack_critical_helper_no_crits()) {
      *logger::ofs << "Attack" << std::endl;
      weapon->primary_attack();
    }
  }
  */

  *logger::ofs << "w_id" << weapon->get_weapon_id() << std::endl;
  *logger::ofs << "w_rcrit" << weapon->calc_is_attack_critical_helper() << std::endl;
  *logger::ofs << "w_crit" << weapon->calc_is_attack_critical_helper() << std::endl;
  weapon->primary_attack();
  interfaces::engine->client_cmd("+attack");
}
