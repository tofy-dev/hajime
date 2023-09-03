#include "implementations.h"
#include "hooks/hooks.h"
#include "source-sdk/structs/structs.h"

typedef bool (*CreateMoveFn) (void*, float, c_user_cmd*);
bool implementations::hooked_create_move(void* thisptr, float flInputSampleTime, c_user_cmd *cmd) {
  return hooks::panel_vmt->get_original_function<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);
}
