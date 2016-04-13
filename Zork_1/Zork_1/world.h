#ifndef __WORLD__
#define __WORLD__

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

	void create_world() const;
	void move() const;

};

#endif