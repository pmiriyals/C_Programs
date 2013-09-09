#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//other alternative is to sort the string and remove duplicates which
//will take O(1) space but O(nlog n + n) time

//This approach using count array takes,
//Time = O(n) and space = O(char_max)
void main()
{
	char s[] = "remove duplicates from this input string";
	int* cnt = calloc(256, sizeof(char));
	int i, len = strlen(s);
	int j = 0;
	for(i = 0; i< len && j < len; i++)
	{
		if(!cnt[s[i]])
		{
			*(s + j) = s[i];
			j++;
			cnt[s[i]] = 1;
		}
	}	
	s[j] = '\0';
	printf("\n string after removing duplicates = %s\n", s);
}
