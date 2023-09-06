#include "bhop.h"
#include "source-sdk/i_entity.h"
#include "interfaces/interfaces.h"
#include "netvars/netvars.h"
#include "source-sdk/structs/structs.h"
#include "source-sdk/structs/enums.h"

void bhop::bhop(c_user_cmd* cmd) {
  c_base_entity* localPlayer = (c_base_entity*) interfaces::entitylist->get_client_entity(interfaces::engine->get_local_player());
  int flags = *((int*)(localPlayer+netvars::get_offset("m_fFlags")));
    static bool released = true;

  if (cmd->buttons & IN_JUMP) {
    if (!released) {
      if (!(flags & entity_flags::GROUND))
          cmd->buttons &= ~(1 << 1);
    }
    else {
      released = false;
    }
  } else if (!released) {
    released = true;
  }
}
