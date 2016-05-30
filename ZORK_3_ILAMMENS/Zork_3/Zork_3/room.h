#ifndef __ROOM_H__
#define __ROOM_H_

#include "entity.h"

class Room : public Entity
{
public:

	Room();
	Room(const char* name, const char* description, e_type type) : Entity(name, description, type){};
	~Room();
};

#endif //room