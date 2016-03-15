#include "world.h"
//#include "room.h"
//#include "exits.h"
//#include "player.h"
#include <string.h>
#include <stdio.h>

world::world()
{
	rooms = new Room[NUM_ROOMS];
	exits = new Exit[NUM_EXITS];
	players = new player;
}

world::~world()
{
	delete[] rooms;
	delete[] exits;
	delete[] players;
}

void world::create_world()
{
	int i, j; //i -> rooms, j -> exits;

	//start + exits
	i = 0;
	strcpy_s((rooms + i)->name, "Start\n");
	strcpy_s((rooms + i)->description, "You seem to be in a large field. To the north you can see a rocky path, while to the south there is a sand path.\n");

	j = 0;
	(exits + j)->origin = (rooms + 0);
	(exits + j)->destination = (rooms + 1); //waterfall
	(exits + j)->direction = north;
	strcpy_s((exits + i)->description, "There seems to be a path leading northwards. You hear water roaring if you listen carefully.\n");

	j = 1;
	(exits + j)->origin = (rooms + 0);
	(exits + j)->destination = (rooms + 3); //main chamber
	(exits + j)->direction = south;
	strcpy_s((exits + i)->description, "There's a sandy path leading south. Not much more to see.\n");

	//waterfall + exits
	i = 1;
	strcpy_s((rooms + i)->name, "Waterfall\n");
	strcpy_s((rooms + i)->description, "You are now in front of a big waterfall. It looks like to the west there's a cave, hidden behind a curtain of water.\n");

	j = 2;
	(exits + j)->origin = (rooms + 1);
	(exits + j)->destination = (rooms + 2); //sword room
	(exits + j)->direction = west;
	strcpy_s((exits + i)->description, "If you look carefully, you can see a sort of cave hidden behind the waterfall, to the west.\n");

	j = 3;
	(exits + j)->origin = (rooms + 1);
	(exits + j)->destination = (rooms + 0); //start
	(exits + j)->direction = south;
	strcpy_s((exits + i)->description, "There's a rocky path leading southwards. In the distance you see a huge field.\n");

	//sword room + exits
	i = 2;
	strcpy_s((rooms + i)->name, "Sword room\n");
	strcpy_s((rooms + i)->description, "With some effort, you get behind the waterfall. You seem to have encountered a cave. In the middle of it, a sword, that looks elvish-made, glimmers with the dim light coming from behind the curtain of water. There's an exit to the east.\n");

	j = 4;
	(exits + j)->origin = (rooms + 2);
	(exits + j)->destination = (rooms + 1); //waterfall
	(exits + j)->direction = east;
	strcpy_s((exits + i)->description, "You can get out of the cave by heading east.\n");

	//main chamber
	i = 3;
	strcpy_s((rooms + i)->name, "Main chamber\n");
	strcpy_s((rooms + i)->description, "You fell down a nasty hole in the ground! You now find yourself in a strange underground room with stone walls, submerged in an eerie orange light. You can see a dark path leading south.\n");

	j = 5;
	(exits + j)->origin = (rooms + 3);
	(exits + j)->destination = (rooms + 4); //underground temple
	(exits + j)->direction = south;
	strcpy_s((exits + i)->description, "An eerie light comes from the end  of a dark path leading south. It seems to be the only way forward.\n");

	//underground temple
	i = 4;
	strcpy_s((rooms + i)->name, "Underground temple\n");
	strcpy_s((rooms + i)->description, "There are several torches hung on the walls of this temple. An abandoned altar stands in the center of the room, with what seems to be remains of blood covering its once-white surface. You can see an old door to the west, and a dark entrance to the east.\n");

	j = 6;
	(exits + j)->origin = (rooms + 4);
	(exits + j)->destination = (rooms + 5); //bow room
	(exits + j)->direction = west;
	strcpy_s((exits + i)->description, "There's a wooden door to the west. It appears to be locked.\n");

	j = 7;
	(exits + j)->origin = (rooms + 4);
	(exits + j)->destination = (rooms + 6); //crystal cave
	(exits + j)->direction = east;
	strcpy_s((exits + i)->description, "There's a dark entrance leading somewhere to your east.\n");

	//bow room
	i = 5;
	strcpy_s((rooms + i)->name, "Bow room\n");
	strcpy_s((rooms + i)->description, "This room is completely austere, and there's a shimmering elvish bow hung on the furthermost wall. A little winged pixie stands guard by it. There's an old door to the east.\n");

	j = 8;
	(exits + j)->origin = (rooms + 5);
	(exits + j)->destination = (rooms + 4); //underground temple
	(exits + j)->direction = east;
	strcpy_s((exits + i)->description, "There's a wooden door to the east. It appears to be locked.\n");


	//crystal cave
	i = 6;
	strcpy_s((rooms + i)->name, "Crystal cave\n");
	strcpy_s((rooms + i)->description, "The light from a torch hung on the entrance wall refracts on the walls of the cave, which is entirely made of iridescent crystal. There's a huge door to the north, an entrance to the west, and a dimly lit passageway to the east. You hear the sound of trickling water coming from the east.\n");

	j = 9;
	(exits + j)->origin = (rooms + 6);
	(exits + j)->destination = (rooms + 4); //underground temple
	(exits + j)->direction = west;
	strcpy_s((exits + i)->description, "There's a dark entrance to the west. It appears to lead to the Underground Temple again.\n");

	j = 10;
	(exits + j)->origin = (rooms + 6);
	(exits + j)->destination = (rooms + 7); //dragon statue
	(exits + j)->direction = north;
	strcpy_s((exits + i)->description, "There's a huge locked door to your north. I wonder where it leads...\n");

	j = 20; //jump  from j = 10 to j = 20 because I forgot to add this exit, added it later...
	(exits + j)->origin = (rooms + 6);
	(exits + j)->destination = (rooms + 9); //underground lake
	(exits + j)->direction = east;
	strcpy_s((exits + i)->description, "You can hear the sound of trickling water coming from the east. There's a poorly lit passageway there.\n");

	//dragon statue
	i = 7;
	strcpy_s((rooms + i)->name, "Dragon statue\n");
	strcpy_s((rooms + i)->description, "An enormous dragon forged in bronze stands guard in the room. In its eye shimmers what appears to be a misplaced emerald. There's a door to the south and another door, intricatedly decorated, behind the statue, and you hear some muffled sounds coming from behind it.\n");

	j = 11;
	(exits + j)->origin = (rooms + 7);
	(exits + j)->destination = (rooms + 8); //dragon room!
	(exits + j)->direction = north;
	strcpy_s((exits + i)->description, "You hear deep, rumbling sounds coming from the north, from behind a door. I wonder if it's a good idea to go there... *shivers*\n");

	j = 12;
	(exits + j)->origin = (rooms + 7);
	(exits + j)->destination = (rooms + 6); //crystal cave
	(exits + j)->direction = south;
	strcpy_s((exits + i)->description, "There's a door leading south. It appears to lead to the Crystal Cave again.\n");

	//Dragon room!
	i = 8;
	strcpy_s((rooms + i)->name, "Dragon room\n");
	strcpy_s((rooms + i)->description, "WATCH OUT! There's a huge white dragon curled up in the middle of the room! He seems to be guarding a glowing blue orb. Its flaming red eyes are pointed on you, and from its nostrils there comes out some grey smoke. There's a closed door to your south.\n");

	j = 13;
	(exits + j)->origin = (rooms + 8);
	(exits + j)->destination = (rooms + 7); //dragon statue
	(exits + j)->direction = south;
	strcpy_s((exits + i)->description, "Wanna run from the dragon, huh? Quick, head south! There's a door there!\n");

	//Underground lake
	i = 9;
	strcpy_s((rooms + i)->name, "Underground lake\n");
	strcpy_s((rooms + i)->description, "A relatively small and shallow lake occupies this secondary cave. Luminescent plants submerge the cave in a strange greenish light. There's a passageway to the west and a bridge to the east, that crosses the lake. You can't see where it ends.\n");

	j = 14;
	(exits + j)->origin = (rooms + 9);
	(exits + j)->destination = (rooms + 6); //crystal cave
	(exits + j)->direction = west;
	strcpy_s((exits + i)->description, "There's a dark passageway leading west. It appears to lead to a familiar, glittering cave.\n");

	j = 15;
	(exits + j)->origin = (rooms + 9);
	(exits + j)->destination = (rooms + 10); //catacombs
	(exits + j)->direction = east;
	strcpy_s((exits + i)->description, "There's a bridge that crosses the lake to the east. It appeasr to lead to an eerie, dark room.\n");

	//Catacombs
	i = 10;
	strcpy_s((rooms + i)->name, "Catacombs\n");
	strcpy_s((rooms + i)->description, "You can hear the wind whistling along the dark corridors of these catacombs. The only light comes from a lonesome torch, and the walls are lined with tombs carved in the stone wall and covered in faded smears of blood. There's a bridge to the west, a small wooden door to the east and a passageway to the north.\n");

	j = 16;
	(exits + j)->origin = (rooms + 10);
	(exits + j)->destination = (rooms + 11); //orb
	(exits + j)->direction = east;
	strcpy_s((exits + i)->description, "There's a small wooden door to the east. You realize it's unlocked, after looking more carefully.\n");

	j = 17;
	(exits + j)->origin = (rooms + 10);
	(exits + j)->destination = (rooms + 12); //final room
	(exits + j)->direction = north;
	strcpy_s((exits + i)->description, "There's a passageway leading north. There's an air current coming from there, and a weird smell of old dust.\n");

	j = 18;
	(exits + j)->origin = (rooms + 10);
	(exits + j)->destination = (rooms + 9); //underground lake
	(exits + j)->direction = west;
	strcpy_s((exits + i)->description, "You can see a bridge leading west. It takes back to the Lake.\n");

	//Orb
	i = 11;
	strcpy_s((rooms + i)->name, "Orb\n");
	strcpy_s((rooms + i)->description, "In a pedestal in the middle of the room, lies another blue orb. The only exit is to the west.\n");

	j = 19;
	(exits + j)->origin = (rooms + 11);
	(exits + j)->destination = (rooms + 10); //catacombs
	(exits + j)->direction = west;
	strcpy_s((exits + i)->description, "The only exit you see is a small wooden door to the west.\n");

	//Arena
	i = 11;
	strcpy_s((rooms + i)->name, "Decaying arena");
	strcpy_s((rooms + i)->description, "This is a huge decaying, underground arena. Its flattened sand floor and its stone arches carved in the walls of the cavern give you chills. A hooded figure stands in the middle of the room. You can't exit this room.\n");


}

void world::move()
{
	char instruction[20]; //stores player's input command

	int i = 0; //exits

	printf("You are now here: %s\n%s\n", ((rooms + i)->name), ((rooms + i)->description));
	printf("You can use the following instructions to play: north/n/go north,\n south/s/go south,\n east/e/go east,\n west/w/go west\n, look,\n help,\n go,\n quit.\n");
	
	do
	{
		printf("What do you want to do? ");
		scanf_s("%s", &instruction);

		if (instruction == "north" || instruction == "go north" || instruction == "n")
		{
			for (i = 0; i < 20; i++)
			{
				if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == north)
				{
					//set new position
					(*(rooms + i)) = (*(exits + i)->destination);
					printf("You went north. You are now here: %s\n", ((rooms + i)->name));
					printf("%s\n", ((rooms + i)->description));
				}
			}
		}

		if (instruction == "south" || instruction == "go south" || instruction == "s")
		{
			for (i = 0; i < 20; i++)
			{
				if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == south)
				{
					//set new position
					(*(rooms + i)) = (*(exits + i)->destination);
					printf("You went south. You are now here: %s\n", ((rooms + i)->name));
					printf("%s\n", ((rooms + i)->description));
				}
			}
		}

		if (instruction == "east" || instruction == "go east" || instruction == "e")
		{
			for (i = 0; i < 20; i++)
			{
				if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == east)
				{
					//set new position
					(*(rooms + i)) = (*(exits + i)->destination);
					printf("You went east. You are now here: %s\n", ((rooms + i)->name));
					printf("%s\n", ((rooms + i)->description));
				}
			}
		}

		if (instruction == "west" || instruction == "go west" || instruction == "w")
		{
			for (i = 0; i < 20; i++)
			{
				if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == west)
				{
					//set new position
					(*(rooms + i)) = (*(exits + i)->destination);
					printf("You went west. You are now here: %s\n", ((rooms + i)->name));
					printf("%s\n", ((rooms + i)->description));
				}
			}
		}

		if (instruction == "help")
		{
			printf("You are now here: %s\n%s\n", ((rooms + i)->description), ((rooms + i)->description)); //prints current room description again
		}

		if (instruction == "look")
		{

			printf("In which direction do you want to have a look? ");
			scanf_s("%s", &instruction);

			if (instruction == "n" || instruction == "north")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == north)
					{
						printf("%s", ((exits + i)->description)); //prints exit description, meaning where it is and what it looks like
					}
				}
			}

			if (instruction == "s" || instruction == "south")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == south)
					{
						printf("%s", ((exits + i)->description));
					}
				}
			}

			if (instruction == "e" || instruction == "east")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == east)
					{
						printf("%s", ((exits + i)->description));
					}
				}
			}

			if (instruction == "w" || instruction == "west")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == west)
					{
						printf("%s", ((exits + i)->description));
					}
				}
			}
		}

		if (instruction == "go")
		{
			printf("In which direction do you want to head? ");
			scanf_s("%s", &instruction);

			if (instruction == "north" || instruction == "go north" || instruction == "n")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == north)
					{
						//set new position
						(*(rooms + i)) = (*(exits + i)->destination);
						printf("You went north. You are now here: %s\n", ((rooms + i)->name));
						printf("%s\n", ((rooms + i)->description));
					}
				}
			}

			if (instruction == "south" || instruction == "go south" || instruction == "s")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == south)
					{
						//set new position
						(*(rooms + i)) = (*(exits + i)->destination);
						printf("You went south. You are now here: %s\n", ((rooms + i)->name));
						printf("%s\n", ((rooms + i)->description));
					}
				}
			}

			if (instruction == "east" || instruction == "go east" || instruction == "e")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == east)
					{
						//set new position
						(*(rooms + i)) = (*(exits + i)->destination);
						printf("You went east. You are now here: %s\n", ((rooms + i)->name));
						printf("%s\n", ((rooms + i)->description));
					}
				}
			}

			if (instruction == "west" || instruction == "go west" || instruction == "w")
			{
				for (i = 0; i < 20; i++)
				{
					if (((rooms + i) == ((exits + i)->origin)) && ((exits + i)->direction) == west)
					{
						//set new position
						(*(rooms + i)) = (*(exits + i)->destination);
						printf("You went west. You are now here: %s\n", ((rooms + i)->name));
						printf("%s\n", ((rooms + i)->description));
					}
				}
			}
		}


	} while (instruction != "quit" || instruction != "q");

	

}