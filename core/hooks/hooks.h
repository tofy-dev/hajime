#include "vmt_hook.h"

namespace hooks {
  void init();
  void reset();

  extern vmt_hook *panel_vmt;
  extern vmt_hook *client_vmt;
  extern vmt_hook *cmd_vmt;
}
