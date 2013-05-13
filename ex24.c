#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];	
	EyeColor eyes;
	float income;
} Person;

int main(int argc, char *argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;

	// prompts user to type first name and copies it to you.first_name
	printf("What is your first name? ");
	in = fgets(you.first_name, MAX_DATA-1, stdin);
	//in = gets(you.first_name);
	//in = fscanf(stdin, "%50s", you.first_name);
	
	check(in != NULL, "Failed ot read the first name.");

	printf("What's your Last Name? ");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	//in = fscanf(stdin, "%50s", you.last_name);
	//in = gets(you.last_name);
	check(in != NULL, "Failed to read last name.");
	
	printf("How old are you? ");
	//int rc = fscanf(stdin, "%d", &you.age);
	char the_n[100];
	fgets(the_n, 100, stdin);
	int rc = atoi(the_n);
	you.age = rc;
	check(rc > 0, "You have to enter a number.");

	printf("What color are your eyes:\n");
	for(i = 0; i <= OTHER_EYES; i++) {
		printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	}
	printf("> ");

	//int eyes = -1;
	//rc = fscanf(stdin, "%d", &eyes);

	char the_cur_n[100];
	fgets(the_cur_n, 100, stdin);
	int eyes = atoi(the_cur_n);
	you.eyes = eyes;
	check(rc > 0, "You have to enter a number.");
	
	// Make sure input is a valid option: otherwise we will have a segmentation fault
	you.eyes = eyes - 1;
	//check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");

	printf("How much do you make an hour? ");
	//rc = fscanf(stdin, "%f", &you.income);
	char inc[100];
	fgets(inc, 100, stdin);
	float income = atoi(inc);
	you.income = income;
	
	check(rc > 0, "Enter a floating point number.");

	printf("----- RESULTS -----\n");

	printf("First Name: %s", you.first_name);
	printf("Last Name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);

	return 0;
error:
	return -1;
}
