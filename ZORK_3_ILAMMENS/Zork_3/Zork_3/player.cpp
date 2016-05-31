#include "player.h"
#include "world.h"
#include "exit.h"
#include <stdio.h>
#include "item.h"

World* catacombs;
int i;

void Player::move(dir direction)
{

	for (i = 0; i < 20; i++)
	{
		if ((loc == (((Exit*)catacombs->entities[i])->origin)) && (((Exit*)catacombs->entities[i])->direction) == direction) //runs trough all the exits until origin and direction match
		{
			if (((Exit*)catacombs->entities[i])->door_state == OPEN)
			{
				//set new position
				(loc) = (((Exit*)catacombs->entities[i])->destination);
				printf("%s", (((Exit*)catacombs->entities[i]))->destination);
				printf("You went north. You are now here: %s\n", ((loc)->name));
				printf("%s\n", (loc)->description);
				break;
			}

			else if (((Exit*)catacombs->entities[i])->door_state == CLOSED)
			{
				printf("The door is locked. You need to open it first.\n");
				break;
			}
		}
	}
}

void Player::look_here()
{
	printf("You are now here: %s\n", loc->name);
}

void Player::look(dir direction)
{
	for (i = 0; i < 20; i++)
	{
		if (((loc) == (((Exit*)catacombs->entities[i])->origin)) && (((Exit*)catacombs->entities[i])->direction) == direction)
		{
			printf("To the north there is: %s", (((Exit*)catacombs->entities[i])->destination)); //prints north room name
			break;
		}
	}
}

void Player::open(dir direction)
{
	for (i = 0; i < 20; i++)
	{
		if (((((Exit*)catacombs->entities[i])->door_state) == CLOSED) && ((Exit*)catacombs->entities[i])->destination == loc) //opens temple -> bow room
		{
			(((Exit*)catacombs->entities[i])->door_state) = OPEN; //changes door state
			printf("You unlocked the door.\n");
			break;
		}

		else
			printf("The door is already open.\n");
	}
}

void Player::close(dir direction)
{
	for (i = 0; i < 20; i++)
	{
		if (((((Exit*)catacombs->entities[i])->door_state) == OPEN) && ((Exit*)catacombs->entities[i])->destination == loc) //opens temple -> bow room
		{
			(((Exit*)catacombs->entities[i])->door_state) = CLOSED; //changes door state
			printf("You locked the door.\n");
			break;
		}

		else
			printf("The door is already closed.\n");

	}
}

void Player::take(String items)
{
	if (used < max)
	{
		for (i = 0; i < 20; i++)
		{
			if (((Item*)catacombs->entities[i])->origin == loc && ((Item*)catacombs->entities[i])->invent == false)
			{
				((Item*)catacombs->entities[i])->invent == true;
				printf("%s has been added to your bag.\n");
			}
		}
	}
}

