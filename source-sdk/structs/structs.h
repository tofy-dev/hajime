#pragma once
class vector{};
class c_user_cmd final
{
public:
	virtual ~c_user_cmd() {}; //Destructor 0
	int command_number; //4
	int tick_count; //8
	vector viewangles; //C
	float forwardmove; //18
	float sidemove; //1C
	float upmove; //20
	int	buttons; //24
	unsigned char impulse; //28
	int weaponselect; //2C
	int weaponsubtype; //30
	int random_seed; //34
	short mousedx; //38
	short mousedy; //3A
	bool has_been_predicted; //3C;
};
