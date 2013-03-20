#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;
	while(i < argc){
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	char *states[] = {
		"Florida", "Illinois",
		"Missouri", "California"
	};
	

	int num_states = sizeof(states)/sizeof(int);
	int states_pos = num_states;
	int j = 0;
	for(j=1; j < argc; j++)	{
		states[states_pos] = "%s", argv[j];
		states_pos++;
	}
		
	i = 0;
	int new_states = sizeof(states)/sizeof(int);
	while(i < new_states)	{
		printf("iteration %d is %s.\n", i, states[i]);
		i++;
	}


	return 0;
}
