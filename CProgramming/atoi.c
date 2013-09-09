#include<stdio.h>
#include<ctype.h>

int atoi(char s[])
{
	int i, n = 0;
	for(i = 0; isspace(s[i]); i++)
		;
	int sign = s[i] == '-' ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(n = 0; isdigit(s[i]); i++)
		n = (10*n) + (s[i] - '0');
	n *= sign;
	return n;
}

void main()
{
	char s[256];
	int c;
	int i = 0;
	while((c = getchar()) != 'q')
		s[i++] = c;
	s[i] = '\0';
	printf("\n atoi(\"%s\") = %d\n", s, atoi(s));
}
