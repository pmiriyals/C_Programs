#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findMaxOccuringChar(char* str, int len)
{
	int* count = calloc(256, sizeof(int));
	int i, max = 0, maxChar;
	for(i = 0; i<len; i++)
	{
		count[str[i]]++;
		if(count[str[i]] > max)
		{
			max = count[str[i]];
			maxChar = str[i];
		}
	}	
	return maxChar;
}

//Voting algorithm will not work here. The input should be in a sequence or
//max occuring element should be greater than n/2;
void main()
{
	char* str = "find max character";
	int len = strlen(str)-1;
	printf("\n max char = %c\n", findMaxOccuringChar(str, len));
}
