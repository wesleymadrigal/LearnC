#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	for(i=1; i < argc; i++){
		printf("Argument %d: %s.\n", i, argv[i]);
	}

	int n = 0;

	for(n = 0; n < 100; n++)
	{
		if((n % 2) == 0){
			printf("%d: fizz\n", n);
		}
		else if((n % 3) == 0){
			printf("%d: buzz\n", n);
		}
		else if((n % 3) == 0 && (n % 5) == 0){
			printf("%d: fizzBuzz\n", n);
		}
	}

	return 0;
}
