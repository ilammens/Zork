#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

class world
{
public:

	room* rooms = new rooms();
	
	{
		world() = new[13];
	}

	{
		~world() = delete[13];
	}
};

