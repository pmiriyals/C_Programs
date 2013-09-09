#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int firstnonrepeatingchar(char* s)
{
	int* cnt = calloc(256, sizeof(char));
	int i, len = strlen(s);
	for(i = 0; i< len;i++)
		cnt[s[i]]++;
	for(i = 0; i< len; i++)
		if(cnt[s[i]] == 1)
			return s[i];
	return -1;
}

void main()
{
	char* s = "print the 1st non repeating charachter";
	printf("\nFirst non-repeating char = %c\n", firstnonrepeatingchar(s));
}
