#include "world.h"
#include "room.h"
#include "exits.h"
#include <string.h>

enum i
{

	START = 1,
	WATERFALL,
	SWORD_CHAMBER,
	MAIN_CHAMBER,
	BOW_CHAMBER,
	UNDERGROUND_TEMPLE,
	CRYSTAL_CAVE,
	DRAGON_STATUE,
	DRAGON_ROOM,
	UNDERGROUND_LAKE,
	CATACOMBS,
	FINAL_ROOM

}; //assign "i" value to each room

class start : public room
{
	void north()
	{
		strcpy("Waterfall");
	}

	void south()
	{
		strcpy("Main Chamber");
	}

	void east()
	{
		strcpy("Sword")
	}
};
