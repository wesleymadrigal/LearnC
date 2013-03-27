#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>


struct Person	{
	char name;
	char location;
	int age;
	int height;
};



void Person_create(struct Person *per, char name, char location, int age, int height)
{


	per->name = name;
	per->location = location;
	per->age = age;
	per->height = height;

	printf("The person's name is %s.\n", per->name);
	printf("%s lives in %s.\n", per->name, per->location);
	printf("%s is %d years old.\n", per->name, per->age);
	printf("%s is %d inches tall.\n", per->name, per->height);

}


int main(int argc, char *argv[])
{

	if(argc < 4)
	{
		printf("Too few arguments to person.  Person takes a name, location, age, and height");
		exit(1);
	
	} else if(argc == 5)
	{

		struct Person *per = malloc(sizeof(Person));
		
		char name = argv[1];
		char location = argv[2];
		int age = argv[3];
		int height = argv[4];

		return Person_create(per, name, location, age, height);
	}
	
	return 0;
}

	
