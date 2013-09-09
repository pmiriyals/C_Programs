#include<stdio.h>

int findpivot(int* arr, int low, int high)
{
	if(low > high)
		return -1;
	if(high == low)
		return low;

	int mid = low + (high-low)/2;

	if(mid < high && arr[mid] > arr[mid+1])
		return mid+1;
	if(arr[mid] <= arr[low])
		return findpivot(arr, low, mid);
	else
		return findpivot(arr, mid, high);
}

int binsearch(int* arr, int low, int high, int x)
{
	if(low < high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] == x)
			return mid;
		if(arr[mid] < x)
			return binsearch(arr, mid+1, high, x);
		else
			return binsearch(arr, low, mid-1, x);
	}
	else
		return -1;
}

void SearchInSortedPivotedArr(int* arr, int low, int high, int x)
{
	int pivot = findpivot(arr, low, high);
	printf("\n pivot = %d\n", pivot);
	if(pivot < 0)
	{
		printf("\n not sorted. Found x at %d\n", binsearch(arr, low, high, x));
		return;
	}
	if(arr[pivot] == x)
	{
		printf("\n Found x at %d\n", pivot);
		return;
	}
	if(arr[low] > x)
		printf("\n found x at %d\n", binsearch(arr, pivot, high, x));
	else
		printf("\nFound x at %d\n", binsearch(arr, low, pivot-1, x));
}

void main()
{
	int arr[] = {9, 10, 2, 6, 7, 8};
	int len = sizeof(arr)/sizeof(int);

	SearchInSortedPivotedArr(arr, 0, len-1, 10);
}
