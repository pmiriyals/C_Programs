#include<stdio.h>

int findMaxSubArr(int arr[], int len)
{
	if(len <= 0)
		return -1;

	int maxEndingHere = arr[0];
	int maxSoFar = arr[0];
	int i = 1;
	while(i < len)
	{
		if(maxEndingHere < 0)
		{
			if(maxEndingHere < arr[i])
				maxEndingHere = arr[i];
		}
		else
			maxEndingHere += arr[i];

		if(maxEndingHere > maxSoFar)
			maxSoFar = maxEndingHere;
		i++;
	}

	return maxSoFar;
}

void main()
{
	int arr[] = {-6, -2, -3, -1};
	int len = sizeof(arr)/sizeof(int);

	printf("\nMax subarray sum = %d\n", findMaxSubArr(arr, len));
}
