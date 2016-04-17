#ifndef __WORLD__
#define __WORLD__

#define NUM_ROOMS 13
#define NUM_EXITS 21

#include "room.h"
#include "exits.h"
#include "player.h"
#include "Item.h"
#include "Vector.h"

class world
{
public:

	Vector<Room*> rooms;
	Vector<Exit*> exits;
	// Vector<player*> players;
	Vector<Item*> items;

	player* players;

public:
	world();
	~world();

	void create_world();
	void move();

};

#endif