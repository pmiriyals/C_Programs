#include<stdio.h>

int fromDec(int num, int b)
{
	int result = 0, n = num;
	int multiplier = 1;

	while(n > 0)
	{
		result+= n%b *multiplier;
		multiplier *= 10;
		n /= b;
	}

	printf("\nfromDec(%d, %d) = %d\n", num, b, result);
	return result;
}

int toDec(int num, int b)
{
	int result = 0, n = num;
	int multiplier = 1;

	while(n > 0)
	{
		result += n%10 * multiplier;
		multiplier *= b;
		n /=10;
	}
	printf("\ntoDec(%d, %d) = %d\n", num, b, result);
	return result;
}

int setbitsitoj(int N, int M, int i, int j)
{
	return (~(~(~0 << (j-i)) << i) & N) || ((~(~0 << (j-i)) & M) << i);
}

void main()
{
	int N = toDec(101101001, 2);
	int M = toDec(10101, 2);

	printf("\n after setting bits = %d\n", fromDec(setbitsitoj(N, M, 2, 6), 2));
}
