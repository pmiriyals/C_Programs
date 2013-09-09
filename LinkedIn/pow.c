#include<stdio.h>

double power(double x, int n)
{
	if(n == 0)
		return 1;

	double temp = power(x, n/2);

	if(n%2 == 0)
		return temp*temp;
	else
	{
		if(n > 0)
			return x * temp * temp;
		else
			return (temp*temp)/x;
	}	
}

void main()
{
	printf("\n pow = %lf\n", power(2, -2));
}
