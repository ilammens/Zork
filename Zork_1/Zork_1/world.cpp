#include "world.h"
#include "room.h"
#include "exits.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "Item.h"

world::world()
{
	players = new player;
}

world::~world()
{
	delete[] players;
};

//change create world funcs -> new Room("name", "description")

void world::create_world()
{
	rooms.push_back(new Room("Start\n", "You seem to be in a large field. To the north you can see a rocky path, while to the south there is a sand path.\n"));
	rooms.push_back(new Room("Waterfall\n", "You are now in front of a big waterfall. It looks like to the west there's a cave, hidden behind a curtain of water.\n"));
	rooms.push_back(new Room("Sword room\n", "With some effort, you get behind the waterfall. You seem to have encountered a cave. In the middle of it, a sword, that looks elvish-made, glimmers with the dim light coming from behind the curtain of water. There's an exit to the east.\n"));
	rooms.push_back(new Room("Main Chamber\n", "You fell down a nasty hole in the ground! You now find yourself in a strange underground room with stone walls, submerged in an eerie orange light. You can see a dark path leading south.\n"));
	rooms.push_back(new Room("Underground Temple\n", "There are several torches hung on the walls of this temple. An abandoned altar stands in the center of the room, with what seems to be remains of blood covering its once-white surface. You can see an old door to the west, and a dark entrance to the east.\n"));
	rooms.push_back(new Room("Bow Room\n", "This room is completely austere, and there's a shimmering elvish bow hung on the furthermost wall. A little winged pixie stands guard by it. There's an old door to the east.\n"));
	rooms.push_back(new Room("Crystal Cave\n", "The light from a torch hung on the entrance wall refracts on the walls of the cave, which is entirely made of iridescent crystal. There's a huge door to the north, an entrance to the west, and a dimly lit passageway to the east. You hear the sound of trickling water coming from the east.\n"));
	rooms.push_back(new Room("Dragon Statue\n", "An enormous dragon forged in bronze stands guard in the room. In its eye shimmers what appears to be a misplaced emerald. There's a door to the south and another door, intricatedly decorated, behind the statue, and you hear some muffled sounds coming from behind it.\n"));
	rooms.push_back(new Room("Dragon Room\n", "WATCH OUT! There's a huge white dragon curled up in the middle of the room! He seems to be guarding a glowing blue orb. Its flaming red eyes are pointed on you, and from its nostrils there comes out some grey smoke. There's a closed door to your south.\n"));
	rooms.push_back(new Room("Underground Lake\n", "A relatively small and shallow lake occupies this secondary cave. Luminescent plants submerge the cave in a strange greenish light. There's a passageway to the west and a bridge to the east, that crosses the lake, and a staircase to the northwest. You can't see where it ends.\n"));
	rooms.push_back(new Room("Catacombs\n", "You can hear the wind whistling along the dark corridors of these catacombs. The only light comes from a lonesome torch, and the walls are lined with tombs carved in the stone wall and covered in faded smears of blood. There's a bridge to the west, a small unlocked wooden door to the east and a passageway to the north.\n"));
	rooms.push_back(new Room("Orb Room\n", "In a pedestal in the middle of the room, lies another blue orb. The only exit is to the west.\n"));
	rooms.push_back(new Room("Decaying Arena\n", "This is a huge decaying, underground arena. Its flattened sand floor and its stone arches carved in the walls of the cavern give you chills. A hooded figure stands in the middle of the room. You can't exit this room.\n"));

	exits.push_back(new Exit("Rocky Path\n", "There seems to be a path leading northwards. You hear water roaring if you listen carefully.\n", OPEN, rooms[0], rooms[1], north));
	exits.push_back(new Exit("Sand Path\n", "There's a sandy path leading south. Not much more to see.\n", OPEN, rooms[0], rooms[3], south));
	exits.push_back(new Exit("Waterfall\n", "If you look carefully, you can see a sort of cave hidden behind the waterfall, to the west.\n", OPEN, rooms[1], rooms[2], west));
	exits.push_back(new Exit("Rocky Path\n", "There's a rocky path leading southwards. In the distance you see a huge field.\n", OPEN, rooms[1], rooms[0], south));
	exits.push_back(new Exit("Waterfall Cave\n", "You can get out of the cave by heading east.\n", OPEN, rooms[2], rooms[1], east));
	exits.push_back(new Exit("Dark Path\n", "An eerie light comes from the end  of a dark path leading south. It seems to be the only way forward.\n", OPEN, rooms[3], rooms[4], south));
	exits.push_back(new Exit("Wooden Door\n", "There's a wooden door to the west. It appears to be locked.\n", OPEN, rooms[4], rooms[5], west));
	exits.push_back(new Exit("Dark Entrance\n", "There's a dark entrance leading somewhere to your east.\n", CLOSED, rooms[4], rooms[6], east));
	exits.push_back(new Exit("Wooden Door\n", "There's a wooden door to the east.\n", OPEN, rooms[5], rooms[4], east));
	exits.push_back(new Exit("Dark Entrance\n", "There's a dark entrance to the west. It appears to lead to the Underground Temple again.\n", OPEN, rooms[6], rooms[4], west));
	exits.push_back(new Exit("Huge Door\n", "There's a huge locked door to your north. You wonder where it leads...\n", OPEN, rooms[6], rooms[7], north));
	exits.push_back(new Exit("Dark Passageway\n", "You can hear the sound of trickling water coming from the east. There's a poorly lit passageway there.\n", OPEN, rooms[6], rooms[9], east));
	exits.push_back(new Exit("Decorated Door\n", "You hear deep, rumbling sounds coming from the north, from behind a door. I wonder if it's a good idea to go there... *shivers*\n", OPEN, rooms[7], rooms[8], north));
	exits.push_back(new Exit("Huge Door\n", "There's a door leading south. It appears to lead to the Crystal Cave again.\n", OPEN, rooms[7], rooms[6], south));
	exits.push_back(new Exit("Decorated Door\n", "Wanna run from the dragon, huh? Quick, head south! There's a door there!\n", OPEN, rooms[8], rooms[7], south));
	exits.push_back(new Exit("Dark Passageway\n", "There's a dark passageway leading west. It appears to lead to a familiar, glittering cave.\n", OPEN, rooms[9], rooms[6], west));
	exits.push_back(new Exit("Bridge\n", "There's a bridge that crosses the lake to the east. It appears to lead to an eerie, dark room.\n", OPEN, rooms[9], rooms[10], east));
	exits.push_back(new Exit("Small Door\n", "There's a small wooden door to the east. You realize it's unlocked, after looking more carefully.\n", OPEN, rooms[10], rooms[11], east));
	exits.push_back(new Exit("Dusty Passageway\n", "There's a passageway leading north. There's an air current coming from there, and a weird smell of old dust.\n", OPEN, rooms[10], rooms[12], north));
	exits.push_back(new Exit("Bridge\n", "You can see a bridge leading west. It takes back to the Lake.\n", OPEN, rooms[10], rooms[9], west));
	exits.push_back(new Exit("Small Door\n", "The only exit you see is a small wooden door to the west.\n", OPEN, rooms[11], rooms[10], west));

	items.push_back(new Item("Sword\n", "It's a fairly old-looking elvish sword, but it's edges are sharp as a razor blade.\n", rooms[2], false, false));
	items.push_back(new Item("Bag\n", "A simple, worn-out bag. It's fairly big, and you can hang it on your back.\n", rooms[0], false, false));
	items.push_back(new Item("Torch\n", "It's hung on the wall, but you can easily take it. It gives enough light for you to see in a radius of 4-5m.\n", rooms[4], false, false));
	items.push_back(new Item("Bow\n", "Another weapon of elvish craft. It's very lightweight. It's made out of birch wood.\n", rooms[5], false, false));
	items.push_back(new Item("Arrows\n", "Without arrows, a bow is of little use.\n", rooms[5], false, false));
	items.push_back(new Item("Ladder\n", "A wooden ladder. It seems to be high enough to get to the eye of the statue.", rooms[7], false, false));
	items.push_back(new Item("Emerald\n", "A shiny, green emerald. As you take it, you hear a light *click*\n", rooms[7], false, false));
	items.push_back(new Item("Orb\n", "It's a weird crystal orb. It seems as though there's some sort of blue non-harmful gas floating inside.\n", rooms[11], false, false));
}

void world::move()
{
	char instruction[20]; //stores player's input command

	// player* players;

	/*printf("What's your name?");
	gets_s(p_name);

	printf("Who are you?");
	gets_s(p_description);*/

	// players.push_back(new player(p_name, p_description, rooms[0]));

	printf("You are now here: %s\n%s\n", ((players->loc)->name), ((players->loc)->description)); //initial print, shows initial position

}
	/*
	do
	{
		printf("What do you want to do? ");
		gets_s(instruction);

		if (strcmp(instruction, "north") == 0 || strcmp(instruction, "go north") == 0 || strcmp(instruction, "n") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == north) //runs trough all the exits until origin and direction match
				{
					if ((exits + i)->door_state == OPEN)
					{
						//set new position
						((players->loc)) = ((exits + i)->destination);
						printf("You went north. You are now here: %s\n", ((players->loc)->name));
						printf("%s\n", ((players->loc)->description));
						break;
					}

					else if ((exits + i)->door_state == CLOSED)
					{
						printf("The door is locked. You need to open it first.\n");
						break;
					}
				}
			}
		}

		else if (strcmp(instruction, "south") == 0 || strcmp(instruction, "go south") == 0 || strcmp(instruction, "s") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == south)
				{
					if ((exits + i)->door_state == OPEN)
					{
						//set new position
						((players->loc)) = ((exits + i)->destination);
						printf("You went south. You are now here: %s\n", ((players->loc)->name));
						printf("%s\n", ((players->loc)->description));
						break;
					}

					else if ((exits + i)->door_state == CLOSED)
					{
						printf("The door is locked. You need to open it first.\n");
						break;
					}
				}
			}
		}

		else if (strcmp(instruction, "east") == 0 || strcmp(instruction, "go east") == 0 || strcmp(instruction, "e") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == east)
				{
					if ((exits + i)->door_state == OPEN)
					{
						//set new position
						((players->loc)) = ((exits + i)->destination);
						printf("You went east. You are now here: %s\n", ((players->loc)->name));
						printf("%s\n", ((players->loc)->description));
						break;
					}

					else if ((exits + i)->door_state == CLOSED)
					{
						printf("The door is locked. You need to open it first.\n");
						break;
					}
				}


			}
		}

		else if (strcmp(instruction, "west") == 0 || strcmp(instruction, "go west") == 0 || strcmp(instruction, "w") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == west)
				{
					if ((exits + i)->door_state == OPEN)
					{
						//set new position
						((players->loc)) = ((exits + i)->destination);
						printf("You went west. You are now here: %s\n", ((players->loc)->name));
						printf("%s\n", ((players->loc)->description));
						break;
					}

					else if ((exits + i)->door_state == CLOSED)
					{
						printf("The door is locked. You need to open it first.\n");
						break;
					}
				}
			}
		}

		else if (strcmp(instruction, "open west") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if ((((exits + i)->door_state) == CLOSED) && (((players->loc) == (exits + 6)->origin) && (((exits+6)->direction) = west))) //opens temple -> bow room
				{
					((exits + 6)->door_state) = OPEN; //changes door state
					printf("You unlocked the door.\n");
					break;
				}
			}
		}

		else if (strcmp(instruction, "open east") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if ((((exits + i)->door_state) == CLOSED) && (((players->loc) == (exits + 8)->origin) && (((exits + 8)->direction) = east))) //opens bow room -> temple
				{
					((exits + 8)->door_state) = OPEN; //changes door state
					printf("You unlocked the door.\n");
					break;
				}
			}
		}

		else if (strcmp(instruction, "close east") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if ((((exits + i)->door_state) == OPEN) && (((players->loc) == (exits + 8)->origin) && (((exits + 8)->direction) = east))) //closes bow room -> temple
				{
					((exits + 8)->door_state) = CLOSED; //changes door state
					printf("You locked the door.\n");
					break;
				}
			}
		}

		else if (strcmp(instruction, "close west") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if ((((exits + i)->door_state) == OPEN) && (((players->loc) == (exits + 6)->origin) && (((exits + 6)->direction) = west))) //closes temple -> bow room
				{
					((exits + 6)->door_state) = CLOSED; //changes door state
					printf("You locked the door.\n");
					break;
				}
			}
		}

		else if (strcmp(instruction, "help") == 0)
		{
			printf("You can use the following instructions to play:\nnorth/n/go north\nsouth/s/go south\neast/e/go east\nwest/w/go west\nlook (direction)\nopen (direction)\nhelp\ngo\nquit/q\n");
		}

		else if (strcmp(instruction, "look") == 0)
		{
			printf("You are now here: %s\n%s\n", ((players->loc)->name), ((players->loc)->description)); //prints current room name again
		}

		else if (strcmp(instruction, "look north") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == north)
				{
					printf("To the north there is: %s", ((exits + i)->destination)); //prints north room name
					break;
				}
			}
		}

		else if (strcmp(instruction, "look south") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == south)
				{
					printf("To the south there is: %s", ((exits + i)->destination)); //prints south room name
					break;
				}
			}
		}

		else if (strcmp(instruction, "look east") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == east)
				{
					printf("To the east there is: %s", ((exits + i)->destination)); //prints east room name
					break;
				}
			}
		}

		else if (strcmp(instruction, "look west") == 0)
		{
			for (i = 0; i < 20; i++)
			{
				if (((players->loc) == ((exits + i)->origin)) && ((exits + i)->direction) == west)
				{
					printf("To the west there is: %s", ((exits + i)->destination)); //prints west room name
					break;
				}
			}
		}

		else if (strcmp(instruction, "go") == 0)
		{
			printf("In which direction do you want to head? ");
		}

		else if (strcmp(instruction, "quit") == 0 || strcmp(instruction, "q") == 0)
		{
			printf("Bye! Thanks for playing :) - Game By: Isabel Lammens! :3\n\n");
			break;
		}

		else
		{
			printf("Please don't use this command. I can't understand it :(\n");
		}

	} while (1); //((strcmp(instruction, "quit") != 0 || strcmp(instruction, "q") != 0));


}
 */