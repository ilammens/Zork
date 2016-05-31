#ifndef __ITEM_H__
#define __ITEM_H__

#include "entity.h"

class Item : public Entity
{
public:

	Item();
	Item(const char* name, const char* description, Room* origin, bool invent, bool equip, e_type type) : Entity(name, description, type){};
	~Item();

	bool invent;
	bool equip;
	Room* origin;

};

#endif //item