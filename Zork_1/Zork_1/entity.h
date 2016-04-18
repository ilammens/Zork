#ifndef __ENTITY__
#define __ENTITY__
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