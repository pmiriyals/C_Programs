#include<stdio.h>

int maxDiff(int* a, int r)
{
	if(r < 1)
		return -1;

	int i, diff = a[1] - a[0], min = a[0];
	for(i = 1; i <= r; i++)
	{
		if(diff < (a[i]-min))
			diff = a[i]-min;
		if(a[i] < min)
			min = a[i];
	}
	return diff;
}

void main()
{
	int a[] = {6, 9, 12, 0, 11};
	int l = sizeof(a)/sizeof(int);

	printf("\n Max diff = %d\n", maxDiff(a, l-1));
}
