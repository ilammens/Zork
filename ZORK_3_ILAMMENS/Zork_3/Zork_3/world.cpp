#include "world.h"
#include "exit.h"
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "item.h"
#include "player.h"
#include <Windows.h>
#include "conio.h"
#include "room.h"

Player* runna;

World::World()
{
	entities.push_back(new Room("Start\n", "You seem to be in a large field. To the north you can see a rocky path, while to the south there is a sand path. There's a bag at your feet.\n", ROOM));
	entities.push_back(new Room("Waterfall\n", "You are now in front of a big waterfall. It looks like to the west there's a cave, hidden behind a curtain of water.\n", ROOM));
	entities.push_back(new Room("Sword room\n", "With some effort, you get behind the waterfall. You seem to have encountered a cave. In the middle of it, a sword, that looks elvish-made, glimmers with the dim light coming from behind the curtain of water. There's an exit to the east.\n", ROOM));
	entities.push_back(new Room("Main Chamber\n", "You fell down a nasty hole in the ground! You now find yourself in a strange underground room with stone walls, submerged in an eerie orange light. You can see a dark path leading south.\n", ROOM));
	entities.push_back(new Room("Underground Temple\n", "There are several torches hung on the walls of this temple. One torch seems slightly looser hung than the others. An abandoned altar stands in the center of the room, with what seems to be remains of blood covering its once-white surface. You can see an old door to the west, and a dark entrance to the east.\n", ROOM));
	entities.push_back(new Room("Bow Room\n", "This room is completely austere, and there's a shimmering elvish bow hung on the furthermost wall, alongside some arrows. A little winged pixie stands guard by it. There's an old door to the east.\n", ROOM));
	entities.push_back(new Room("Crystal Cave\n", "The light from a torch hung on the entrance wall refracts on the walls of the cave, which is entirely made of iridescent crystal. There's a huge door to the north, an entrance to the west, and a dimly lit passageway to the east. You hear the sound of trickling water coming from the east.\n", ROOM));
	entities.push_back(new Room("Dragon Statue\n", "An enormous dragon forged in bronze stands guard in the room. In its eye shimmers what appears to be a misplaced emerald. There's a door to the south and another door, intricatedly decorated, behind the statue, and you hear some muffled sounds coming from behind it.\n", ROOM));
	entities.push_back(new Room("Dragon Room\n", "WATCH OUT! There's a huge white dragon curled up in the middle of the room! He seems to be guarding a glowing blue orb. Its flaming red eyes are pointed on you, and from its nostrils there comes out some grey smoke. There's a closed door to your south.\n", ROOM));
	entities.push_back(new Room("Underground Lake\n", "A relatively small and shallow lake occupies this secondary cave. Luminescent plants submerge the cave in a strange greenish light. There's a passageway to the west and a bridge to the east, that crosses the lake, and a staircase to the northwest. You can't see where it ends.\n", ROOM));
	entities.push_back(new Room("Catacombs\n", "You can hear the wind whistling along the dark corridors of these catacombs. The only light comes from a lonesome torch, and the walls are lined with tombs carved in the stone wall and covered in faded smears of blood. There's a bridge to the west, a small unlocked wooden door to the east and a passageway to the north.\n", ROOM));
	entities.push_back(new Room("Orb Room\n", "In a pedestal in the middle of the room, lies another blue orb. The only exit is to the west.\n", ROOM));
	entities.push_back(new Room("Decaying Arena\n", "This is a huge decaying, underground arena. Its flattened sand floor and its stone arches carved in the walls of the cavern give you chills. A hooded figure stands in the middle of the room. You can't exit this room.\n", ROOM));

	entities.push_back(new Exit("Rocky Path\n", "There seems to be a path leading northwards. You hear water roaring if you listen carefully.\n", OPEN, (Room*)entities[0], (Room*)entities[1], north, EXIT));
	entities.push_back(new Exit("Sand Path\n", "There's a sandy path leading south. Not much more to see.\n", OPEN, (Room*)entities[0], (Room*)entities[3], south, EXIT));
	entities.push_back(new Exit("Waterfall\n", "If you look carefully, you can see a sort of cave hidden behind the waterfall, to the west.\n", OPEN, (Room*)entities[1], (Room*)entities[2], west, EXIT));
	entities.push_back(new Exit("Rocky Path\n", "There's a rocky path leading southwards. In the distance you see a huge field.\n", OPEN, (Room*)entities[1], (Room*)entities[0], south, EXIT));
	entities.push_back(new Exit("Waterfall Cave\n", "You can get out of the cave by heading east.\n", OPEN, (Room*)entities[2], (Room*)entities[1], east, EXIT));
	entities.push_back(new Exit("Dark Path\n", "An eerie light comes from the end  of a dark path leading south. It seems to be the only way forward.\n", OPEN, (Room*)entities[3], (Room*)entities[4], south, EXIT));
	entities.push_back(new Exit("Wooden Door\n", "There's a wooden door to the west. It appears to be locked.\n", OPEN, (Room*)entities[4], (Room*)entities[5], west, EXIT));
	entities.push_back(new Exit("Dark Entrance\n", "There's a dark entrance leading somewhere to your east.\n", CLOSED, (Room*)entities[4], (Room*)entities[6], east, EXIT));
	entities.push_back(new Exit("Wooden Door\n", "There's a wooden door to the east.\n", OPEN, (Room*)entities[5], (Room*)entities[4], east, EXIT));
	entities.push_back(new Exit("Dark Entrance\n", "There's a dark entrance to the west. It appears to lead to the Underground Temple again.\n", OPEN, (Room*)entities[6], (Room*)entities[4], west, EXIT));
	entities.push_back(new Exit("Huge Door\n", "There's a huge locked door to your north. You wonder where it leads...\n", OPEN, (Room*)entities[6], (Room*)entities[7], north, EXIT));
	entities.push_back(new Exit("Dark Passageway\n", "You can hear the sound of trickling water coming from the east. There's a poorly lit passageway there.\n", OPEN, (Room*)entities[6], (Room*)entities[9], east, EXIT));
	entities.push_back(new Exit("Decorated Door\n", "You hear deep, rumbling sounds coming from the north, from behind a door. I wonder if it's a good idea to go there... *shivers*\n", OPEN, (Room*)entities[7], (Room*)entities[8], north, EXIT));
	entities.push_back(new Exit("Huge Door\n", "There's a door leading south. It appears to lead to the Crystal Cave again.\n", OPEN, (Room*)entities[7], (Room*)entities[6], south, EXIT));
	entities.push_back(new Exit("Decorated Door\n", "Wanna run from the dragon, huh? Quick, head south! There's a door there!\n", OPEN, (Room*)entities[8], (Room*)entities[7], south, EXIT));
	entities.push_back(new Exit("Dark Passageway\n", "There's a dark passageway leading west. It appears to lead to a familiar, glittering cave.\n", OPEN, (Room*)entities[9], (Room*)entities[6], west, EXIT));
	entities.push_back(new Exit("Bridge\n", "There's a bridge that crosses the lake to the east. It appears to lead to an eerie, dark room.\n", OPEN, (Room*)entities[9], (Room*)entities[10], east, EXIT));
	entities.push_back(new Exit("Small Door\n", "There's a small wooden door to the east. You realize it's unlocked, after looking more carefully.\n", OPEN, (Room*)entities[10], (Room*)entities[11], east, EXIT));
	entities.push_back(new Exit("Dusty Passageway\n", "There's a passageway leading north. There's an air current coming from there, and a weird smell of old dust.\n", OPEN, (Room*)entities[10], (Room*)entities[12], north, EXIT));
	entities.push_back(new Exit("Bridge\n", "You can see a bridge leading west. It takes back to the Lake.\n", OPEN, (Room*)entities[10], (Room*)entities[9], west, EXIT));
	entities.push_back(new Exit("Small Door\n", "The only exit you see is a small wooden door to the west.\n", OPEN, (Room*)entities[11], (Room*)entities[10], west, EXIT));

	entities.push_back(new Item("Sword\n", "It's a fairly old-looking elvish sword, but it's edges are sharp as a razor blade.\n", (Room*)entities[2], false, false, ITEM, sword));
	entities.push_back(new Item("Bag\n", "A simple, worn-out bag. It's fairly big, and you can hang it on your back.\n", (Room*)entities[0], false, false, ITEM, bag));
	entities.push_back(new Item("Torch\n", "It's hung on the wall, but you can easily take it. It gives enough light for you to see in a radius of 4-5m.\n", (Room*)entities[4], false, false, ITEM, torch));
	entities.push_back(new Item("Bow\n", "Another weapon of elvish craft. It's very lightweight. It's made out of birch wood.\n", (Room*)entities[5], false, false, ITEM, bow));
	entities.push_back(new Item("Arrows\n", "Without arrows, a bow is of little use.\n", (Room*)entities[5], false, false, ITEM, arrows));
	entities.push_back(new Item("Emerald\n", "A shiny, green emerald. As you take it, you hear a light *click*\n", (Room*)entities[7], false, false, ITEM, emerald));
	entities.push_back(new Item("Orb\n", "It's a weird crystal orb. It seems as though there's some sort of blue non-harmful gas floating inside.\n", (Room*)entities[11], false, false, ITEM, orb));

	runna = new Player("Runna\n", "You're an average-looking elf. You've got white braided hair that reaches your middle back, and you're wearing what appear to be warrior robes. You carry no weapons.", CREATURE, 150, 10, (Room*)entities[0]);
	entities.push_back(runna);
};

World::~World(){};

bool World::game()
{
	state update;
	String instruction;
	int i;

	initialtime = GetTickCount();

	//runs code every x milliseconds (DELAY)
	currenttime = GetTickCount();
	if (currenttime >= (initialtime + DELAY))
	{
		for (int i = 0; i < entities.size(); i++)
		{
			update = entities[i]->Update();

			if (update == STOP)
				return false;

			if (update == error)
			{
				printf("An error has occurred :(\n");
				getchar();
				return false;
			}
		}
		initialtime = currenttime;
	}


		if (_kbhit())
		{
			if (charcommandnum < (COMMANDBUFFER - 2)){
				command[charcommandnum] = _getch();
				command[charcommandnum + 1] = '\0';
				printf("String: %s\n", command); //prints command state
				charcommandnum++;

				system("cls");
				printf("You chose: %s\n", command);

				if (command[charcommandnum - 1] == '\r')
				{ //prints command and deletes it afterwards
					printf("You chose: %s\n", command);
					command[charcommandnum - 1] = '\0';
					charcommandnum = 0;
					instruction = command;

					Vector<String> token;
					instruction.tokenize(token);

					printf("What do you want to do?\n");

					while (1)
					{
						if (token[0] == "north" || token[0] == "go" && token[1] == "north" || token[0] == "n")
						{
							runna->move(north);
						}

						if (token[0] == "south" || token[0] == "go" && token[1] == "south" || token[0] == "s")
						{
							runna->move(south);
						}

						if (token[0] == "east" || token[0] == "go" && token[1] == "east" || token[0] == "e")
						{
							runna->move(east);
						}

						if (token[0] == "west" || token[0] == "go" && token[1] == "west" || token[0] == "w")
						{
							runna->move(west);
						}

						if (token[0] == "help")
						{
							printf("You can use the following instructions to play:\nnorth/n/go north\nsouth/s/go south\neast/e/go east\nwest/w/go west\nlook\nopen (direction)\ntake\ndrop\nequip\nunequip\ntalk\nattackhelp\ngo\nquit/q\n");
						}

						if (token[0] == "look")
						{
							runna->look_here();
						}

						if (token[0] == "look" && token[1] == "north")
						{
							runna->look(north);
						}

						if (token[0] == "look" && token[1] == "south")
						{
							runna->look(south);
						}

						if (token[0] == "look" && token[1] == "east")
						{
							runna->look(east);
						}

						if (token[0] == "look" && token[1] == "west")
						{
							runna->look(west);
						}

						if (token[0] == "open" && (token[1] == "north" || token[1] == "n"))
						{
							runna->open(north);
						}

						if (token[0] == "open" && (token[1] == "south" || token[1] == "s"))
						{
							runna->open(south);
						}

						if (token[0] == "open" && (token[1] == "east" || token[1] == "e"))
						{
							runna->open(east);
						}

						if (token[0] == "open" && (token[1] == "west" || token[1] == "w"))
						{
							runna->open(west);
						}

						if (token[0] == "take")
						{
							if (token[1] == "sword" || token[1] == "bow" || token[1] == "arrows" || token[1] == "bag") //|| token[1] = "emerald" || token[1] == "orb" || token[1] == "torch")
							{
								runna->take(token[1]);
							}
						}

						if (token[0] == "q" || token[0] == "quit")
						{
							printf("Thanks for playing! :3\n");
							return false;
						}

					}
				}
				else{
					command[COMMANDBUFFER - 1] = '\0';
				}
			}
		}
	}

