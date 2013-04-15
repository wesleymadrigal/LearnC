#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "ex19.h"

int Monster_attack(void *self, int damage)
{
	Monster *monster = self;
	assert(monster != NULL);
	// _(description) calls the macro proto.N
	printf("You attack %s!\n", monster->_(description));
	monster->hit_points -= damage;
	
	if(monster->hit_points > 0) {
		printf("It is still alive with %d life left.\n", monster->hit_points);
		return 0;
	} else {
		printf("The monster is dead.\n");
		// return 1; aborts game
		return 0;
	}
}

int Monster_init(void *self)
{
	Monster *monster = self;
	assert(monster != NULL);
	monster->hit_points = 20;
	return 1;
}


// override object.h functions and object.c base funcitons
Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack
};

void *Room_move(void *self, Direction direction)
{
	Room *room = self;
	assert(room != NULL);
	Room *next = NULL;

	if(direction == NORTH && room->north) {
		printf("You go north, into:\n");
		next = room->north;
	} else if(direction == SOUTH && room->south) {
		printf("You go south, into:\n");
		next = room->south;
	} else if(direction == EAST && room->east) {
		printf("You go east, into:\n");
		next = room->east;
	} else if(direction == WEST && room->west) {
		printf("You go west, into:\n");
		next = room->west;
	} else {
		printf("You can't go that direction.");
		next = NULL;
	}
	if(next) {
		next->_(describe)(next);
	}
	return next;
}


int Room_attack(void *self, int damage)
{
	Room *room = self;
	assert(room != NULL);
	Monster *monster = room->bad_guy;
	assert(monster != NULL);
	if(monster) {
		monster->_(attack)(monster,damage);
		return 1;
	} else {
		printf("You pointlessly attack at nothing, baffoon.\n");
		return 1;
	}
}

int Map_attack(void *self, int damage)
{
        Map* map = self;
        Room *location = map->location;
        assert(map != NULL && location != NULL);
        return location->_(attack)(location, damage);
}


Object RoomProto = {
	.move = Room_move,
	.attack = Room_attack
};

void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;
	assert(map != NULL && location != NULL);
	next = location->_(move)(location, direction);

	if(next) {
		map->location = next;
	}

	return next;
}

int Map_attack(void *self, int damage)
{
	Map* map = self;
	Room *location = map->location;
	assert(map != NULL && location != NULL);
	return location->_(attack)(location, damage);
}

int Map_init(void *self)
{
	Map *map = self;
	// make some room for small map
/*
	Room *hall = NEW(Room, "The great Hall");
	Room *dungeon = NEW(Room, "The dark dungeon with the minotaur");
	Room *chambers = NEW(Room, "The Upper Chambers");
	Room *arena = NEW(Room, "The arena");
*/

	Room *hall = Object_new(sizeof(Room), RoomProto, "The great hall");
	Room *dungeon = Object_new(sizeof(Room), RoomProto, "The dark dungeon with the minotaur");
	Room *chambers = Object_new(sizeof(Room), RoomProto, "The Upper Chambers");
	Room *arena = Object_new(sizeof(Room), RoomProto, "The arena");
	Room *atrium = Object_new(sizeof(Room), RoomProto, "The atrium of knights of old");
	Room *atrium_skydeck = Object_new(sizeof(Room), RoomProto, "The atrium of dragons.");
	Room *antigravity = Object_new(sizeof(Room), RoomProto, "The antigravity room, all is weightless here.");
	// put bad guy in dungeon
	// dungeon->bad_guy = NEW(Monster, "The ferocious minotaur");
	dungeon->bad_guy = Object_new(sizeof(Monster), MonsterProto, "The ferocious minotaur");
	antigravity->bad_guy = Object_new(sizeof(Monster), MonsterProto, "The evil floating scientist.");
	atrium_skydeck->bad_guy = Object_new(sizeof(Monster), MonsterProto, "The firebreathing beast of old");

	// setup map rooms
	hall->north = dungeon;
	dungeon->west = chambers;
	dungeon->east = arena;
	dungeon->south = hall;
	dungeon->north = atrium;
	atrium->east=atrium_skydeck;
	atrium->north=antigravity;
	atrium_skydeck->west=atrium;
	atrium_skydeck->south=arena;
	antigravity->south=atrium;
	arena->north=atrium_skydeck;

	chambers->east = dungeon;
	arena->west = dungeon;

	// start map and character off in hall
	map->start = hall;
	map->location = hall;

	return 1;
}

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

int process_input(Map *game)
{
	printf("\n> ");
	char ch = getchar();
	getchar(); // ENTER
	
	int damage = rand() % 4;

	switch(ch) {
		case -1:
			printf("Giving up? You blow.\n");
			return 0;
			break;
		
		case 'n':
			//game->_(move)(game, NORTH);
			game->proto.move(game, NORTH);
			break;

		case 's':
			//game->_(move)(game, SOUTH);
			game->proto.move(game, SOUTH);
			break;
		
		case 'e':
			//game->_(move)(game, EAST);
			game->proto.move(game, EAST);
			break;

		case 'w':
			//game->_(move)(game, WEST);
			game->proto.move(game, WEST);
			break;

		case 'a':
			//game->_(attack)(game, damage);
			game->proto.attack(game, damage);
			printf("%d damage inflicted on enemy.\n", damage);
			break;
		case 'l':
			printf("You can go:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east) printf("EAST\n");
			if(game->location->west) printf("WEST\n");
			break;

		default:
			printf("What?: %d\n", ch);
	}
	
	return 1;
}

int main(int argc, char *argv[])
{
	// simple way to setup randomness
	srand(time(NULL));

	// make our map to work with
	Map *game = NEW(Map, "The dungeon with the minotaur.");

	printf("You enter the ");
	game->location->_(describe)(game->location);
		
	while(process_input(game)) {
	}

	return 0;
}

