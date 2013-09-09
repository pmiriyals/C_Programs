#include<stdio.h>

void printUnsortedSubArr(int* a, int l)
{
	int s, e, i;
	for(i = 0; i< l-1; i++)
		if(a[i] > a[i+1])
		{
			s = i;
			break;
		}

	if(i == l-1)
	{
		printf("\n array is sorted\n");
		return;
	}

	for(e = l-1; e > 0; e++)
		if(a[e] < a[e-1])
			break;

	int min = a[s], max = a[s];
	for(i = s+1; i<= e; i++)
	{
		if(a[i] < min)
			min = a[i];
		if(a[i] > max)
			max = a[i];
	}
	for(i = 0; i< s; i++)
		if(a[i] > min)
			break;
	s = i;
	for(i = l-1; i>e; i++)
		if(a[i] < max)
			break;
	e = i;
	printf("\n unsorted sub array = ");
	for(i = s; i<=e; i++)
		printf(" %d ", a[i]);
}

void main()
{
	int a[] = {5, 10, 15, 20, 18, 25, 40, 35, 30, 50, 60, 90};
	int l = sizeof(a)/sizeof(int);
	printUnsortedSubArr(a, l);
}
