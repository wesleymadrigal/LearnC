#include <stdio.h>
#include <string.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
	char test1[1000] = {'y'};
	char *ptest1 = test1;
	memset(test1, 1000, 'y');

	int i = 0;
	for(i = 0; i < 10; i++)
	{
		printf("The pointer value is %d\n", *ptest1++);
	}
	
	return 0;
}
