#include <stdlib.h>
#include "world.h"
#include "room.h"


int main()
{
	
	world world;

	world.create_world();

	world.move();

	system("pause");
	return 0;

}

