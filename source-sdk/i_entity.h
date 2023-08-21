#pragma once

#include <cstdint>
class c_base_combat_weapon;
class client_class;
class vector;
struct model_t;
typedef float matrix3x4[3][4];

class c_base_entity {
public:
    bool get_life_state();

    int get_health();

    int get_team();

    void update_glow_effect();

    bool is_dormant();
};
