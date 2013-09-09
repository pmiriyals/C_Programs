#include<stdio.h>

//O(log n)
int CeilSearchIter(int arr[], int low, int high, int x)
{
	if(x > arr[high])
		return -1;

	if(x <= arr[low])
		return arr[low];

	int mid = (low + high)/2;

	int i = low;
	while(i <= mid)
	{
		if(x == arr[mid])
			return arr[mid];
		else if(x > arr[mid])
		{
			if(((mid+1) <= high) && x <= arr[mid+1])
				return arr[mid+1];
			else 
			{
				i = mid+1;			
				mid = (mid + high)/2;
			}
		}
		else if(x < arr[mid])
		{
			if(((mid-1) >= low) && x > arr[mid-1])
				return arr[mid];
			else
			{
				mid = (low + mid)/2;
				i++;
			}
		}
	}

	return -1;
}

//O(log n)
int CeilSearchRecur(int arr[], int low, int high, int x)
{
	if(x > arr[high])
		return -1;
	int mid = (high+low)/2;

	if(x == arr[mid])
		return arr[mid];
	else if(x > arr[mid])
	{
		if(((mid+1) <= high) && x <= arr[mid+1])
			return arr[mid+1];
		else
			CeilSearchRecur(arr, mid+1, high, x);
	}
	else
	{
		if(((mid-1) >= low) && x > arr[mid-1])
			return arr[mid];
		else
			CeilSearchRecur(arr, low, mid-1, x);
	}
}


//O(n)
int FloorLinearSearch(int arr[], int low, int high, int x)
{
	int i;

	if(arr[low] > x)
		return -1;
	for(i = low; i <= high; i++)
	{
		if(arr[i] <= x)
			return arr[i];
	}
	return -1;
}

//O(n)
int CeilLinearSearch(int arr[], int low, int high, int x)
{
	int i;

	if(arr[high] < x)
		return -1;
	for(i = low; i <= high; i++)
	{
		if(arr[i] >= x)
			return arr[i];
	}
	return -1;
}

void main()
{
	int arr[] = {2, 5, 8, 9, 12};
	int x;
	printf("\nPlease enter key = ");
	scanf("%d", &x);
	int len = sizeof(arr)/sizeof(int);
	printf("\n Ceil = %d\n", CeilSearchIter(arr, 0, len-1, x));	
}
