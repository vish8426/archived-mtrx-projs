#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

char *inputString(FILE* fp, size_t size)
{
	//The size is extended by the input with the value of the provisional
	char *str;
	int ch;
	size_t len = 0;
	str = realloc(NULL, sizeof(char)*size);
	//Size is start size
	if(!str)return str;
	while(EOF!=(ch=fgetc(fp)) && ch != '\n')
	{
		str[len++]=ch;
		if(len==size)
		{
			str = realloc(str, sizeof(char)*(size+=16));
			if(!str)return str;
		}
	}
	str[len++]='\0';

	return realloc(str, sizeof(char)*len);
}

int main(void)
{
	//Initialising Pointer
	char *m;
	
	//Start of Program & Intro Printing
	printf("Simple Calculator\n");
	start:
	printf(">>> ");
	
	//Setting up Pointer & Length 
	m = inputString(stdin, 10);
	int len = strlen(m);
	
	if(len == 1)
	{
		for(int i = 0; i < len; i++)
		{
			//Accounting for help in lower case
			if(strchr(m,'h') != NULL)
			{
				printf("Simple Calculator understands the following arithmetic operations:\n^ exponentiation\n+ addition\n- subtraction\n* multiplication\n/ division\n");
				goto start;
			}
			
			//Accounting for Help in upper case
			if(strchr(m,'H') != NULL)
			{
				printf("Simple Calculator understands the following arithmetic operations:\n^ exponentiation\n+ addition\n- subtraction\n* multiplication\n/ division\n");
				goto start;
			}
		}
	}
	
	//Accounting for quit in lower case
	if(strchr(m,'q') != NULL)
	{
		printf("Goodbye!\n");
		exit(0);
	}
	
	//Accounting for Quit in upper case
	if(strchr(m,'Q') != NULL)
	{
		printf("Goodbye!\n");
		exit(0);
	}
	
	//Setting Pointer to a Character Array
	char stringArray[len];
	strncpy(stringArray, m, sizeof(m));
	
	//Accounting for an empty input
	if(stringArray[0] == ' ')
	{
		printf("Error: Illegal input!\n");
		goto start;
	}
	for(int i = 0; i < len; i++)
	{
		//Accounting for inputting invalid characters
		//Alphabets:
		if(isalpha(stringArray[i]) != NULL)
		{
			printf("Error: Illegal input!\n");
			goto start;
		}
		//Allowing Operators & Digits:
		if(isdigit(stringArray[i]) != NULL && isdigit(stringArray[i+2]) != NULL)
		{
			printf("Error: Illegal input!\n");
			goto start;
		}
		
	}
	for(int j = 0; j < len; j++)
	{
		//Checking for addition operators
		if(stringArray[j] = '+')
		{
			float value1 = 0; 
			float value2 = 0; 
			sscanf(m,"%f + %f",&value1, &value2);
			float addition = value1 + value2;
			printf("%.3f\n", addition);
			break;
		}
	}
	for(int j = 0; j < len; j++)
	{
		//Checking for subtraction operators
		if(stringArray[j] = '-')
		{
			float value3 = 0; 
			float value4 = 0; 
			sscanf(m,"%f - %f",&value3, &value4);
			float subtraction = (value3 - value4);
			printf("%.3f\n", subtraction);
			break;
		}
	}
	for(int j = 0; j < len; j++)
	{
		//Checking for multiplication operators
		if(stringArray[j] = '*')
		{
			float value5 = 0; 
			float value6 = 0; 
			sscanf(m,"%f * %f",&value5, &value6);
			float multiplication = value5 * value6;
			printf("%.3f\n", multiplication);
			break;
		}
	}
	for(int j = 0; j < len; j++)
	{
		//Checking for exponential operators
		if(stringArray[j] = '^')
		{
			float base = 0; 
			float exponent = 0;
			long long result = 1;
			sscanf(m,"%f ^ %f",&base, &exponent);
			//Accounting for undefined exponential output.
			if(base == 0 && exponent == 0)
			{
				printf("Error: Illegal input!\n");
				goto start;
			}
			//Calculating the power of numbers inputted.
			while(exponent != 0)
			{
				result *= base;
				--exponent;
			}
			printf("%.3f\n", result);
			break;
		}
	}
	for(int j = 0; j < len; j++)
	{
		//Checking for division operators
		if(stringArray[j] = '/')
		{
			float dividend = 0;
			float divisor = 0; 
			sscanf(m,"%f / %f",&dividend, &divisor);
			//Check if the output of dividing by zero is undefined.
			if(divisor == 0)
			{
				printf("Error: Divide by zero!\n");
				goto start;
			}
			//Calculating the division of numbers inputted.
			float division = dividend * divisor;
			printf("%.3f\n", division);
			break;
		}
	}
	//Jump to Start of Program
	goto start;
	free(m);
}