#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *file;
	file = fopen("test.txt", "r");
	int c;
	do	{
		// for each character in the file, get it
		c = fgetc(file);
		// and pipe it over to stdout
		fputc(c, stdout);
		}	while (c != EOF);
	fputc('\n', stdout);
	return 0;
}
