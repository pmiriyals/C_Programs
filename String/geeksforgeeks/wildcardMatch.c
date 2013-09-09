#include<stdio.h>

int isMatch(char* s, char* p)
{
	if(*s == '\0' && *p == '\0')
		return 1;

	if(*s == '\0' && *p == '*' && *p != '\0')
		return 0;
	
	if(*s == *p)
		return isMatch(s+1, p+1);

	if(*p == '\\' && *(p+1) == 'd' && *(p+2) == '*' && (*s >= '0' && *s <= '9'))
		return isMatch(s + 1, p);
	else if(*p == '\\' && *(p+1) == 'd' && *(p+2) == '*')
		return isMatch(s, p + 3);

	if(*p == '\\' && *(p+1) == 'd' && *(p+2) == '+' && (*s >= '0' && *s <= '9'))
		return isMatch(s + 1, p);
	else if(*p == '\\' && *(p+1) == 'd' && *(p+2) == '+')
	{
//		printf("%c\n", *(s-1));
		return (*(s-1) < '0' || *(s-1) > '9') ? 0 : isMatch(s, p + 3);
	}

	return 0;
}

void main()
{
	char* s = "abcdef";
	char* p = "abc\\d+def";

	printf("Match = %s\n", isMatch(s, p) ? "true" : "false");
}
