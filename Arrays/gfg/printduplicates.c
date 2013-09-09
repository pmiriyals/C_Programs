#include<stdio.h>
#include<stdlib.h>

void printDuplicates(int* a, int l)
{
	int i;
	printf("\n Duplicates elements = ");
	for(i = 0; i< l; i++)
	{
		if(a[abs(a[i])] > 0)
			a[abs(a[i])] = -a[abs(a[i])];
		else
			printf(" %d ", abs(a[i]));
	}
	printf("\n");
}

void main()
{
	int a[] = {1, 2, 3, 1, 3};
	int l = sizeof(a)/sizeof(int);
	printDuplicates(a, l);
}
