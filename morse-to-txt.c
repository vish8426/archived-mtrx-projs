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
	//Initializing character arrays
	char string[MAX][SIZE];
	char destination[MAX] [MAX][8];
	
	//Initializing Morse code character array
	char *input[38]={".-","-...","-.-.","-..",".","..-.","--.",
					 "....","..",".---","-.-",".-..","--","-.",
					 "---",".--.","--.-",".-.","...","-","..-",
					 "...-",".--","-..-","-.--","--..","-----",
					 ".----","..---","...--","....-",".....",
					 "-....","--...","---..","----.","/"};
	
	//Initializing alphabet and number character array
	char *output[38]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
				   	"P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3",
					"4","5","6","7","8","9"," "};
	
	//Initializing separator 
	char *code, *separator = " ";
	
	//Initializing loop values, array to copy
	int i, k, j;
	int arraycpy[MAX];
	
	//Printing out introductory text
	printf("Welcome to the Morse translator.\n");
	printf("Enter input: ");
	
	//Loop through inputted string
	int l = 1;
	for(i=0; i<l; i++)
	{
		gets(string[i]);
	}
	
	for(i=0,j=0;i<l;++i)
	{
		//Loop to copy the inputted string into a character array
		for(code = strtok(string[i], separator);code != NULL;code = strtok(NULL, separator))
		{
			strcpy(destination[i][j++], code);
		}
		arraycpy[i] = j;
	}
	
	for(i=0;i<l;i++)
	{
		//Loop through copied string 
		for(j=0; j<arraycpy[i]; j++)
		{	
			//Loop through morse code array
			for(k=0; k<37; k++)
			{
				//Compare input to morse code array 
				if(strcmp(destination[i][j], input[k])==NULL)
				{
					//Print morse code
					printf("%s",output[k]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}