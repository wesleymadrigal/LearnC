#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)	{
		printf("ERROR: You need an argument.\n");
		return 1;
	}

	int i = 0;
	for(i=0; argv[1][i] != '\0'; i++)	{
		char letter = argv[1][i];
		// each of these cases is mapped out in the program by location	 
		switch(letter)	{
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;
			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;
			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;
			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;
			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;
			case 'y':
			case 'Y':
				if(i > 2){
					printf("%d: 'Y'\n", i);
				}
				break;
		}
	}
	
	// the below is a step ladder of if statements evaluating whether or not the current character
	// of the argument array is a vowel.  If it makes it down the ladder, a notification is 
	// printed
	int j = 0;
	for(j=0; argv[1][j] != '\0'; j++){
		char letter = argv[1][j];
		if(letter != 'a' && letter != 'A'){
		
			if(letter != 'e' && letter != 'E'){
		
				if(letter != 'i' && letter != 'I'){
		
					if(letter != 'o' && letter != 'O'){
		
						if(letter != 'u' && letter != 'U'){
	
							printf("Not a vowel: %c\n", letter);
						}
					}
				}
			}
		}		

	}			

	return 0;
}
