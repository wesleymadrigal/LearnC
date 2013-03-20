#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	// go through each string in argv
	for(i = 1; i < argc; i++)	{
		printf("arg %d: %s\n", i, argv[i]);
	}
	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Illinois"
	};
	int num_states = 4;

	for(i = 0; i < num_states; i++)	{
		printf("state %d: %s\n", i, states[i]);
	}

	return 0;
}

/*  * 	The OS passes each command line argument as string into the argv array.  The program's name (./ex10) is at 0,
	which is why we start the for initializer at place i = 1 instead of 0 for argv
    *	OS also sets argc to # args in argv array so you can process w/out going past end.
	
*/
