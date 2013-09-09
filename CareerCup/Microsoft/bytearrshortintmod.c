#include<stdio.h>
#include<stdlib.h>

void main()
{
//	char* num = malloc(4);
	char num[4];
	*num = 10;

	short int x = 7;


	printf("\nnum = %d\n", *num % x);	

}
