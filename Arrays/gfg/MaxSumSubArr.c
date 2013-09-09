#include<stdio.h>

void main()
{
	int arr[] = {-6, -2, 3};
	int maxFoundSoFar = arr[0];
	int maxEndingHere = arr[0];
	int i, len = sizeof(arr)/sizeof(int);
	for(i = 1; i< len; i++)
	{
		maxEndingHere += arr[i];
		if(maxEndingHere < arr[i])
			maxEndingHere = arr[i];
		if(maxFoundSoFar < maxEndingHere)
			maxFoundSoFar = maxEndingHere;
	}
	printf("\nMax sum = %d\n", maxFoundSoFar);
}
