#include<stdio.h>

void rev(char* s)
{
	if(*s == '\0')
		return;

	rev(s+1);
	printf("%c", *s);
}

void main()
{
	char s[] = "reverse this";
//	scanf("%s", s);
	rev(s);
//	printf("\nreverse = %s\n", s);
}
