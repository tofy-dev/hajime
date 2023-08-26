#pragma once
#include "c_base_combat_weapon.h"

class c_base_entity {
public:
    bool get_life_state();

    int get_health();

    int get_team();

    c_base_combat_weapon* get_weapon();

    void update_glow_effect();

    bool is_dormant();
};
