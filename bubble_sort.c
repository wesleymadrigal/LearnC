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


int *bubble_sort(int count, int *numbers)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count-1; j++)
		{
			if(numbers[j] > numbers[j+1])
			{
				temp = numbers[j+1];
				numbers[j+1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}

	for(i=0; i < count; i++)
	{
		printf("Sorted %d\n", numbers[i]);
	}
	
	return 0;
}

int find_min(int count, int to_be_bigger_than, int *numbers)
{
	int foo = numbers[0];
	int i = 0;
	for(i=0; i < count; i++)
	{
		if(numbers[i] < foo && numbers[i] > to_be_bigger_than)
		{
			foo = numbers[i];
		}
	}
	
	printf("The minimum greater than %d is %d.\n", to_be_bigger_than, foo);

	return 0;
} 
	
	 

int main(int argc, char *argv[])
{
	int count = argc-1;
	int i = 0;
	int *numbers = malloc(count * sizeof(int));

	for(i = 1; i < argc; i++)
	{
		numbers[i-1] = atoi(argv[i]);
	}

	bubble_sort(count, numbers);
	find_min(count, 3, numbers);
	
	free(numbers);
	return 0;
}
				
