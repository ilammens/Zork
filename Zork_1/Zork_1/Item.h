#ifndef __ITEM__
#define __ITEM__

#include "entity.h"
#include "room.h"

enum objects{SWORD, BAG, TORCH, BOW, ARROWS, ORB};

class Item : public Entity
{
public:
	Item(const char* new_name, const char* new_description, Room* origin, bool equipped, bool inventory) : Entity(new_name, new_description){ };

	Room* origin;
	bool equipped;
	bool inventory;

	int max = 8;
	
	
	~Item(){};

};

#endif