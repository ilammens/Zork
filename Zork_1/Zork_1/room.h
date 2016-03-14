#ifndef _ROOM_
#define _ROOM_

#include "world.h"

class room
{
public:

	virtual void north();
	virtual void south();
	virtual void east();
	virtual void west();

};

#endif