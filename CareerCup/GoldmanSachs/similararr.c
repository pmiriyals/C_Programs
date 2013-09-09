#include<stdio.h>



void main()
{
	int a[]  = {2, 3, 5, 8};
	int b[] = {8, 2, 5, 3};
	int la = sizeof(a)/sizeof(int);
	int lb = sizeof(b)/sizeof(int);
	int xor = 0;	
	if(la == lb)
	{
		for(lb = 0; lb < la; lb++)
		{
			xor  = xor^a[lb]^b[lb];
		}
		if(xor==0)
		{
			printf("\narrays are similar");
			return ;
		}
	}
	printf("\n not similar");
	
}
