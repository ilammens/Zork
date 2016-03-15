#include "world.h"
#include "room.h"
#include "exits.h"
#include "player.h"
#include <string.h>

world::world()
{
	rooms = new room[NUM_ROOMS];
	exits = new exit[/*count exit num!*/];
	players = new player[1];
}

world::~world()
{
	delete[] rooms;
	delete[] exits;
	delete[] players;
}

void const world::create_world()
{
	int i, j; //i -> rooms, j -> exits;
	
		//north = 1, south = 2, east = 3, west = 4
		//start + exits
		i = 0;
		strcpy_s((rooms + i)->name, "Start");
		strcpy_s((rooms + i)->description, "You seem to be in a large field. To the north you can see a rocky path, while to the south there is a sand path.");

		j = 0;
		(exit + j)->origin = (rooms + 0);
		(exit + j)->destination = (rooms + 1); //waterfall
		(exit + j)->direction = north;

		j = 1;
		(exit + j)->origin = (rooms + 0);
		(exit + j)->destination = (rooms + 3); //main chamber
		(exit + j)->direction = south;

		//waterfall + exits
		i = 1;
		strcpy_s((rooms + i)-> name, "Waterfall");
		strcpy_s((rooms + i)->description, "You are now in front of a big waterfall. It looks like to the west there's a cave, hidden behind a curtain of water.");

		j = 2;
		(exit + j)->origin = (rooms + 1);
		(exit + j)->destination = (rooms + 2); //sword room
		(exit + j)->direction = west;

		j = 3;
		(exit + j)->origin = (rooms + 1);
		(exit + j)->destination = (rooms + 0); //start
		(exit + j)->direction = south;

		//sword room + exits
		i = 2;
		strcpy_s((rooms + i)->name, "Sword room");
		strcpy_s((rooms + i)->description, "With some effort, you get behind the waterfall. You seem to have encountered a cave. In the middle of it, a sword, that looks elvish-made, glimmers with the dim light coming from behind the curtain of water.");
		
		j = 4;
		(exit + j)->origin = (rooms + 2);
		(exit + j)->destination = (rooms + 1); //waterfall
		(exit + j)->direction = east;

		//main chamber
		i = 3;
		strcpy_s((rooms + i) -> name, "Main chamber");
		strcpy_s((rooms + i) -> description, "You fell down a nasty hole in the ground! You now find yourself in a strange underground room with stone walls, submerged in an eerie orange light. You can see a dark path leading south.");
	
		j = 5;
		(exit + j)->origin = (rooms + 3);
		(exit + j)->destination = (rooms + 4); //underground temple
		(exit + j)->direction = south;

		//underground temple
		i = 4;
		strcpy_s((rooms + i) -> name, "Underground temple");
		strcpy_s((rooms + i) -> description, "There are several torches hung on the walls of this temple. An abandoned altar stands in the center of the room, with what seems to be remains of blood covering its once-white surface. You can see an old door to the west, and a dark entrance to the east.");

		j = 6;
		(exit + j)->origin = (rooms + 4);
		(exit + j)->destination = (rooms + 5); //bow room
		(exit + j)->direction = west;

		j = 7;
		(exit + j)->origin = (rooms + 4);
		(exit + j)->destination = (rooms + 6); //crystal cave
		(exit + j)->direction = east;

		//bow room
		i = 5;
		strcpy_s((rooms + i)->name, "Bow room");
		strcpy_s((rooms + i)->description, "This room is completely austere, and there's a shimmering elvish bow hung on the furthermost wall. A little winged pixie stands guard by it. There's an old door to the east.");

		j = 8;
		(exit + j)->origin = (rooms + 5);
		(exit + j)->destination = (rooms + 4); //underground temple
		(exit + j)->direction = east;

		//crystal cave
		i = 6;
		strcpy_s((rooms + i)->name, "Crystal cave");
		strcpy_s((rooms + i)->description, "The light from a torch hung on the entrance wall refracts on the walls of the cave, which is entirely made of iridescent crystal. There's a huge door to the north, an entrance to the west, and a dimly lit passageway to the east. You hear the sound of trickling water coming from the east.");

		j = 9;
		(exit + j)->origin = (rooms + 6);
		(exit + j)->destination = (rooms + 4); //underground temple
		(exit + j)->direction = west;

		j = 10;
		(exit + j)->origin = (rooms + 6);
		(exit + j)->destination = (rooms + 7); //dragon statue
		(exit + j)->direction = north;

		//dragon statue
		i = 7;
		strcpy_s((rooms + i)->name, "Dragon statue");
		strcpy_s((rooms + i)->description, "An enormous dragon forged in bronze stands guard in the room. In its eye shimmers what appears to be a misplaced emerald. There's a door to the south and another door, intricatedly decorated, behind the statue, and you hear some muffled sounds coming from behind it.");

		j = 11;
		(exit + j)->origin = (rooms + 7);
		(exit + j)->destination = (rooms + 8); //dragon room!
		(exit + j)->direction = north;

		j = 12;
		(exit + j)->origin = (rooms + 7);
		(exit + j)->destination = (rooms + 6); //crystal cave
		(exit + j)->direction = south;

		//Dragon room!
		i = 8;
		strcpy_s((rooms + i)->name, "Dragon room");
		strcpy_s((rooms + i)->description, "WATCH OUT! There's a huge white dragon curled up in the middle of the room! He seems to be guarding a glowing blue orb. Its flaming red eyes are pointed on you, and from its nostrils there comes out some grey smoke. There's a closed door to your south.");

		j = 13;
		(exit + j)->origin = (rooms + 8);
		(exit + j)->destination = (rooms + 7); //dragon statue
		(exit + j)->direction = south;

		//Underground lake
		i = 9;
		strcpy_s((rooms + i)->name, "Underground lake");
		strcpy_s((rooms + i)->description, "A relatively small and shallow lake occupies this secondary cave. Luminescent plants submerge the cave in a strange greenish light. There's a passageway to the west and a bridge to the east, that crosses the lake. You can't see where it ends.");

		j = 14;
		(exit + j)->origin = (rooms + 9);
		(exit + j)->destination = (rooms + 6); //crystal cave
		(exit + j)->direction = west;

		j = 15;
		(exit + j)->origin = (rooms + 9);
		(exit + j)->destination = (rooms + 10); //catacombs
		(exit + j)->direction = east;

		//Catacombs
		i = 10;
		strcpy_s((rooms + i)->name, "Catacombs");
		strcpy_s((rooms + i)->description, "You can hear the wind whistling along the dark corridors of these catacombs. The only light comes from a lonesome torch, and the walls are lined with tombs carved in the stone wall and covered in faded smears of blood. There's a bridge to the west, a small wooden door to the east and a passageway to the north.\n");

		j = 16;
		(exit + j)->origin = (rooms + 10);
		(exit + j)->destination = (rooms + 11); //orb
		(exit + j)->direction = east;

		j = 17;
		(exit + j)->origin = (rooms + 10);
		(exit + j)->destination = (rooms + 12); //final room
		(exit + j)->direction = north;

		j = 18;
		(exit + j)->origin = (rooms + 10);
		(exit + j)->destination = (rooms + 9); //underground lake
		(exit + j)->direction = west;

		//Orb
		i = 11;
		strcpy_s((rooms + i)->name, "Orb");
		strcpy_s((rooms + i)->description, "In a pedestal in the middle of the room, lies another blue orb. The only exit is to the west.\n");

		j = 19;
		(exit + j)->origin = (rooms + 11);
		(exit + j)->destination = (rooms + 10); //catacombs
		(exit + j)->direction = west;

		//Arena
		i = 11;
		strcpy_s((rooms + i)->name, "Decaying arena");
		strcpy_s((rooms + i)->description, "This is a huge decaying, underground arena. Its flattened sand floor and its stone arches carved in the walls of the cavern give you chills. A hooded figure stands in the middle of the room. You can't exit this room.\n");


}