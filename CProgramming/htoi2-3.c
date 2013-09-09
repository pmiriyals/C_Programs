#include<stdio.h>
#include<string.h>
#include<ctype.h>

int htoi(char* s, int l)
{
	int i = 0, num = 0;
	int hex[] = {10, 11, 12, 13, 14, 15};
	while(i < l && !isalnum(s[i]))
		i++;

	if(i < l-1 && s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
		i+=2;

	while(i < l && isalnum(s[i]))
	{		
		if(s[i] >= '0' && s[i] <= '9')
		{
			num*= 16;		
			num += s[i]-'0';
		}
		else if(s[i] >= 'a' && s[i] <= 'f')
		{
			num*= 16;		
			num += hex[s[i]-'a'];
		}
		else if(s[i] >= 'A' && s[i] <= 'F')
		{
			num*= 16;		
			num+= hex[s[i]-'A'];
		}
		else
			break;
		i++;
	}
	return num;
}

void main()
{
	char s[] = "0x2aF3";
	printf("\n htoi(%s) = %d\n", s, htoi(s, strlen(s)));
}
