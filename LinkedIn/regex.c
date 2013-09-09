#include<stdio.h>
#include<stdlib.h>

int ismatch(char* s, char* p)
{
	if(*s == '\0' && *p == '\0')
		return 1;

	if(*p == '*' && *(p+1) != '\0' && *s == '\0')
		return 0;

	if(*p == '?' || *p == *s)
		return ismatch(s+1, p+1);

	if(*p == '*')
		return ismatch(s, p+1) || ismatch(s+1, p);
	return 0;
}

void main()
{
	char s[] = "match";
	char p[] = "m?tc*??";

	printf("\nismatch(%s, %s) = %s\n", s, p, ismatch(s, p) ? "Matching" : "Not a match");
}


