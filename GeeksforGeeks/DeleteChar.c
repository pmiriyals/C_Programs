#include<stdio.h>

void DeleteChar(char s1[], char s2[], int s[])
{
	int i = 0, j = 0;

	while(s2[i] != '\0')
	{
		s[s2[i++]] = 1;
	}

	i = 0;
	while(s1[i] != '\0')
	{
		if(s[s1[i]] != 1)
		{
			s1[j++] = s1[i];
		}
		i++;
	}
	s1[j] = '\0';
	printf("New string is = %s\n", s1);
}

void main()
{
	char s1[100], s2[100];
	int s[256];
	printf("\nPlease enter string 1 = ");
	scanf("%s", s1);
	printf("\nPlease enter string 2 = ");
	scanf("%s", s2);
	int i;
	for(i = 0; i < 256; i++)
	{
		s[i] = 0;
	}
	DeleteChar(s1, s2, s);
}
