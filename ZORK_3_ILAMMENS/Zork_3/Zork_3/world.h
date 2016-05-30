#ifndef __WORLD_H__
#define __WORLD_H_

#include "vector.h"
#include "entity.h"

class World
{
public:

	Vector<Entity*> entity;

	World();
	~World();

};
#endif //world