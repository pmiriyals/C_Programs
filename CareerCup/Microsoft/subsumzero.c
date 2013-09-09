#include<stdio.h>
#include<stdlib.h>

//naive O(n!)
//solvable in O(n) using a tmp array and finding same numbers in the array
void FindSubArrSum(int sum, int* arr, int l)
{
	if(l <= 0)
		return;

	int subSum = 0;
	int start = 0;
	int end = 0;
	int* temp = calloc(l, sizeof(int));

	int i, j;
	for(i = 0; i< l; i++)
	{
		start = i;		
		for(j = i; j< l; j++)
		{
			subSum += arr[j];
			if(subSum == sum)
			{
				printf("\n Sum found between %d and %d indexes\n", start, j);
			}
		}
		subSum = 0;
		
	}
}

void main()
{
	int a[] = {1, 0, 2, -1, 0, -1, 10};
	FindSubArrSum(3, a, 7);
}
