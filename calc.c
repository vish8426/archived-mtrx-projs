//Trigonometric Calculator

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define False (!TRUE)

int main(void)
{
	//Initiatng Variables
	int a,i = 5,j = 0;
	int introws;
	float strval,finval;
	char input[i];
	
	//Boot Text
	printf("TRIG: the trigonometric calculator\n");
	
	//Start of Program
	start:
	printf("\nPlease input request (h-help, q-quit): ");
	scanf("%s",&input[i]);
	
	//Test for 'h'
	if (input[i] == 'h')
	{
		printf("\nThe input format is a single line of letters and numbers comprising the\nfollowing fields:\n");

		printf("\n <types> <start-value> <final-value> <intermediate-rows>\n");

		printf("\nThese fields must be input in the order shown above, where <types>\nis a set of letters, and the others are single numbers defining\nthe range of computation.\n");

		printf("\nThe <types> field consists of zero or more of the letters from the set\n<stcdr>, which indicate respectively,\n");

		printf("\n (1) The desired trig functions: sin, tan, cos.\n");
		printf(" (2) Whether to use degrees or radians for input parameters.\n");
		printf(" (3) Whether to quit the program.\n");

		printf("\nExample input: scr 0 2.3 3\n");
		
		goto start;
	}
	//Test for 'q'
	else if (input[i] == 'q')
	{
		exit(1);
	}
	else if (input[5] == 115 || input[5] == 99 || input[5] == 116 || input[5] == 100 || input[5] == 114 ||
			 input[4] == 115 || input[4] == 99 || input[4] == 116 || input[4] == 100 || input[4] == 114 ||
			 input[3] == 115 || input[3] == 99 || input[3] == 116 || input[3] == 100 || input[3] == 114 || 
			 input[2] == 115 || input[2] == 99 || input[2] == 116 || input[2] == 100 || input[2] == 114 || 
			 input[1] == 115 || input[1] == 99 || input[1] == 116 || input[1] == 100 || input[1] == 114)
	{
		scanf("%f%f%d",&strval,&finval,&introws);
	}
	else
	{
		printf("\nError: Illegal input!\n");
		goto start;
	}
	
	if (input[i] == 'r')
	{
		goto radians;
	}
	else if (input[i] == 'd')
	{
		goto degrees;
	}
	else if (input[i] == "dr" || "rd")
	{
		printf("\nError: Illegal input!\n");
		goto start;
	}
	else
	{
		goto degrees;
	}
	
	radians:
	while ( a < (introws + 2))
	{	
		printf("\n   Degrees\tRadians\t\tSin\t\tCos\t\tTan\n");
		printf("\n");
		float rad = (((finval-strval)/(introws + 1))*j);
		float deg = ((180/3.14159) * rad);
		float sine = sin(rad);
		float cosine = cos(rad);
		float tangent = tan(rad);
		j = j + 1;
		printf("%10.3f%13.3f%12.3f%16.3f%16.3f\n",deg,rad,sine,cosine,tangent);
		a++;
	}
	
	degrees:
	while ( a < (introws + 2))
	{	
		printf("\n   Degrees\tRadians\t\tSin\t\tCos\t\tTan\n");
		printf("\n");
		float deg = (((finval-strval)/(introws + 1))*j);
		float rad = ((3.14159/180)*deg);
		float sine = sin(deg);
		float cosine = cos(deg);
		float tangent = tan(deg);
		j = j + 1;
		printf("%10.3f%13.3f%12.3f%16.3f%16.3f\n",deg,rad,sine,cosine,tangent);
		a++;
	}
	goto start;
}