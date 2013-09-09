#include<stdio.h>

int gcdRecur(int x, int y)
{
	if(x%y == 0)
		return y;

	gcd(y, x%y);
}

int gcdIter(int x, int y)
{
	int r = x%y;
	while(r != 0)
	{
		x = y;
		y = r;
		r = x%y;
	}
	return y;
}

void main()
{
	printf("\n gcd recursive = %d\n", gcdRecur(3, 10));
	printf("\n gcd Iter = %d\n", gcdIter(6, 10));
}
