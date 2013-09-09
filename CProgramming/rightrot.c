#include<stdio.h>
#include "Util.h"

int rightrot(int x, int n)
{
	int y = x >> n;
	int l = numBits(y);
	return ((x & (~(~0 << n))) << l) | y;
}

void main()
{
	int num;
	scanf("%d",  &num);
	num = BinToDec(num);
	DecToBin(num);
	num = rightrot(num, 3);
	puts("\nRotated bits = ");
	DecToBin(num);
}
