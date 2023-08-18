#include "altvmt.h"

namespace hooks {
  void init();
  void create_hook(altvmt *vmt, int idx, void* func);

  extern altvmt *client_vmt;
  extern altvmt *engine_vmt;
  extern altvmt *panel_vmt;
  extern altvmt *surface_vmt;
  extern altvmt *entitylist_vmt;
}
