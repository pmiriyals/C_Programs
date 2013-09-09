#include<stdio.h>
#include<stdlib.h>

#define max 500 

void nl()
{
	printf("\n");
}

void printarr(int* a, int l)
{
	int i = 0;
	nl();
	for(i = 0; i< l; i++)
		printf(" %d ", a[i]);
}

int getindex(int* arr, int n, int l)
{
	int val = getindexofNthLargest(arr, n, 0, l);
	int i;
	for(i = 0; i< l; i++)
		if(arr[i] == val)
			return i;
	return -1;
}

int getindexofNthLargest(int* arr, int n, int low, int high)
{
	int* a1 = calloc(max, sizeof(int));
	int* a2 = calloc(max, sizeof(int));

	int pivot = low + (high-low)/2;
	int i, j = 0, k = 0;
	printarr(arr, high);
	for(i = 0; i< high; i++)
		if(arr[i] < arr[pivot])
			a1[j++] = arr[i];
		else if(arr[i] > arr[pivot])
			a2[k++] = arr[i];

		printarr(a1, j);		
		printarr(a2, k);
//		exit(0);
		if(k  > n)
			return getindexofNthLargest(a2, n, 0, k);
		else if(n <= (high-j))
			return getindexofNthLargest(a1,n-( high-j), 0, j);
		else
		{
			return arr[pivot];

		}

}

void main()
{
	int arr[] = {9, 1, 5, 2};
	printf("\n %dth largest = %d\n", 1, getindexofNthLargest(arr, 3, 0, 4));
}
