#ifndef _EXITS_
#define _EXITS_

class exit
{
public:

	char name[30];
	char description[300];

	room* origin;
	room* destination; 

	enum direction {north, south, east, west};

};

#endif