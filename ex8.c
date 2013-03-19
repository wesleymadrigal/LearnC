#include <stdio.h>

int main(int argc, char *argv[])
{

	char full_name[] = {
                'W', 'e', 's', 'l', 'e', 'y', ' ',
                'D', '.', ' ',
                'M', 'a', 'd', 'r', 'i', 'g', 'a', 'l'
                };

	int areas[] = {10, 12, 13, 14, 'W'};
	char name[] = "Wes";
	// On some systems may have to change
	// %ld to %u since some unsigned ints
	printf("The size of an int: %u\n", sizeof(int));
	printf("The size of areas (int[]): %u\n", sizeof(areas));
	printf("The number of ints in areas: %u\n", sizeof(areas)/sizeof(int));
	printf("The first area is: %d, the 2nd %d.\n", areas[4], areas[1]);
	printf("The size of a char: %u\n", sizeof(char));
	printf("The size of name (char[]); %u\n", sizeof(name));
	printf("The number of chars: %u\n", sizeof(name)/sizeof(char));
	printf("The size of full name (char[]): %u\n", sizeof(full_name));
	printf("The number of chars: %u\n", sizeof(full_name)/sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

	return 0;
}
