#include "autostab.h"
#include "interfaces/interfaces.h"
#include "source-sdk/c_base_combat_weapon.h"
#include "source-sdk/i_entity.h"
#include "source-sdk/iv_engine_client.h"
#include "utils/logger.h"
#include "source-sdk/structs/structs.h"
#include "utils/netvars/netvars.h"

bool autostab::backstab(c_user_cmd* cmd) {
  //*logger::ofs << "Getting localplayer..." << std::endl;
  c_base_entity* localPlayer = (c_base_entity*) interfaces::entitylist->get_client_entity(interfaces::engine->get_local_player());
  if (localPlayer == NULL) return false;

  //*logger::ofs << "Getting weapon..." << std::endl;
  c_base_combat_weapon* weapon = localPlayer->get_weapon();
  if (weapon == NULL) return false;

  *logger::ofs << cmd->tick_count << std::endl;
  // *logger::ofs << cmd->forwardmove << std::endl;
  *logger::ofs << cmd->sidemove << std::endl;

  //*logger::ofs << "If weaponid == 7" << std::endl;
  if (weapon->get_weapon_id() == 7) {
    //*logger::ofs << "If backstab" << std::endl;
    if (*(bool*)(weapon+netvars::get_offset("m_bReadyToBackstab"))) {
      cmd->buttons |= IN_ATTACK;
      return true;
    }
  }

  return false;
}
