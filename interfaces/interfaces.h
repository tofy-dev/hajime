#pragma once
#include "source-sdk/iv_engine_client.h"
#include "source-sdk/iv_panel.h"
#include "source-sdk/i_base_client_dll.h"
#include "source-sdk/i_entity_list.h"
#include "source-sdk/i_surface.h"

#include <string>
#include <cstdint>

namespace interfaces {
  void init();

  extern uint32_t engine_addr;
  extern uint32_t client_addr;
  extern uint32_t vgui_addr;
  extern uint32_t matsurface_addr;

  extern iv_engine_client *engine;
  extern iv_panel *panel;
  extern i_base_client_dll *client;
  extern i_entity_list *entitylist;
  extern i_surface *surface;
};

