#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
	if(errno)	{
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

int main(int argc, char *argv[])
{

	int *numbers = malloc(argc-1 * sizeof(int));

	int i = 0;
	int j = 0;
	int temp = 0;
	for(i = 1; i < argc; i++)
	{
		numbers[i-1] = atoi(argv[i]);
	}

	for(i = 0; i < argc-1; i++)
	{
		for(j = 0; j < argc-2; j++)
		{
			if(numbers[j] > numbers[j+1])
			{
				temp = numbers[j+1];
				numbers[j+1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}

	for(i=0; i < argc-1; i++)
	{
		printf("Sorted %d\n", numbers[i]);
	}
			
	free(numbers);
	return 0;
}
				
