#include<stdio.h>
#include<stdlib.h>

void main()
{
	char s1[] = "geeks for geeks";

	int* s = (int*) calloc(256, sizeof(char));

	int i =0, j = 0;
	while(s1[i] != '\0')
	{
		if(s[s1[i]] == 0)
		{
			s1[j++] = s1[i];
			s[s1[i]] = 1;
		}
		i++;		
	}
	s1[j] = '\0';
	printf("\nString is  = %s\n", s1);
}
