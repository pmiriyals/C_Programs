#include<stdio.h>

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int MaxSumNoAdj(int* a, int l)
{
	int i = 0;
	int excl_new;
	int incl = a[0];
	int excl = 0;
	for(i = 1; i<=l; i++)
	{
		excl_new = max(incl, excl);
		incl = excl + a[i];
		excl = excl_new;
	}
	return max(incl, excl);
}

//O(n)
void main()
{
	int a[] = {5,  5, 10, 40, 50, 35};
	int len = sizeof(a)/sizeof(int);
	printf("\n Max sum such that no two elements are adjacent = %d\n", MaxSumNoAdj(a, len-1));
}
