#include<stdio.h>

int findMin(int arr[], int low, int high)
{
	if(low > high)
		return;

	int mid = low + (high-low)/2;
	if(mid < high && arr[mid] > arr[mid+1])
		return arr[mid+1];

	if(arr[mid] < arr[low])
		return findMin(arr, low, mid-1);
	else
		return findMin(arr, mid+1, high);
}

void main()
{
	int arr[] = {6, 7, 9, 15, 4};
	int high = (sizeof(arr)/sizeof(int))-1;
	printf("\nMin = %d\n", findMin(arr, 0, high));
}
