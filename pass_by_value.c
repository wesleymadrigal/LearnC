#include <stdlib.h>
#include <stdio.h>

void foo(int x)
{
	x = 0;
}

int main(void)
{
	int y = 10;
	foo(y);
	printf("The value of y is now: %d\n", y);
	// y still equals 10
}
