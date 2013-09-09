#include<stdio.h>
#include<stdlib.h>

void convtobin(int n)
{
	char* s = malloc(sizeof(char)*64);
	int num = n;
//	s+=32;
	*s = '\0';
	while(n > 0)
	{
		if(n&1)
			*(--s) = '1';
		else
			*(--s) = '0';
		n>>=1;
	}
	printf("\n Dec(%d) to binary = %s", num, s);
}

int countsetbits(int n)
{
	int cnt;
	for(cnt = 0; n; cnt++)
		n&=(n-1);
	return cnt;
}

void main()
{
	int num;
	scanf("%d", &num);
	convtobin(num);
	printf("\n");
	printf("\n number of set bits = %d", countsetbits(num));
	printf("\n");
}
