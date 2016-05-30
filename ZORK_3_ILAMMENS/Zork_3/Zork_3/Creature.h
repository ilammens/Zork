#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "entity.h"
#include "room.h"

class Creature : public Entity
{
public:

	Room* location;

	Creature();
	Creature(const char* name, const char* description, e_type type) : Entity(name, description, type){};
	~Creature();
};

#endif //creature