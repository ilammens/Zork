#ifndef __ITEM_H__
#define __ITEM_H__

#include "entity.h"

enum objects {bag, sword, arrows, bow, torch, orb, emerald };

class Item : public Entity
{
public:

	Item(const char* name, const char* description, Room* origin, bool invent, bool equip, e_type type, int damage, int hp) : Entity(name, description, type){};
	~Item();

	bool invent;
	bool equip;
	Room* origin;
	Room* location;

	int damage;
	int hp;


};

#endif //item