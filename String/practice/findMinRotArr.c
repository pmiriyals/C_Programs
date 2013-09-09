#include<stdio.h>

//O(log n)N
int findMin(int* a, int low, int high)
{
	if(low < high)
	{
		int mid = low + (high-low)/2;
		if(mid < high && a[mid] > a[mid+1])
			return a[mid+1];

		if(a[mid] < a[low])
			return findMin(a, low, mid);
		else
			return findMin(a, mid+1, high);
	}

}

void main()
{
	int arr[] = {15, 20, 25, 5, 8, 10, 14};
	printf("\n Min = %d\n", findMin(arr, 0, (sizeof(arr)/sizeof(int))-1));
}
