#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void die(const char *message)
{
	if(errno){
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
}

int main() {
	FILE *pfile;
	long lsize;
	char * buffer;
	size_t result;

	pfile = fopen("test.txt", "rb");
	if (pfile == NULL) {
		fputs("File error", stderr);
		exit(1);
	}

	// obtain file size
	fseek(pfile, 0, SEEK_END);
	lsize = ftell(pfile);
	rewind(pfile);

	// allocate memory to contain whole file
	buffer = (char*) malloc (sizeof(char)*lsize);
	if(buffer == NULL)
	{
		fputs("Memory error", stderr);
		exit(2);
	}
	printf("Size of my text file: %ld\n", lsize);

	result = fread(buffer, 1, lsize, pfile);
	if(result != lsize)
	{
		fputs("Reading error", stderr);
		exit(3);
	}
	
	printf("The contents of my text file: %s\n", buffer);

	fclose(pfile);
	free(buffer);
	return 0;
}
