#ifndef _WORLD_
#define _WORLD_

#define NUM_ROOMS 13

class world
{
public:

	room* rooms;
	exit* exits;
	
	world()
	{
		rooms = new room[NUM_ROOMS];
	}
	~world();

	void create_world();

};

#endif