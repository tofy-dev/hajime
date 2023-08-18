#include "hooks/hooks.h"
#include "interfaces/interfaces.h"
#include "source-sdk/i_entity.h"
#include "utils/netvars/netvars.h"
#include "features/esp/glow.h"

typedef void (*PaintTraverseFn) (void*, unsigned int, bool, bool);
inline void hooked_paint_traverse(void* thisptr, unsigned int vgui_panel, bool force_repaint, bool allow_force) {
  ((PaintTraverseFn)hooks::panel_vmt->real[42])(thisptr, vgui_panel, force_repaint, allow_force);

  static unsigned int drawPanel = 0;

  if(!drawPanel)
  {
  	std::string szPanelName = interfaces::panel->get_name(vgui_panel);
  	if(szPanelName.find("FocusOverlayPanel") != std::string::npos)
      drawPanel = vgui_panel;
  }
  
  if(drawPanel && vgui_panel == drawPanel) {
    c_base_entity* localPlayer = (c_base_entity*) interfaces::entitylist->get_client_entity(interfaces::engine->get_local_player());
	if(!localPlayer) return;

    *(int*)((uint32_t)localPlayer+netvars::get_offset("m_nForceTauntCam")) = 1;
    glow::glow();
  }
}
