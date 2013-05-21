#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c;
	int i = 0;
	FILE *the_file;
	FILE *file;
	file = fopen("test.txt", "w");

	for(i = 1; i < argc; i++)
	{
		fprintf(file, "%s", argv[i]);
	}
	fclose(file);	
	printf("Stdin written to test.txt\n");
	
	the_file = fopen("test.txt", "r");
	
	do
	{
		c = fgetc(the_file);
		fputc(c, stdout);
	} while(c != EOF);
	fputc('\n', stdout);
	

	return 0;
}
	
