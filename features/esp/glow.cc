#include "glow.h"
#include "source-sdk/c_glow_object_manager.h"
#include "interfaces/interfaces.h"
#include "source-sdk/i_entity.h"
#include "utils/netvars/netvars.h"
#include "utils/memory/FindPattern.h"
#include "utils/logger.h"

void glow::glow() {
  using logger::ofs;

  *ofs << "caddr: " << interfaces::client_addr << std::endl;
  *ofs << "caddr: " << interfaces::client_addr+0x204f340 << std::endl;

  CGlowObjectManager* glowobjectmanager = reinterpret_cast<CGlowObjectManager*> (interfaces::client_addr + 0x204f340);
  *ofs << "gom ptr: " << glowobjectmanager << std::endl;

  *ofs << "Glowing entities..." << std::endl;
  for (int index = 0; index < glowobjectmanager->m_GlowObjectDefinitions.m_Size; index++) {
    *ofs << "gom looping " << index << std::endl;
    GlowObjectDefinition_t& glowobject = glowobjectmanager->m_GlowObjectDefinitions[index];

    if (glowobject.m_nNextFreeSlot != ENTRY_IN_USE)
        continue;

    glowobject.m_vGlowColor = Vector(0.f, 1.f, 0.f);
  }

  *ofs << "Looping through entities..." << std::endl;
  *ofs << "[debug] max index: " << interfaces::entitylist->get_highest_entity_index() << std::endl;
  // *ofs << interfaces::entitylist->get_highest_entity_index() << std::endl;

  // for (int index = 1; index < interfaces::entitylist->get_highest_entity_index(); index++) {
    // *ofs << "loop" << index << std::endl;
    // c_base_entity* entity = static_cast<c_base_entity*>(interfaces::entitylist->get_client_entity(index));

	// if(!entity)
	//   continue;

	// if(entity->get_health() < 1)
	//   continue;

	// if(entity->get_life_state() != 0)
	//   continue;

    // *ofs << "Set glow = true..." << std::endl;
    // *(int*)((uint32_t)entity+netvars::get_offset("m_bGlowEnabled")) = 1;
    // *ofs << "Update glow effect..." << std::endl;
    // entity->update_glow_effect();
  // }
}
