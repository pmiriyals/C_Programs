#include<stdio.h>
#include<stdlib.h>

#define MAX 256

//O(n)
int areAnagrams(char s1[], char s2[])
{
	int* count = calloc(MAX, sizeof(int));
	int i;	
	for(i = 0; s1[i] && s2[i]; i++)
	{
		if(s1[i] != ' ' && s1[i] != '\t')
			count[s1[i]]++;
		if(s2[i] != ' ' && s2[i] != '\t')
		count[s2[i]]--;
	}

	if(s1[i] || s2[i])
		return 0;

	for(i = 0; i< MAX; i++)
		if(count[i] != 0)
			return 0;
	return 1;
}	

void main()
{
	char s1[MAX], s2[MAX];

	printf("\nEnter string1 = ");
	scanf("%s", s1);
	printf("\nEnter string2 = ");
	scanf("%s", s2);

	printf("\nAre anagrams: %s\n", areAnagrams(s1, s2) > 0 ? "Yes" : "No");
}
