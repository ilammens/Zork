#include "world.h"
#include <stdlib.h>
#include <stdio.h>

World* world;

int main()
{
	world = new World();

	printf("You suddenly wake up in the middle of a field. There's a bag at your feet, and you have a faint headache. As you struggle to stand up, you start to remember: you are being chased by an assassin. You have to run.\n");
	printf("What will you do?\n");

	while(world->game());

	system("pause");
	return 0;
}