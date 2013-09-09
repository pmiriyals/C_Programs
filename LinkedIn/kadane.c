#include<stdio.h>

void main()
{
	int a[] = {1, 3, -1, 5, -5, -6, 3, -1};
	int maxsofar = 0;
	int maxtillhere = 0;
	int isneg = 1;
	int minneg = a[0];
	int i = 0;
	int l = sizeof(a)/sizeof(int);
	
	while(i < l)
	{
		maxtillhere += a[i];
		if(maxtillhere < 0)
		{
			maxtillhere = 0;	
		}
		else
			isneg = 0;
		if(isneg && a[i] > minneg)
			minneg = a[i];
		else if(maxtillhere > maxsofar)
			maxsofar = maxtillhere;		
	}

	if(isneg)
		printf("\n max sum = %d\n", minneg);
	else
		printf("\nmax sum = %d\n", maxsofar);
}
