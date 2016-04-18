#ifndef __PLAYER__
#define __PLAYER__
#include "entity.h"
#include "Item.h"

class player //: public Entity
{
public:
	//player(const char* new_name, const char* new_description, Room* loc) : Entity(new_name, new_description){};
	
	Room* loc;

	enum stats
	{
		no_stats,
		sword_attack,
		sword_defense,
		sword_strenght
	};

	stats sword = no_stats;
};

#endif