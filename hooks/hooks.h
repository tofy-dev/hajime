#include "altvmt.h"

namespace hooks {
  void init();
  void create_hook(altvmt *vmt, int idx, void* func);

  extern altvmt *panel_vmt;
  extern altvmt *clientmode_vmt;
}
