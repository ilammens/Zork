#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Creature.h"
#include "room.h"
#include "entity.h"

class Player : public Creature
{
public:

	Player(const char* name, const char* description, e_type type, int hp, int attack, Room* origin) : Creature(name, description, type){};
	~Player();

	Room* origin;
	Room* loc;
	int hp;
	int attack;

	int used = 0;
	int max = 8;
	int max_coins = 50;

public:
	
	void move(dir direction);
	void look(dir direction);
	void look_here();
	void open(dir direction);
	void close(dir direction);
	void take(String items);

	


};

#endif //player
	