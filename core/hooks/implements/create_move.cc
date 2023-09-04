#include "implementations.h"
#include "hooks/hooks.h"
#include "source-sdk/structs/structs.h"
#include "utils/logger.h"
#include "globals/globals.h"

using logger::ofs;
typedef bool (*CreateMoveFn) (void*, float, c_user_cmd*);
bool implementations::hooked_create_move(void* thisptr, float flInputSampleTime, c_user_cmd *cmd) {
  *ofs << thisptr << std::endl;
  *ofs << globals::g_pClientMode << std::endl;

  *ofs << thisptr << std::endl;
  *ofs << flInputSampleTime << std::endl;
  *ofs << cmd << std::endl;

  *ofs << "function? idk" << std::endl;
  *ofs << hooks::panel_vmt->get_original_function<CreateMoveFn>(22) << std::endl;

  bool ret = hooks::panel_vmt->get_original_function<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);
  *ofs << "checking cmd vals..." << std::endl;
  *ofs << cmd->upmove << std::endl;
  *ofs << cmd->tick_count << std::endl;
  *ofs << cmd->forwardmove << std::endl;
  *ofs << cmd->sidemove << std::endl;
  *ofs << cmd->upmove << std::endl;
  *ofs << cmd->buttons << std::endl;
  *ofs << cmd->weaponselect << std::endl;
  *ofs << cmd->weaponsubtype << std::endl;
  *ofs << cmd->mousedx << std::endl;
  *ofs << cmd->mousedy << std::endl;
  return ret;
}
