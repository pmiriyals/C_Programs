#include<stdio.h>
#include<math.h>

//Time = exponential
int fibo(int n)
{
	if(n <= 1)
		return n;

	return fibo(n-1) + fibo(n-2);
}

//O(1)
int binets(int n)
{
	float phi = (1+sqrt(5))/2;
	float nphi = (1-sqrt(5))/2;

	int num = (int) ((pow(phi, n) - pow(nphi, n))/sqrt(5));
	return num;
}

//O(n)
int fibIter(int n)
{
	int a = 0, b = 1, c;

	int i;
	for(i = 2; i<=n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

#define NIL -1
#define MAX 100
 
int lookup[MAX];

void _initialize()
{
  int i;
  for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}

//Top down approach
//Space = O(n)
//Time = O(n)
int fib(int n)
{
   if(lookup[n] == NIL)
   {
    if ( n <= 1 )
      lookup[n] = n;
    else
      lookup[n] = fib(n-1) + fib(n-2);
   }
 
   return lookup[n];
}

//Bottom Up approach
//Space = O(n)
//Time = O(n)
int fibTabulated(int n)
{
  int f[n+1];
  int i;
  f[0] = 0;   f[1] = 1; 
  for (i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];
 
  return f[n];
}

void main()
{
	printf("\nfibo inefficient recur = %d\n", fibo(10));
	printf("\nfibo using binets formula = %d\n", binets(10));
	printf("\nfibo using efficient iter = %d\n", fibIter(10));
	_initialize();
	printf("\nMemoized version of fibo (top down recursion) = %d\n", fib(10));
	printf("\nBottow up approach (Tabulated) fibo = %d\n", fibTabulated(10));
}
