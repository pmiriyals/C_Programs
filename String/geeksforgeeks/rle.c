#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void rle(char* s)
{
	int i = 1, num = 1, j = 0;
	int len = strlen(s);
	char* str = malloc(sizeof(char)* (len + 1));
	char c = s[0];
	str[j++] = c;
	while(i < len)
	{
		if(c == s[i])
		{
			num++;
		}
		else
		{
			str[j++] = '0' + num; //only works if num < 9. Use itoa instead
			c = s[i];
			str[j++] = c;
			num = 1;
		}
		i++;
	}

 	str[j++] = '0' + num;
	str[j] = '\0';
	
	printf("%s\n", str);
}

void main()
{
	char s[] = "wwwwaaadexxxxxx";
	rle(s);
}
