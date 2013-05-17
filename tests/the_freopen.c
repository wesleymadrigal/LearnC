#include <stdio.h>

int main()
{
	freopen("test.txt", "w", stdout);
	printf("Let's see if this ends up in text.txt");
	fclose(stdout);
	return 0;
}
