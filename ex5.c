#include <stdio.h>

/* this is a comment */
int main(int argc, char *argv[])
{
	int distance = 97;
	float power = 2.345f;
	double super_power = 54683.198536;
	char initial = 'D';
	char first_name[] = "Wesley";
	char last_name[] = "Madrigal";
	int hex = 0X33;
	int oct = 033;

	printf("You are %c miles away.\n", distance);
	printf("You are a number to the %f power.\n", power);
	printf("You are a super power %f.\n", super_power);
	printf("My first initial is %c.\n", initial);
	printf("My first name is %s.\n", first_name);
	printf("My last name is %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);	

	printf("first hexadicmal trial: %d.\n", hex);
	printf("first octal trial: %d.\n", oct);
	return 0;
}
