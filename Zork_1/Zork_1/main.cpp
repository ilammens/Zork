#include <stdlib.h>
#include <stdio.h>
#include "world.h"


int main()
{
	printf("You can use the following instructions to play:\nnorth/n/go north\nsouth/s/go south\neast/e/go east\nwest/w/go west\nlook (direction)\nopen (direction)\nhelp\ngo\nquit/q\n");
	
	world world;

	world.create_world();

	world.move();

	system("pause");
	return 0;

}

