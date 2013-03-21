#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	
	int product = 0;
	for(i=1; i < argc; i++)
	{
		if(i == 1)
		{
			int first = (int)argv[i];
			printf("The first %d.\n", first);
			//product = product + (int)argv[i];
		}
		else
		{
			int cur = (int)argv[i];
			printf("The %d.\n", cur);
			//product = product * (int)argv[i];
		}
	}

	printf("The product of the numbers is %d.\n", product);

	return 0;
}
