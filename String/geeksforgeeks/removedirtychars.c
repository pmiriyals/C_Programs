#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void removedirtychars(char* s1, char* s2)
{
	int i, j = 0;
	int* cnt = calloc(256, sizeof(char));
	for(i = 0; s2[i] != '\0'; i++)
		cnt[s2[i]] = 1;
	
	for(i = 0; s1[i] != '\0'; i++)
	{
		if(!cnt[s1[i]])
		{
			s1[j] = s1[i];
			j++;
		}		
	}
	s1[j] = '\0';
}

void main()
{
	char s1[] = "geeksforgeeks";
	char s2[] = "mask";
	removedirtychars(s1, s2);
	printf("\n after removing dirty chars = %s\n", s1);
}
