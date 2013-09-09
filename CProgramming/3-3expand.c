#include<stdio.h>
#include<string.h>

void expand(char s1[], char s2[])
{
	int l = strlen(s1) - 1;
	int i, j = 0, c;
	
	for(i = 0; i <= l; i++)
	{
		if(s1[i] != '-')
			s2[j++] = s1[i];
		else if(i > 0 && i < l)
		{
			if(s1[i-1] >= '0' && s1[i+1] <= '9')
			{
				c = s1[i-1] + 1;				
				while(c < s1[i+1])
				{
					s2[j++] = c++;
				}
			}
			else if('a'<= s1[i-1] && 'z' >= s1[i+1])
			{								
				c = s1[i-1] + 1;
				while(c < s1[i+1])
					s2[j++] = c++;
			}
			else if('A' <= s1[i-1] && 'Z' >= s1[i+1])
			{
				c = s1[i-1] + 1;
				while(c < s1[i+1])
					s2[j++] = c++;
			}
			else
				s2[j++] = s1[i];

		}
		else
			s2[j++] = s1[i];
	}
}

void main()
{
	char s1[] = " a-z ";
	char s2[1024];

	expand(s1, s2);
	printf("\n Expanded string = %s\n\n", s2);
}
