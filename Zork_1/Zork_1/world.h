#ifndef _WORLD_
#define _WORLD_

#define NUM_ROOMS 13
#define NUM_EXITS 21 //will vary when implementing traps

#include "room.h"
#include "exits.h"
#include "player.h"

class world
{
public:

	Room* rooms;
	Exit* exits;
	player* players;

public:
	world();
	~world();

	void const create_world();
	void const move();

};

#endif