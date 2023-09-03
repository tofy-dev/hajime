#include "source-sdk/structs/structs.h"

namespace implementations {
  void hooked_paint_traverse(void* thisptr, unsigned int vgui_panel, bool force_repaint, bool allow_force);
  bool hooked_create_move(void* thisptr, float flInputSampleTime, c_user_cmd *cmd);
}
