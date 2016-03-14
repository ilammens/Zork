#ifndef _EXITS_
#define _EXITS_

class exit
{
public:

	char name[30];
	char description[300];
	char north;
	char south;
	char east;
	char west;

	room* origin;
	room* destination; 

};

#endif