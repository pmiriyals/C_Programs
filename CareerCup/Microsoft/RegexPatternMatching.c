#include<stdio.h>

int match(char* s1, char* s2)
{
	if(*s1 == '\0' && *s2 == '\0')	//if both strings reach end return truee
		return 1;
	if(*s1 == '*' && *(s1+1) != '\0' && *s2 == '\0')	//assuming that s1 does not have two *'s consecutively
		return 0;

	if(*s1 == '?' || *s1 == *s2)
		return match(s1+1, s2+1);
	
	if(*s1 == '*')
		return (match(s1+1, s2) || match(s1, s2+1));

	return 0;	
}

void main()
{
	char s1[100], s2[100];
	puts("\nEnter s1: ");
	scanf("%s", s1);
	puts("\nEnter s2: ");
	scanf("%s", s2);
	if(match(s1, s2))
		printf("Yes\n");
	else
		printf("No\n");
}
