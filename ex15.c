#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get sizes of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	// first way using indexing
	for(i = count-1; i > -1; i--)	{
		printf("%s has %d years alive.\n", *(names+i), *(ages+i));
	}

	printf("---\n");

	// setup the pointes to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for(i=count-1; i > -1; i--)	{
		printf("%s is %d years old again.\n",
			*(cur_name+i), *(cur_age+i));
	}
	printf("---\n");

	// third way, pointers are just arrays

	for(i = count-1; i > -1; i--)	{
		printf("%s is %d years old again.\n",
			cur_name[i], cur_age[i]);
	}

	printf("---\n");

	//fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age=ages; (cur_age-ages) < count; cur_name++, cur_age++)
	{
		printf("%s live %d years so far.\n",
			*cur_name, *cur_age);
	}

	printf("%p\n", *cur_age);
	printf("%p", *cur_name);

	return 0;
}
