#include<stdio.h>
#include<string.h>

//using bitvector
//O(n)
void remdup(char* s)
{
	int checker = 0;
	int val, i = 0, j = 0;

	while(s[i] != '\0')
	{
		val = s[i] - 'a';
		if((checker & (1 << val)) > 0)
		{
			i++;
			continue;
		}		
		s[j++] = s[i++];
		checker |= (1 << val);
	}
	s[j] = '\0';
}

//use two loops O(n2)
//sort string and iterate O(nlogn)
//use count array O(n)
void main()
{
	char s[] = "abacdbbac";
	remdup(s);
	printf("\nafter removing duplicates = %s\n", s);
}
