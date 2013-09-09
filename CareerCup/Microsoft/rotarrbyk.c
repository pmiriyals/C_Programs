#include<stdio.h>

void swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//Time: O(n) & Space: O(1)
void rotarr(int* a, int k, int len)
{
	int i, j, n;
	for(i = 0, j = len-1; i< j; i++, j--)
	{
		swap(a, i, j);
	}
	for(i = 0, j=k-1; i<j; i++, j--)
	{
		swap(a, i, j);
	}
	for(i=k, j=len-1; i<j; i++, j--)
		swap(a, i, j);
}

void main()
{
	int a[] = {5, 1, 7, 3, 9};
	int l = sizeof(a)/sizeof(int);
	rotarr(a, 3, l);
	int i;
	for(i = 0; i<l;i++)
		printf(" %d ", a[i]);
}
