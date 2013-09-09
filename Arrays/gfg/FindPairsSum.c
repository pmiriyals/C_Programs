#include<stdio.h>
#include<stdlib.h>

int getMax(int* arr, int len)
{
	int i;
	int max = arr[0];
	for(i = 1; i< len; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}

void main()
{
	int arr[] = {3, 5, 2, 10, 6, 1, 7};
	int len = sizeof(arr)/sizeof(int);
	int max = getMax(arr, len);
	int* cnt = calloc(max+1, sizeof(int));
	int i, sum = 8, temp;	
	for(i = 0; i < len; i++)
	{
		temp = sum - arr[i];
		if(temp >= 0 && cnt[temp])
		{
			printf("\n Found pair = (%d, %d)\n", temp, arr[i]);
		}
		cnt[arr[i]] = 1;
	}
}
