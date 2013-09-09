#include<stdio.h>
#include<math.h>



//O(1) to find Nth fibonacii number using Binet's formula
int NthFibo(int n)
{
	double sqrt5 = sqrt(5);
	double phi = (1 + sqrt5)/2;
	double _phi = (1-sqrt5)/2;
	double num = (pow(phi, n) - pow(_phi, n))/sqrt5;
//	printf("\nfloor(%f) = %f", num, floor(num));
	return (num - floor(num) > 0.5) ? ceil(num) : floor(num);
}

//Time: O(n), dynamic programming, saving the results in a bottom up approach
//Space: O(n)
int fib(int n)
{
  int f[n+1], i;

  f[0] = 0;
  f[1] = 1;
 
  for (i = 2; i <= n; i++)
  {
	f[i] = f[i-1] + f[i-2];
	printf("\n fibo(%d) = %d\n", i, f[i]);
  }
 
  return f[n];
}

void main()
{
	int i = 100;
	fib(47);
	while(i < 10)
	{
		printf("\n fibo(%d) = %d\n", i, NthFibo(i));
		i++;
	}
}
