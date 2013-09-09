#include<stdio.h>

void printLeaders(int* a, int l)
{
	int max = a[l];
	printf("\n Leaders = %d ", max);
	int i;
	for(i = l-1; i>=0; i--)
	{
		if(a[i] > max)
		{
			printf(" %d ", a[i]);
			max = a[i];
		}
	}
}

void main()
{
	int a[] = {16, 17, 4, 3, 5, 2};
	int len = sizeof(a)/sizeof(int);
	printLeaders(a, len-1);
}
