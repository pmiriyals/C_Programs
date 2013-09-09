#include<stdio.h>
#include<stdlib.h>

void printUnionIntersection(int* a, int* b, int la, int lb)
{
	int i = 0, j = 0, k = 0, n = 0;
	int l = (la > lb)? la : lb;

	int* unionArr = calloc(la+lb, sizeof(int));
	int* intersection = calloc(la, sizeof(int));

	while(i < la && j < lb)
	{
		if(a[i] == b[j])
		{
			unionArr[k++] = a[i];
			intersection[n++] = a[i];
			i++; j++;
		}
		else if(a[i] < b[j])
		{
			unionArr[k++] = a[i++];
		}
		else
			unionArr[k++] = b[j++];
	}
	while(i < la)
		unionArr[k++] = a[i++];
	while(j < lb)
		unionArr[k++] = b[j++];

	printf("\n union = ");
	for(i = 0; i < k; i++)
		printf(" %d ", unionArr[i]);
	printf("\n intersection = ");
	for(i = 0; i < n; i++)
		printf(" %d ", intersection[i]);
}

void main()
{
	int a[] = {3, 7, 9, 12, 15, 20};
	int b[] = {1, 7, 10, 12};
	int la = sizeof(a)/sizeof(int);
	int lb = sizeof(b)/sizeof(int);
	printUnionIntersection(a, b, la, lb);
}
