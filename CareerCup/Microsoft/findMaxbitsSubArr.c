#include<stdio.h>

void findMaxSubArr(int arr[], int len)
{
	if(len <= 0)
		return;

	int sndx = 0, max = 0, i = 0, sum = 0;
	
	while(i < len)
	{		
		if(arr[i])
			sum++;
		else
			sum--;
		while(abs(sum) > (len-i-1))
		{
			if(sum < 0)
				sum++;
			else
				sum--;
			sndx++;	
		}

		if(sum == 0)
		{
			printf("\n start index = %d and end index = %d, len = %d\n", sndx, i, i-sndx);
			if(max < (i-sndx+1))
				max = i-sndx + 1;
		}
		i++;		
	}
	printf("Max len = %d\n", max);
}

void main()
{
	int arr[] = {1,1,1,1,0,0,1,0,1};
	findMaxSubArr(arr, sizeof(arr)/sizeof(int));
}
