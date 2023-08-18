#include "interfaces.h"
#include "source-sdk/iv_engine_client.h"
#include "source-sdk/iv_panel.h"
#include "source-sdk/i_base_client_dll.h"
#include "source-sdk/i_entity_list.h"
#include "source-sdk/i_surface.h"
#include "utils/logger.h"

#include <dlfcn.h>
#include <fstream>

typedef void *(*create_interface_t)(const char*, int*);
void interfaces::init() {
  using namespace logger;

  void *client_so = dlopen("./tf/bin/client.so", RTLD_LAZY);
  void *engine_so = dlopen("./bin/engine.so", RTLD_LAZY);
  void *vgui_so = dlopen("./bin/vgui2.so", RTLD_LAZY);
  void *materialsurface_so = dlopen("./bin/vguimatsurface.so", RTLD_LAZY);
  
  *ofs << "Creating interfaces..." << std::endl;
  engine = (iv_engine_client*)((create_interface_t) dlsym(engine_so, "CreateInterface"))("VEngineClient013", nullptr);
  client = (i_base_client_dll*)((create_interface_t) dlsym(client_so, "CreateInterface"))("VClient017", nullptr);
  entitylist = (i_entity_list*)((create_interface_t) dlsym(client_so, "CreateInterface"))("VClientEntityList003", nullptr);
  panel = (iv_panel*)((create_interface_t) dlsym(vgui_so, "CreateInterface"))("VGUI_Panel009", nullptr);
  surface = (i_surface*)((create_interface_t) dlsym(materialsurface_so, "CreateInterface"))("VGUI_Surface030", nullptr);
}

namespace interfaces {
  iv_engine_client *engine = nullptr;
  i_base_client_dll *client = nullptr;
  i_entity_list *entitylist = nullptr;
  iv_panel *panel = nullptr;
  i_surface *surface = nullptr;
}
