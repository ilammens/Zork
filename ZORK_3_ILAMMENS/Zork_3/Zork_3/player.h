#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Creature.h"
#include "room.h"
#include "entity.h"

class Player : public Creature
{
public:

	Player();
	Player(const char* name, const char* description, e_type type, int hp) : Creature(name, description, type){};

	Room* origin;
	Room* loc;
	int hp;

};

#endif //player
	