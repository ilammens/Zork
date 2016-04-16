#ifndef __ROOM__
#define __ROOM__
#include "entity.h"

class Room : public Entity
{
public:

	Room(const char* new_name, const char* new_description, int num) : Entity(new_name, new_description){ };

};

#endif