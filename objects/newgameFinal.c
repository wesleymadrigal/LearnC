#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "newgame.h"


int main(int argc, char *argv[])
{

	srand(time(NULL));

	//Map *game = NEW(Map, "The dark dungeon");
	Map *game = MapMake;
	game->location->_(describe)(game->location);
	
	while(process_input(game)){
	}

	return 0;
}
