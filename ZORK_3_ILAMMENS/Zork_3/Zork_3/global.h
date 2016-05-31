#ifndef __GLOBAL__
#define __GLOBAL__

//holds all enums

enum e_type
{
	CREATURE,
	EXIT,
	ROOM,
	ITEM
};

enum dir
{
	north,
	south,
	east,
	west
};

enum state
{
	CONTINUE,
	STOP,
	ERROR
};

#endif //global