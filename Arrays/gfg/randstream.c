#include<stdio.h>
#include<stdlib.h>

int getRandom(int i)
{
	static int res;
	static int cnt = 0;
	cnt++;
	if(cnt == 1)
		res = i;
	else
	{
		if((rand() % cnt) == (cnt-1))
			res = i;
	}
	return res;
}

void main()
{
	int i;
	for(i = 0; i<20; i++)
	{
		printf("\n Random number generated from 1st %d numbers = %d\n", i+1, getRandom(i));
	}
}
