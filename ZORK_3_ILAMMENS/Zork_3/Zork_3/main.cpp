#include "world.h"
#include <stdlib.h>

World* world;

int main()
{
	world = new World();

	while(world->game());

	system("pause");
	return 0;
}