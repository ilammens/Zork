#include <stdio.h>
#include <stdlib.h>
#include "world.h"
#include "room.h"



main()
{
	int opc;

	char dir;

	do //loop to ask for directions
	{
		printf("In which direction do you want to go? (n/s/e/w)");
		scanf_s("%c", &dir);



	} while (dir != 'q')
}

