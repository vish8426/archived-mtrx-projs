#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "shape.h"

int main(int argc, char **argv)
{
	printf("SHAPES: The shape printer\n");
	
	char shape[1];
	int height,width,levels,thickness,runCount = 0;
	
	start:
	//Test if the program has successfully been run more than once.
	//Print the default menu if the program has been run just once.
	if(runCount==0)
	{
		printf("Please select a shape from the following list:\n - (t) right-angled triangle\n - (s) square\n - (r) rectangle\n - (p) triangular pyramid\n");
	}
	//Decide to print the (q) - quit option if program has been run through once already.
	else
	{
		printf("Please select a shape from the following list:\n - (t) right-angled triangle\n - (s) square\n - (r) rectangle\n - (p) triangular pyramid\n - (q) quit from SHAPES.\n");
	}
	scanf("%s",&shape[0]);
	
	//Test if the user has selected (q) - quit the program.
	if(shape[0]=='q' && runCount>0)
	{
		return 0;
	}
	
	//Test if user input is a valid alphabet character and not an integer.
	while(isalpha(shape[0])==0)
	{
		printf("Invalid input.\nPlease select a shape from the following list:\n - (t) right-angled triangle\n - (s) square\n - (r) rectangle\n - (p) triangular pyramid\n");
		scanf("%s",&shape[0]);
	}
	
	//Go through the user input 'shape' and test that the saved string is one of the menu choices. 
	int length,i = 0,count = 0;
	char array[4] = "tsrp";
	
	length = strlen(array);
	
	while(i<length)
	{
		if(array[i] == shape[0])
		{
			count = count + 1;
		}
		i++;
	}
	if(count==0)
	{
		printf("Invalid input.\n");
		goto start;
	}
	//This point in the code is to check for height.
	//If height is not a valid input the program will loop back here.
	error:
	printf("What height should the shape be?\n");
	//Test if height is an integer.
	while(scanf("%d",&height)!=1)
	{
		printf("Invalid input.\n");
		printf("What height should the shape be?\n");
		scanf("%*s");
	}
	//Test for conditions specified for valid height input.
	if(height<1 || (height<2 && shape[0]=='p'))
	{
		printf("Invalid input.\n");
		goto error;
	}
	//------------------------------------------------------
	//Shapes can now be specified and printed at this point.
	//TRIANGLE
	if(shape[0]=='t')
	{
		//This point in the code for the triangle, the user is asked for border thickness.
		//If border is not valid input the program will loop back here.
		errorBorder1:
		printf("What thickness should the border have?\n");
		while(scanf("%d",&thickness)!=1)
		{
			printf("Invalid input.\n");
			printf("What thickness should the border have?\n");
			scanf("%*s");
		}
		//Test for conditions specified for valid border input.
		if(thickness<1)
		{
			printf("Invalid input.\n");
			goto errorBorder1;
		}
		print_triangle(height,thickness);
		runCount = runCount + 1;
		goto start;
	}
	//SQUARE
	if(shape[0]=='s')
	{
		//This point in the code for the square, the user is asked for border thickness.
		errorBorder2:
		printf("What thickness should the border have?\n");
		while(scanf("%d",&thickness)!=1)
		{
			printf("Invalid input.\n");
			printf("What thickness should the border have?\n");
			scanf("%*s");
		}
		//Test for conditions specified for valid border input.
		if(thickness<1)
		{
			printf("Invalid input.\n");
			goto errorBorder2;
		}
		print_square(height,thickness);
		runCount = runCount + 1;
		goto start;
	}
	//RECTANGLE
	if(shape[0]=='r')
	{
		//This point in the code for the rectangle, the user is asked for width.
		errorWidth:
		printf("What width should the rectangle be?\n");
		while(scanf("%d",&width)!=1)
		{
			printf("Invalid input.\n");
			printf("What width should the rectangle be?\n");
			scanf("%*s");
		}
		//Test for conditions specified for valid width input.
		if(width<1)
		{
			printf("Invalid input.\n");
			goto errorWidth;
		}
		//This point in the code for the rectangle, the user is asked for border thickness.
		errorBorder3:
		printf("What thickness should the border have?\n");
		while(scanf("%d",&thickness)!=1)
		{
			printf("Invalid input.\n");
			printf("What thickness should the border have?\n");
			scanf("%*s");
		}
		//Test for conditions specified for valid border input.
		if(thickness<1)
		{
			printf("Invalid input.\n");
			goto errorBorder3;
		}
		print_rectangle(height,width,thickness);
		runCount = runCount + 1;
		goto start;
	}
	//TRIANGULAR PYRAMID
	if(shape[0]=='p')
	{
		//This point in the code for the triangular pyramid, the user is asked for number of levels.
		errorLevels:
		printf("How many levels should the triangular pyramid have?\n");
		while(scanf("%d",&levels)!=1)
		{
			printf("Invalid input.\n");
			printf("How many levels should the triangular pyramid have?\n");
			scanf("%*s");
		}
		//Test for conditions specified for valid levels input.
		if(levels<1)
		{
			printf("Invalid input.\n");
			goto errorLevels;
		}
		print_pyramid(height,levels);
		runCount = runCount + 1;
		goto start;
	}
	return 0;
}