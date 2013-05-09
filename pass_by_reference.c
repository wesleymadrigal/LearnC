#include <stdio.h>
#include <stdlib.h>

void foo(int *x)
{
	*x = 0;
}

int main(void)
{
	int y = 10;
	foo(&y);
	printf("The value of y is now: %d\n", y);
	// y now = 0
}

