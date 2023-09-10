#include "implementations.h"
#include "hooks/hooks.h"
#include "interfaces/interfaces.h"
#include "source-sdk/i_entity.h"
#include "utils/netvars/netvars.h"
#include "features/esp/glow.h"
#include "utils/logger.h"
#include "globals/settings.h"

typedef void (*PaintTraverseFn) (void*, unsigned int, bool, bool);
void implementations::hooked_paint_traverse(void* thisptr, unsigned int vgui_panel, bool force_repaint, bool allow_force) {
  if (settings::sniper_scope) {
    const char* name = interfaces::panel->get_name(vgui_panel);
    if (name[0] == 'H' && name[3] == 'S' && name[8] == '\0') return;
  }

  hooks::panel_vmt->get_original_function<PaintTraverseFn>(42)(thisptr, vgui_panel, force_repaint, allow_force);

  static unsigned int drawPanel = 0;

  if(!drawPanel)
  {
  	std::string szPanelName = interfaces::panel->get_name(vgui_panel);
  	if(szPanelName.find("FocusOverlayPanel") != std::string::npos)
      drawPanel = vgui_panel;
  }
  
  if(drawPanel && vgui_panel == drawPanel) {
    if (settings::glow) glow::glow();
    if (settings::third_person) {
      c_base_entity* localPlayer = (c_base_entity*) interfaces::entitylist->get_client_entity(interfaces::engine->get_local_player());
      *(int*)((uint32_t)localPlayer+netvars::get_offset("m_nForceTauntCam")) = 1;
    }
  }
}
