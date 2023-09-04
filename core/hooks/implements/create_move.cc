#include "implementations.h"
#include "hooks/hooks.h"
#include "source-sdk/structs/structs.h"
#include "utils/logger.h"
#include "globals/globals.h"
#include "features/autostab/autostab.h"

using logger::ofs;
typedef bool (*CreateMoveFn) (void*, float, c_user_cmd*);
bool implementations::hooked_create_move(void* thisptr, float flInputSampleTime, c_user_cmd *cmd) {
  // *ofs << thisptr << std::endl;
  // *ofs << flInputSampleTime << std::endl;
  // *ofs << cmd << std::endl;

  if (cmd->buttons & IN_JUMP) {
    *ofs << "jumping" << std::endl;
  }

  if (autostab::is_backstab()) {
    // *ofs << "backstab!" << std::endl;
    // cmd->buttons |= IN_ATTACK;
  }
  bool ret = hooks::cmd_vmt->get_original_function<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);

  // *ofs << "checking cmd vals..." << std::endl;
  // *ofs << cmd->upmove << std::endl;
  // *ofs << cmd->tick_count << std::endl;
  // *ofs << cmd->forwardmove << std::endl;
  // *ofs << cmd->sidemove << std::endl;
  // *ofs << cmd->upmove << std::endl;
  // *ofs << cmd->buttons << std::endl;
  // *ofs << cmd->weaponselect << std::endl;
  // *ofs << cmd->weaponsubtype << std::endl;
  // *ofs << cmd->mousedx << std::endl;
  // *ofs << cmd->mousedy << std::endl;
  return ret;
}
