#ifndef _object_h
#define _object_h

typedef enum{
	NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct{
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, Direction direction);
	int (*attack)(void *self, int damage);
} Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

// makes macro for short version of normal way we call Object_new and avoids potential
// errors with calling it wrong.  T and N parameters are injected into line of code on the right
// syntax T##Proto says "concat Proto at end of T", so if had NEW(Room, "Hello.") the it'd make RoomProto there.
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
// syntactic sugar for object system and helps write obj->prot.blah as simply as obj->_(blah).
// not necessary, but a trick
#define _(N) proto.N

#endif
