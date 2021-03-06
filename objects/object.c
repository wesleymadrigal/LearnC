#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
	Object *obj = self;
	
	assert(obj != NULL);
	if(obj)
	{
		if(obj->description) free(obj->description);
		free(obj);
	}
}

void Object_describe(void *self)
{
	Object *obj = self;
	assert(obj != NULL);
	printf("%s.\n", obj->description);
}

int Object_init(void *self)
{
	// do nothing
	return 1;
}

void *Object_move(void *self, Direction direction)
{
	assert(direction != NULL);
	printf("You can't go in that direction.\n");
	return NULL;
}

int Object_attack(void *self, int damage)
{
	assert(damage != NULL);
	printf("You can't attack that.\n");
	return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
	// setup default functions in case they aren't set
	if(!proto.init) proto.init = Object_init;
	if(!proto.describe) proto.describe = Object_describe;
	if(!proto.destroy) proto.destroy = Object_destroy;
	if(!proto.attack) proto.attack = Object_attack;
	if(!proto.move) proto.move = Object_move;

	// cannot make a struct of one size, then point a different pointer at it to "cast" it
	Object *el = calloc(1, size);
	assert(el != NULL);
	*el = proto;

	// copy description over
	el->description = strdup(description);

	// initialize it with init
	if(!el->init(el)){
		// didn't initialize properly
		el->destroy(el);
		return NULL;
	} else {
		// all done and we have made an object
		return el;
	}
}

