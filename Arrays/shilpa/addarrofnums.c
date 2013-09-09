#include<stdio.h>
#include<stdlib.h>

void addArrofNums(int* a, int* b, int* c, int la, int lb, int lc)
{
	int sum, carry = 0;
	while(la >= 0 && lb >= 0 && lc>=0)
	{
		sum = a[la--] + b[lb--] + carry;
		carry = sum/10;
		c[lc--] = sum % 10;
	}
	while(la >= 0 && lc >= 0)
	{
		sum = a[la--] + carry;	
		c[lc--] = sum % 10;
		carry = sum /10;
	}
	while(lb >= 0 && lc >= 0)
	{
		sum = b[lb--] + carry;
		c[lc--] = sum % 10;
		carry = sum/10;
	}
	if(lc >= 0)
		c[lc] = carry;
}

void main()
{
	int a[] = {1, 6, 9, 5};
	int b[] = {8, 9, 8, 9, 9, 9};
	int la = sizeof(a)/sizeof(int);
	int lb = sizeof(b)/sizeof(int);
	int lc = (la > lb) ? (la+1) : (lb+1);
	int* c = calloc(lc, sizeof(int));
	addArrofNums(a, b, c, la-1, lb-1, lc-1);
	int i;
	for(i = 0; i< lc; i++)
		printf(" %d ", c[i]);
	printf("\n");
}
