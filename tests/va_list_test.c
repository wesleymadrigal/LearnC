#include <stdio.h>  /* printf */
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

void printfloats(int n, ...)
{
	int i;
	double val;
	printf("Printing floats:");
	va_list vl;
	va_start(vl, n);
	for(i=0; i<n; i++)
	{
		val = va_arg(vl, double);
		printf(" [%.2f]\n", val);
		printf("The size of val is %d\n", sizeof(val));
		printf("The location of val is %p\n", &val);
	}
	va_end(vl);
}

int main()
{
	printfloats(3, 5.67890, 1.5777777);
	return 0;
}
