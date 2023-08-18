#pragma once
#include "source-sdk/iv_engine_client.h"
#include "source-sdk/iv_panel.h"
#include "source-sdk/i_base_client_dll.h"
#include "source-sdk/i_entity_list.h"
#include "source-sdk/i_surface.h"

#include <string>

namespace interfaces {
  void init();

  extern int engine_addr;
  extern int client_addr;
  extern int vgui_addr;
  extern int matsurface_addr;

  extern iv_engine_client *engine;
  extern iv_panel *panel;
  extern i_base_client_dll *client;
  extern i_entity_list *entitylist;
  extern i_surface *surface;
};

