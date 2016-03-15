#ifndef _WORLD_
#define _WORLD_

#define NUM_ROOMS 13
#define NUM_EXITS 19 //will vary when implementing traps

class world
{
public:

	room* rooms;
	exit* exits;
	
	world();
	~world();

	void create_world();
	void move();

};

#endif