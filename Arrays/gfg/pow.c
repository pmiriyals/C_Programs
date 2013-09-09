#include<stdio.h>

int power(int x, int y)
{
	if(y <= 0)
		return 1;

	int temp = power(x, y/2);

	if(y%2 == 0)
		return temp*temp;
	else
	{
		if(y > 0)
			return x*temp*temp;
		else
			return (temp*temp)/x;
	}
}

void main()
{
	int x = 3, y = 3;
	printf("\npow(%d, %d) = %d\n", x, y, power(x, y));
}
