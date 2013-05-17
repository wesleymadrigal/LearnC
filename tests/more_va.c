#include <stdio.h>
#include <stdarg.h>

int use_va(int n, ...)
{
	int i;
	int val;
	va_list vl;
	// initialize the va_list vl object
	va_start(vl, n);
	for(i=0; i<n; i++)
	{
		val = va_arg(vl, int);
		printf("The current iteration's value in va_list is: %d and it's size is %d\n", val, sizeof(val));
	}

	return 0;
}


int main(int argc, char *argv[])
{

	use_va(3, 2, 3);

	return 0;
}
