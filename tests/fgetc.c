#include <stdio.h>

int main()
{
	FILE * pFile;
	int **wes = 2;
	int c;
	int n = 0;
	pFile = fopen("fgetcTest.txt", "r");
	if (pFile == NULL) perror("Error opening file.");
	else
	{
		do	{
			c = fgetc(pFile);
			if (c == 'W' || c == 'w') n++;
			} while (c != EOF);
		fclose(pFile);
		printf("The file contains %d W and w's.\n", n);
		printf("The address of wes is %p.\n", &wes);
		printf("The value of wes is %d.\n", wes);
		printf("The size of wes is %d.\n", sizeof(wes));
		wes = 500;
		printf("The value of wes is now %d.\n", wes);
	}
	return 0;
}
	
