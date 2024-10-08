#include "interfaces.h"
#include "source-sdk/iv_engine_client.h"
#include "source-sdk/iv_panel.h"
#include "source-sdk/i_base_client_dll.h"
#include "source-sdk/i_entity_list.h"
#include "source-sdk/i_surface.h"

#include "utils/logger.h"
#include "utils/memory/memory.h"

#include <dlfcn.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>


using namespace logger;
void* load_so(std::string name, uint32_t& addr) {
  addr = memory::get_base_address(getpid(), name);
  *ofs << "addr: " << addr << std::endl;
  return dlopen(("." + name).c_str(), RTLD_LAZY);
}

typedef void *(*create_interface_t)(const char*, int*);
void interfaces::init() {
  void* engine_so = load_so("/bin/engine.so", engine_addr);
  void* client_so = load_so("/tf/bin/client.so", client_addr);
  void* vgui_so = load_so("/bin/vgui2.so", vgui_addr);
  void* matsurface_so = load_so("/bin/vguimatsurface.so", matsurface_addr);

  *ofs << "Creating interfaces..." << std::endl;
  engine = (iv_engine_client*)((create_interface_t) dlsym(engine_so, "CreateInterface"))("VEngineClient013", nullptr);
  client = (i_base_client_dll*)((create_interface_t) dlsym(client_so, "CreateInterface"))("VClient017", nullptr);
  entitylist = (i_entity_list*)((create_interface_t) dlsym(client_so, "CreateInterface"))("VClientEntityList003", nullptr);
  panel = (iv_panel*)((create_interface_t) dlsym(vgui_so, "CreateInterface"))("VGUI_Panel009", nullptr);
  surface = (i_surface*)((create_interface_t) dlsym(matsurface_so, "CreateInterface"))("VGUI_Surface030", nullptr);

  dlclose(engine_so);
  dlclose(client_so);
  dlclose(vgui_so);
  dlclose(matsurface_so);
}

// Should be fine if none of the interfaces are deleted???
void interfaces::reset() {
}

namespace interfaces {
  uint32_t engine_addr;
  uint32_t client_addr;
  uint32_t vgui_addr;
  uint32_t matsurface_addr;

  iv_engine_client *engine = nullptr;
  i_base_client_dll *client = nullptr;
  i_entity_list *entitylist = nullptr;
  iv_panel *panel = nullptr;
  i_surface *surface = nullptr;
}
