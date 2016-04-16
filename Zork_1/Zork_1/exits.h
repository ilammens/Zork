#ifndef _EXITS_
#define _EXITS_

#define CLOSED true
#define OPEN false

#include "entity.h"

enum direct { north, south, east, west };

class Exit : public Entity
{
public:

	Exit(const char* new_name, const char* new_description, bool door_state, Room* origin, Room* destination, direct dir) : Entity(new_name, new_description){ };

	bool door_state;

	Room* origin;
	Room* destination;
	direct dir;


};

#endif