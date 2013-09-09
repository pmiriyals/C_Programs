#include<stdio.h>
#include "Util.h"

int setBits(int x, int p, int n, int y)
{
	return ((y & ~(~0 << n)) << (p+1-n)) | (x & ~((~(~0<<n)) << (p+1-n)));
}

void main()
{
	int num1, num2;
	printf("num1 = ");
	scanf("%d", &num1);
	printf("\nnum2 = ");
	scanf("%d", &num2);
	num1 = BinToDec(num1);
	printf("\n num1 in Bin = ");
	DecToBin(num1);
	num2 = BinToDec(num2);
	printf("\n num2 in Bin = ");
	DecToBin(num2);
	printf("\n num1 = %d", num1);
	printf("\n num2 = %d", num2);

	printf("\n setbits = ");
	DecToBin(setBits(num1, 4, 3, num2));
}
