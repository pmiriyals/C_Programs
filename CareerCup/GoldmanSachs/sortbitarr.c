#include<stdio.h>

void swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;

//	int temp = *a;
//	*a = *b;
//	*b = temp;
}

void sort(int* a, int l)
{
	int i = 0, j = l-1;

	while(i < j)
	{
		while(a[i] == 1 && i < j)
			i++;
		while(a[j] == 0 && j > i)
			j--;

		swap(a+i, a+j);
	}
}

void main()
{
	int a[] = {0, 1, 0, 0, 0, 1, 1, 0, 0, 1};
	int l = sizeof(a)/sizeof(int);
	sort(a, l);
	printf("\n sorted array = ");
	int i = 0;
	while(i < l)
		printf(" %d ", a[i++]);
}
