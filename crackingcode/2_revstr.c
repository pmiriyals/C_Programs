#include<stdio.h>
#include<string.h>

//in-place reversal of a string
void rev(char* s)
{
	char* e = s;
	while(*e)
		e++;
	e--;
	char c;
	while(s < e)
	{
		c = *e;
		*e-- = *s;
		*s++ = c;
	}
}

//in-place string reversal
void revstr(char* s)
{
	int l = strlen(s);
	int i, x, j = 0;
	for(i = l-1;i>j; i--, j++)
	{
		x = s[i];
		s[i] = s[j];
		s[j] = x;
	}
}

void main()
{
	char s[] = "reverse this";
//	rev(s);
	revstr(s);
	printf("\nreversed string = %s\n", s);
}
