#ifndef __EXIT_H__
#define __EXIT_H__

#include "global.h"
#include "entity.h"
#include "room.h"

#define OPEN true
#define CLOSED false

class Exit : public Entity
{
public:

	dir direction;

	Room* origin;
	Room* destination;

	bool door_state;

	Exit();
	Exit(const char* name, const char* description, bool door_state, Room* origin, Room* destination, dir direction, e_type type) : Entity(name, description, type) {};
	~Exit();
};

#endif