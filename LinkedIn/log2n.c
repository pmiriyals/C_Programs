#include<stdio.h>

int log2n(int n)
{
	return n > 1 ? 1 + log2n(n/2) : 0;
}

void main()
{
	printf("\n log n base 2 = %d", log2n(10));
}
