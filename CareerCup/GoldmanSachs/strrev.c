#include<stdio.h>

void strrev(char* s, int i)
{
	int end = i-1;
	int start = 0;
	char c;
	while(start < end)
	{

		c = s[start];
		s[start++] = s[end];
		s[end--] = c;
	}	
}

void main()
{
	char s[500];
	int i = 0;
	char c;
	while((c = getchar())!= 'q')
		s[i++] = c;

	s[i] = '\0';

	strrev(s, i);
	printf("\nRev = %s", s);
}
