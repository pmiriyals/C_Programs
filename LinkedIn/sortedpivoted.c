#include<stdio.h>

int findpivot(int a[], int low, int high)
{
	if(high < low)
		return -1;

	if(high == low)
		return a[low];

	int mid = low + (high-low)/2;

	if(mid < high && a[mid] > a[mid+1])
		return mid+1;

	if(mid > low && a[mid-1] > a[mid])
		return mid;

	if(a[low] > a[mid])
		return findpivot(a, low, mid-1);
	else
		return findpivot(a, mid+1, high);
}

int binsearch(int a[], int low, int high, int x)
{
	if(high < low)
		return -1;

	int mid = low + (high-low)/2;

	if(a[mid] == x)
		return mid;

	if(a[mid] > x)
		return binsearch(a, low, mid-1, x);
	else
		return binsearch(a, mid+1, high, x);	
}

int findx(int a[], int l, int x)
{
	int pivot = findpivot(a, 0, l-1);

	if(pivot == -1)
		return binsearch(a, 0, l-1, x);

	if(a[0] <= x)
		return binsearch(a, 0, pivot, x);
	else
		return binsearch(a, pivot, l-1, x);
}

void main()
{
	int a[] = {9, 12, 14, 16, 1, 2, 5, 7, 8};
	int l = sizeof(a)/sizeof(int);
	printf("\nindex of element x = %d\n", findx(a, l, 10));
}
