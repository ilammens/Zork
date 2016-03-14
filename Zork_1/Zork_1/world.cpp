#include "world.h"
#include "player.h"
#include "exits.h"
#include "room.h"

class world
{
public:

	void create_world()
	{
		{
			world() = new[13];
		}

		{
			~world() = delete[13];
		}
	}

	room* rooms = new room[13];
	player* players = new player[1];
	exit* exits = new exit[];


};


