#include<stdio.h>
#include<math.h>

int coinflip()
{
	return rand()%2;
}

int bintodec(int num)
{
	int res = 0, cnt = 0;

	while(num > 0)
	{
		if(num & 1)
		{
			res+= pow(2, cnt);
		}
		cnt++;
		num = num/10;
	}
	return res;
}

int RollDice()
{
	int num = 0, i = 3;
	while(i > 0)
	{
		num = num*10 + coinflip();
		i--;
	}
	num = bintodec(num);

	if(num == 7)
		return RollDice();
	else
		return num;
}

void main()
{
	printf("\ndice  = %d\n", RollDice());
}
