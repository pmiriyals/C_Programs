#include<stdio.h>
#include<math.h>

void DecToBin(int num)
{
	if(num <= 0)
	{
		printf(" %d", num);	
		return;
	}
	int x = 0;
	if(num & 1)
		x = 1;
	else
		x = 0;
	DecToBin(num >> 1);
	printf(" %d", x);
}

int BinToDec(int num)
{
	int count = 0;
	int val = 0;
	while(num > 0)
	{
		if(num % 10)
		{
			val += pow(2, count);
		}
		num /= 10;
		count++;
	}
	return val;
}

int numBits(int num)
{
	int cnt = 0;
	while(num > 0)
	{
		cnt++;
		num = num >> 1;
	}
	return cnt;
}
