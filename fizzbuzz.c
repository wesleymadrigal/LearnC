#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	for(i=0; i < 100; i++)
	{
		if((i%3) == 0)
		{
			printf("Fizz: %d\n", i);
		} 
		else if((i%5) == 0)
		{
			printf("Buzz: %d\n", i);
		}
		else if(((i%3) != 0 && (i%5) != 0))
		{
			printf("FizzBuzz!!!: %d\n", i);
		}
	}

	return 0;
}
		
