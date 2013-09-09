#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SortArr(int* a, int la)
{
	int mid = 0, low = 0, high = la-1;
	while(mid <= high)
	{
		switch(a[mid])
		{
			case 0:
				swap(&a[low++], &a[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(&a[mid], &a[high--]);
				break;			
		}
	}
	int i;
	printf("\n sorted array = ");
	for(i = 0; i < la; i++)
		printf(" %d ", a[i]);
	printf("\n");
}

void main()
{
	int a[] = {1, 2, 2, 0, 0, 1, 0, 2, 0, 0, 1, 1, 2, 2, 0};
	int la = sizeof(a)/sizeof(int);
	SortArr(a, la);
}
