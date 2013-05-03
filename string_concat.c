#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

	char string1[80];

	int i = 0;
	for(i=1; i < argc; i++)
	{
		strcat(string1, argv[i]);
	}

	printf("%s", string1);

	return 0;
}
