#ifndef _EXITS_
#define _EXITS_

#define CLOSED true
#define OPEN false

enum direct { north, south, east, west };

class Exit
{
public:

	char name[30];
	char description[300];
	bool door_state;

	Room* origin;
	Room* destination;
	direct direction;


};

#endif