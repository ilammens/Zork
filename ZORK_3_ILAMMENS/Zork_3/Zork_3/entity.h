#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "my_string.h"
#include "l_list.h"

class Entity
{
public:

	enum e_type
	{
		CREATURE,
		EXIT,
		ROOM,
		ITEM
	};

	String name;
	String description;

	List<Entity*> entities;

	Entity();
	~Entity();
};

#endif //entity