#include<stdio.h>
#include<stdlib.h>

void randN(int n)
{
	int* arr = malloc(sizeof(int) * (n + 1));
	int i;
	for(i=0; i<= n; i++)
		arr[i] = -1;
	int cnt = 1;
	int num;
	while(cnt <= n)
	{
		num = rand() % n + 1;
		printf("num = %d     cnt = %d\n", num, cnt);
		if(arr[num] < 0)
		{	
			if(arr[cnt] < 0)
				arr[cnt] = -num;
			else
				arr[cnt] = num;
			arr[num] = -arr[num];
			cnt++;
		}

	}
	printf("\n Randomly generated numbers = ");
	for(i = 1; i<= n; i++)
		printf(" %d ", arr[i]);
	printf("\n");
}

void main()
{
	randN(5);
}
