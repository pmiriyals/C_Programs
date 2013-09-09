#include<stdio.h>

//Avg and worst case O(n log n)
//Stable in most implementations and not an inplace sorting alg
//Space O(n)

void Merge(int arr[], int tmp[], int left, int right, int rightend)
{
	int k = left;
	int num = rightend-left+1;
	int leftend = right-1;
	int i;

	while((left <= leftend) && (right <= rightend))
	{
		if(arr[left] < arr[right])
			tmp[k++] = arr[left++];
		else
			tmp[k++] = arr[right++];
	}

	while(left <= leftend)
		tmp[k++] = arr[left++];
	while(right <= rightend)
		tmp[k++] = arr[right++];

	for(i = 0; i <num; i++, rightend--)
		arr[rightend] = tmp[rightend];
	
}

void Divide(int arr[], int tmp[], int left, int right)
{
	int center = (left+right)/2;
	if(left < right)
	{
		Divide(arr, tmp, left, center);
		Divide(arr, tmp, center+1, right);
		Merge(arr, tmp, left, center+1, right);
	}
}


void MergeSort(int arr[], int len)
{
	int tmp[len];
	Divide(arr, tmp, 0, len-1);
}


void main()
{
	int arr[] = {10, 9, 3, 8, 6, 1};
	int len = sizeof(arr)/sizeof(int);
	MergeSort(arr, len);
	int i = 0;
	printf("\n");
	while(i < len)
		printf(" %d ", arr[i++]);
	printf("\n");
}
