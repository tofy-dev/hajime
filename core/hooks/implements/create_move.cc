#include "features/bhop/bhop.h"
#include "implementations.h"
#include "hooks/hooks.h"
#include "source-sdk/structs/structs.h"
#include "utils/logger.h"
#include "globals/globals.h"
#include "features/autostab/autostab.h"
#include "interfaces/interfaces.h"
#include "globals/settings.h"

#include <bitset>

using logger::ofs;
typedef bool (*CreateMoveFn) (void*, float, c_user_cmd*);
bool implementations::hooked_create_move(void* thisptr, float flInputSampleTime, c_user_cmd *cmd) {
  bool result = hooks::cmd_vmt->get_original_function<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);
  if (!cmd || !cmd->command_number) {
    return result;
  }

  if (settings::bunnyhop) bhop::bhop(cmd);
  if (settings::auto_backstab) autostab::backstab(cmd);
  *ofs << std::bitset<32>(cmd->buttons) << std::endl;

  return result;
}
