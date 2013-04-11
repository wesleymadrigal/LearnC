#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("First n: %d\n", rand()%1000);
	srand (time(NULL));
	printf("Rand n: %d\n", rand()%1000);
	srand (1);
	printf("Again first number: %d\n", rand()%1000);

	return 0;
}
