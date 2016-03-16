#ifndef _EXITS_
#define _EXITS_

enum direct { north, south, east, west };

class Exit
{
public:

	char name[30];
	char description[300];
	bool door;

	Room* origin;
	Room* destination;
	direct direction;


};

#endif