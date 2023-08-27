#pragma once

class c_base_combat_weapon {
public:
    void primary_attack();
    int get_weapon_id();
    bool calc_is_attack_critical_helper_no_crits();
    bool calc_is_attack_critical_helper();
};
