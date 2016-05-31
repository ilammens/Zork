#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "my_string.h"
#include "l_list.h"
#include "global.h"

class Entity
{
public:

	e_type type;

	String name;
	String description;

	//List<Entity*> entity;

	Entity();
	Entity(const char* name, const char* description, e_type type) : name(name), description(description), type(type) {};
	~Entity();

	virtual state Update(){ return state::CONTINUE; };
};

#endif //entity