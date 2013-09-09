#include<stdio.h>

int FindMaxInArr(int* a, int low, int high)
{
	int max = low;
	int i;
	
	for(i = low+1; i<high;i++)
		if(a[i] > a[max])
			max = i;
	return max;
}


void findMaxInConsecutiveSubArrbyK(int* a, int k, int len)
{
	if(k > len)
		return;
	int i = 1;
	int max = a[0];
	int move = 0;
	
	while(i < len && k <= (len-i+1))
	{
		if(a[i]> max)
		{
			max = a[i];
			printf(" %d ", max);
		}
		if(move == k)
		{
			move = 0;
			max = a[i];
		}
		move++;
		i++;
	}
}

void main()
{
	int arr[] = {3, 5, 6, 1, 9, 5, 8};
	printf("\n%d\n", sizeof(short int));
	//findMaxInConsecutiveSubArrbyK(arr, 2, sizeof(arr)/sizeof(int));
}
