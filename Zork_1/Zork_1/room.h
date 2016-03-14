#ifndef _ROOM_
#define _ROOM_

#include "world.h"
#include <string.h>

class room
{
public:

	char name;
	char description;
	char north;
	char south;
	char east;
	char west;

};

#endif