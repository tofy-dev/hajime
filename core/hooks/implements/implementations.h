#include "source-sdk/structs/structs.h"

namespace implementations {
  void hooked_paint_traverse(void* thisptr, unsigned int vgui_panel, bool force_repaint, bool allow_force);
  void hooked_create_move(float flInputSampleTime, c_user_cmd *cmd);
}
