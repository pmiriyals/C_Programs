#include<stdio.h>

void reverserecur(char* s)
{
	if(*s == '\0')
		return;
	reverserecur(s+1);
	printf("%c", *s);
}

void main()
{
	char s[] = "print reverse of this string";
	reverserecur(s);
}
