#include "glow.h"
#include "source-sdk/c_glow_object_manager.h"
#include "interfaces/interfaces.h"
#include "source-sdk/i_entity.h"
#include "utils/netvars/netvars.h"

void glow::glow() {
  for (int index = 0; index < glowobjectmanager->m_GlowObjectDefinitions.m_Size; index++) {
    GlowObjectDefinition_t& glowobject = glowobjectmanager->m_GlowObjectDefinitions[index];

    if (glowobject.m_nNextFreeSlot != ENTRY_IN_USE)
        continue;

    glowobject.m_vGlowColor = Vector(0.f, 1.f, 0.f);
  }

  for (int index = 1; index < interfaces::entitylist->get_highest_entity_index(); index++) {
    c_base_entity* entity = static_cast<c_base_entity*>(interfaces::entitylist->get_client_entity(index));

	if(!entity)
	  continue;

	if(entity->get_health() < 1)
	  continue;

	if(entity->get_life_state() != 0)
	  continue;

    *(int*)((uint32_t)entity+netvars::get_offset("m_bGlowEnabled")) = 1;
    entity->update_glow_effect();
  }
}

namespace glow {
  CGlowObjectManager* glowobjectmanager = reinterpret_cast<CGlowObjectManager*>(interfaces::client_addr + 0x204F340);
}
