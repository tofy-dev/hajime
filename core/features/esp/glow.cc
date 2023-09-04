#include "glow.h"
#include "source-sdk/c_glow_object_manager.h"
#include "interfaces/interfaces.h"
#include "source-sdk/i_entity.h"
#include "utils/netvars/netvars.h"
#include "utils/memory/memory.h"
#include "utils/logger.h"
#include "globals/globals.h"
#include <cstdint>

void glow::glow() {
  using logger::ofs;

  for (int index = 0; index < globals::g_GlowObjectManager->m_GlowObjectDefinitions.m_Size; index++) {
    GlowObjectDefinition_t& glowobject = globals::g_GlowObjectManager->m_GlowObjectDefinitions[index];

    if (glowobject.m_nNextFreeSlot != ENTRY_IN_USE)
        continue;

    glowobject.m_vGlowColor = Vector(1.f, 0.f, 1.f);
  }

  for (int index = 1; index < interfaces::entitylist->get_highest_entity_index(); index++) {
    // *ofs << "loop" << index << std::endl;
    c_base_entity* entity = interfaces::entitylist->get_client_entity(index);

    if(!entity)
      continue;
    // *ofs << "entity " << entity << std::endl;

    // *ofs << "dormant " << entity->is_dormant() << std::endl;
    if(entity->is_dormant())
      continue;

    // *ofs << "life state " << entity->get_life_state() << std::endl;
    if(entity->get_life_state() != 0)
      continue;

    // *ofs << "health " << entity->get_health() << std::endl;
    if(entity->get_health() < 1)
      continue;

    // *ofs << "Set glow = true..." << std::endl;
    // *ofs << "Update glow effect..." << std::endl;
    entity->update_glow_effect();
  }
}
