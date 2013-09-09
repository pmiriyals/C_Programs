#include<stdio.h>
#include<stdlib.h>

int merge(int* arr, int* tmp, int left, int right, int rightend)
{
	int leftend = right-1;
	int k = left;
	int i;
	int num = rightend-left+1;
	int inv = 0;

	while((left <= leftend) && (right <= rightend))
	{
		if(arr[left] < arr[right])
			tmp[k++] = arr[left++];
		else
		{
			tmp[k++] = arr[right++];
			inv += right - left;
		}
	}

	while(left <= leftend)
		tmp[k++] = arr[left++];

	while(right <= rightend)
		tmp[k++] = arr[right++];

	for(i = left; i< right; i++)
		arr[i] = tmp[i];

	return inv;
}

int mergesort(int* arr, int* tmp, int left, int right)
{
	int inv = 0;

	if(right > left)
	{
		int mid = (left + (right-left)/2);

		inv = mergesort(arr, tmp, left, mid);
		inv += mergesort(arr, tmp, mid+1, right);
		inv += merge(arr, tmp, left, mid, right);
	}

	return inv;
}

void main()
{
	int arr[] = {4, 1, 2, 3, 5};
	int l = sizeof(arr)/sizeof(int);
	int* tmp = (int*) malloc(sizeof(int) * l);
	printf("\ninversion count = %d\n", mergesort(arr, tmp, 0, l-1));
}
