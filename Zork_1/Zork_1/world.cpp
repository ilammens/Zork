#include "world.h"
#include "room.h"
#include "exits.h"
#include "player.h"

world::world()
{
	rooms = new room[NUM_ROOMS];
	exits = new exit[/*count exit num!*/];
	players = new player[1];
}

world::~world()
{
	delete[] rooms;
	delete[] exits;
	delete[] players;
}

void const world::create_world()
{
	int i;

}