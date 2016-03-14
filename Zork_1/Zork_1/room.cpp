#include "world.h"
#include "room.h"
#include "exits.h"

room* rooms = new room(); //pointer to rooms

enum 
{

	START = 1,
	WATERFALL,
	SWORD,
	MAIN_CHAMBER,
	UNDERGROUND_TEMPLE,
	BOW_CHAMBER,
	CRYSTAL_CAVE,
	DRAGON_STATUE,
	DRAGON_ROOM,
	UNDERGROUND_LAKE,
	CATACOMBS,
	FINAL_ROOM

}; //assign "i" value to each room
