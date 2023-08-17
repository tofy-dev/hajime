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

	bool is_alive();

	bool is_player();

	int get_health();
    
    vector get_origin();

    int get_team();

    bool& glow_enabled();

	void update_glow_effect();

	void destroy_glow_effect();
};
