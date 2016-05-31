#ifndef __WORLD_H__
#define __WORLD_H_

#include "vector.h"
#include "entity.h"

#define DELAY 10000
#define COMMANDBUFFER 50

class World
{
public:

	Vector<Entity*> entities;
//	Player* runna;

public:
	World();
	~World();

	bool game();

	char command[COMMANDBUFFER];
	bool loop_1 = true;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int charcommandnum = 0;

	

};
#endif //world