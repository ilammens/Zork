#ifndef __ITEM_H__
#define __ITEM_H__

#include "entity.h"

enum objects {bag, sword, arrows, bow, torch, orb, emerald };

class Item : public Entity
{
public:

	Item(const char* name, const char* description, Room* origin, bool invent, bool equip, e_type type, objects num) : Entity(name, description, type){};
	~Item();

	bool invent;
	bool equip;
	Room* origin;

	objects num;


};

#endif //item