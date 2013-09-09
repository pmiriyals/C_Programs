#include<stdio.h>
#include<string.h>

int atoi(char* s)
{
	int l = strlen(s);
	if(l <= 0)
		return -1;

	int i = 0, sign;
	while(s[i] == ' ' || s[i] == '\t')
		i++;

	if(s[i] == '-')
		sign = -1;
	else
		sign = 1;
	if(s[i] == '-' || s[i] == '+')
		i++;
	int num = 0;
	while(s[i] != '\0')
	{
		if(isdigit(s[i]))
			num = (num*10) + (s[i]-'0');
		i++;
	}
	return (num*sign);
}

void main()
{
	char* num = "    	-123 9";
	printf("\n num = %d\n", atoi(num));
}
