#include<stdio.h>
#include "Util.h"

int getLeftBits(int x, int p, int n)
{
	return ((x >> p) & (~(~0 << n)));
}

int getRightBits(int x, int p, int n)
{
	return ((x >> (p+1-n)) & ~(~0 << n));
}

void main()
{
	int num;
	scanf("%d", &num);
	DecToBin(num);
	printf("\n");	
	DecToBin(getRightBits(num, 1, 2));
	printf("\n");
}
