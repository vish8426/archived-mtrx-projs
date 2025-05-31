#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>

//Initializing macros
#define MAX 100
#define SIZE 255

int main()
{
	//Initializing Morse code character array
	char *morse[] = {".-","-...","-.-.","-..",".","..-.","--.",
					 "....","..",".---","-.-",".-..","--","-.",
					 "---",".--.","--.-",".-.","...","-","..-",
					 "...-",".--","-..-","-.--","--..","-----",
					 ".----","..---","...--","....-",".....",
					 "-....","--...","---..","----.","/"};
	
	//Initializing alphabet and number character array
	char alph[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	
	char inbuf[BUFSIZ];
    int numchars = strlen(alph);
	
	int i, j;
    int iL;
	
	printf("Welcome to the Morse translator.\n");
    printf("Enter input: ");
    fgets(inbuf, BUFSIZ, stdin);

    iL = strlen(inbuf) - 1;

    for (i = 0; i < iL; i++) 
	{
        inbuf[i] = toupper(inbuf[i]);
    }
	
	for (i = 0; i < iL; i++)
	{
		if(isalpha(inbuf[i]) || isdigit(inbuf[i]))
		{
			goto translation;
		}
		else
			printf("Invalid input!\n");
			break;
			exit(0);
	}
	
	translation:
    for (i = 0; i < iL; i++) 
	{
		if(inbuf[i] == ' ')
			printf(" / ");
        else
            for (j = 0; j <= numchars; j++) 
			{
                if (inbuf[i] == alph[j]) 
				{
                    printf("%s ", morse[j]);
                    break;
                }
            }
    }
	printf("\n");
    return 0;
}