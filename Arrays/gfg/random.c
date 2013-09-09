#include<stdio.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void print(int* a, int n)
{
	int i;
	printf("\nArray = ");
	for(i = 0; i<n;i++)
		printf(" %d", a[i]);
}

void shuffle(int* deck, int n)
{
	int i, ndx;

	for(i = 0; i< n; i++)
	{
		ndx = rand()%n;
		if(ndx > i)
		{
			swap(deck+ndx, deck+i);
		}
	}
}

int stream(int i)
{
	static int cnt = 0;
	static int res;

	cnt++;
	if(cnt == 1)
	{
		res = i;
	}
	else
	{

		int n = rand()%cnt;
		if(n == cnt-1)
			res = i;
	}
	return res;
}

void main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(a)/sizeof(n);
//	shuffle(a, n);
//	shuffle(a, n);
	print(a, n);
	int i;
	for(i = 0; i<n;i++)
		printf("\nRandomly selected from stream = %d", stream(a[i]));
}

