#include<stdio.h>

void printArr(int* a, int la)
{
	int i;
	for(i = 0; i<= la; i++)
		printf(" %d ", a[i]);
}

int moveToEnd(int* a, int la)
{
	int i, j = la;
	for(i = la; i>= 0; i--)
	{
		if(a[i] != -1)
			a[j--] = a[i];
	}	
	return j+1;
}

void mergeSortedArrs(int* a, int* b, int la, int lb)
{
	int startA = moveToEnd(a, la);
	printf("\n Array a = ");
	printArr(a, la);
	int i = 0, j = 0;
	while(i <= la && j <= lb && startA <= la)
	{
		if(b[j] < a[startA] && startA <= la)
		{
			a[i++] = b[j++];
		}
		else
		{
			a[i++] = a[startA++];
		}
	}
	if(startA > la)	//case where array is completely copied and elements are still present in b
	{
		while(i<= la && j<= lb)
			a[i++] = b[j++];
	}
}
//At most 3 passes, with min 2 passes
//Time = O(n)
//Space = O(1)
void main()
{
	int a[] = {5, -1, 10, -1, -1, 15, 20};
	int b[] = {3, 8, 9};
	int la = sizeof(a)/sizeof(int);
	int lb = sizeof(b)/sizeof(int);
	mergeSortedArrs(a, b, la-1, lb-1);
	printf("\n Array after merging = ");
	printArr(a, la-1);
	printf("\n");
}
