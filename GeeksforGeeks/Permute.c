#include<stdio.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a  = *b;
	*b = temp;
}

void Permute(char* s, int i, int n)
{
	if(i == n)
	{
		printf("%s\n", s);
		return;
	}

	int j;
	for(j = i; j<=n;j++)
	{
		swap(s+i, s+j);
		Permute(s, i+1, n);
		swap(s+i, s+j);
	}	
}

void main()
{
	char arr[] = "ABC";
	Permute(arr, 0, 2);
}
