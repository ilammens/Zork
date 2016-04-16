#ifndef __ITEM__
#define __ITEM__

#include "entity.h"
#include "room.h"

class Item : public Entity
{
public:
	Item(const char* new_name, const char* new_description, Room* origin) : Entity(new_name, new_description){ };

};

#endif