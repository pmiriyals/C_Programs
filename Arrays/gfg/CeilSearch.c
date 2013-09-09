#include<stdio.h>

int CeilSearch(int* a, int low, int high, int x)
{
	if(low > high)
		return -1;

	int mid = low + (high-low)/2;
	if(a[low] > x)
		return a[low];
	if(a[high] < x)
		return -1;

	if(a[mid] == x)
		return a[mid];

	if(a[mid] > x)
	{
		if(mid-1 >= low && a[mid-1] < x)
			return a[mid];
		else
			return CeilSearch(a, low, mid-1, x);
	}
	else
	{
		if(mid+1 <= high && a[mid+1] > x)
			return a[mid+1];
		else
			return CeilSearch(a, mid+1, high, x);
	}
	
}

void main()
{
	int a[] = {2, 5, 8, 12, 16, 20};
	int x = 18;
	int l = sizeof(a)/sizeof(int);
	printf("\nCeil = %d\n", CeilSearch(a, 0, l-1, x));
}
