#include<stdio.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char* s, int i, int n)
{
	if(i == n)
		printf("\n %s", s);
	else
	{
		int j;	
		for(j = i; j<=n; j++)
		{
			swap(s+i, s+j);
			permute(s, i+1, n);
			swap(s+i, s+j);
		}
	}
}

void main()
{
	char s[] = "abc";
	permute(s, 0, 2);
}
