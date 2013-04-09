#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
	if(errno)
	{
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

typedef int (*math)(int a, int b);

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a/b;
}

int modulus(int a, int b)
{
	return a % b;
}


void test_methods(int a, int b, math func)
{
	printf("The result of applying method to %d and %d is: %d\n", a, b, func(a, b));
}

int main(int argc, char *argv[])
{

	if(argc != 3)
	{
		printf("ERROR: Only two numbers as arguments\n");
	} else {
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		test_methods(a, b, multiply);
		test_methods(a, b, divide);
		test_methods(a, b, modulus);
		
	}

	return 0;
}		
		
