#ifndef _WORLD_
#define _WORLD_

#define NUM_ROOMS 13

class world
{
public:

	room* rooms;
	exit* exits;
	
	world();
	~world();

	void create_world();

};

#endif