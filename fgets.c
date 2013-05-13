#include <stdio.h>
#include "dbg.h"


int main(int argc, char *argv[])
{
	int MAX_DATA = 100;
	char *in = NULL;
	char first_name[MAX_DATA];
	in = fgets(first_name, MAX_DATA-1, stdin);

	printf("His name is: %s\n", in);

	return 0;
}
