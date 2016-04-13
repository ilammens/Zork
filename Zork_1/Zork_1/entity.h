#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "Vector.h"
#include "string_own.h"

class Entity
{
public:
	String name = nullptr;
	String description = nullptr;

public:
	Entity(const char* new_name, const char* new_description) : name(new_name), description(new_description){ };
	~Entity();
};

#endif