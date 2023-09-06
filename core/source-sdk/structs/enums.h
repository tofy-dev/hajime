enum entity_flags : int
{
	GROUND = (1 << 0),
	DUCKING = (1 << 1),
	WATERJUMP = (1 << 2),
	ONTRAIN = (1 << 3),
	INRAIN = (1 << 4),
	FROZEN = (1 << 5),
	ATCONTROLS = (1 << 6),
	CLIENT = (1 << 7),
	FAKECLIENT = (1 << 8)
};
