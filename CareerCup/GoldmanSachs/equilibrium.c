#include<stdio.h>

//O(n)
void equilibrium(int* a, int l)
{
	int sum = 0, i, leftsum = 0;
	for(i = 0; i< l; i++)
		sum+=a[i];
	for(i = 0; i< l; i++)
	{
		sum -= a[i];

		if(sum == leftsum)
		{
			printf("\n equilibrium found at index = %d and sum = %d\n", a[i], sum);
			return;
		}
		leftsum+=a[i];
	}
	printf("not found")
}

void alternatemethod(int* a, int l)
{
int i = 0, j = (l-1);
	int front = 0, back = 0;
	
	while(i < j)
	{
		if(front > back)
		{
			back += a[j--];
		}
		else if(back > front)
			front += a[i++];
		else
		{
			back += a[j--];
			front += a[i++];
		}
	}
	if(back == front)
		printf("\n equilibrium found at index = %d and value = %d and sum = %d\n", i, a[i], front);
	else
		printf("\n not found\n");
}

void main()
{
	int a[] = {1, 2, 3, 0};
	int l = sizeof(a)/sizeof(int);
	equilibrium(a, l);
//	int* tmp = calloc(l, sizeof(int));
	
}
