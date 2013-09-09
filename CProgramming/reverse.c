#include<stdio.h>
#include<string.h>

void reverse(char s[])
{
	int i, j, c;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}	
}

void rev(char* s)
{
	if(*s)
	{
		rev(s+1);
		putchar(*s);
	}
}

void main()
{
	char s[100];
	scanf("%s", s);
	
	reverse(s);
	printf("\n rev = %s\n", s);
	printf("\nrecursive rev = ");
	rev(s);
	putchar('\n');
}
