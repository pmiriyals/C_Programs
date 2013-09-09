#include<stdio.h>
#include<string.h>

void dividestring(char* s, int n)
{
	int len = strlen(s);
	if(len % n != 0)
	{
		printf("\n string not valid.\n");	
		return;
	}
	int part = len/n;
	int i;
	for(i = 0; i< len; i++)
	{
		if(i % part == 0)
			printf("\n");
		printf("%c", s[i]);
	}
}

void main()
{
	char* s = "dividethisstring";
	dividestring(s, 4);
}
