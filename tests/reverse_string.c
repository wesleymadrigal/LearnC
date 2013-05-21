#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	if(argc > 2)
	{
		printf("[ERROR] The reverse_string program only takes one string as an argument.\n");
		exit(1);
	} else if (argc == 1) {
		printf("[ERROR] The reverse_string program takes one string as an argument.\n");
		exit(1);
	}
	
	int i = 0;
	int c;

	FILE *new;
	new = fopen("new.txt", "w");
	int size = strlen(argv[1]);

	for(size = size-1; size >= i; size--)
	{
		char c = argv[1][size];
		fputc(c, new);
	}

	fclose(new);

	FILE *reversed;
	reversed = fopen("new.txt", "r");
	do	{
		c = fgetc(reversed);
		fputc(c, stdout);
		}
			while(c != EOF);
	printf("\n");
	
	return 0;
}
