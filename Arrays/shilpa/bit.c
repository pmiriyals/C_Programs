#include<stdio.h>
#include<stdlib.h>

void dectobin(int num)
{
	char* s = malloc(sizeof(char)* 10);
	s[9] = '\0';
	int i = 8;
	int n = num;
	while(n>0 && i>=0)
	{
		if(n&1)
			s[i--] = '1';
		else
			s[i--] = '0';
		n >>= 1;
	}
	s[i] = '0';
	s += i;
	printf("\n binary(%d) = %s\n", num, s);
}

void main()
{
	int num;
	printf("\n enter a number = ");
	scanf("%d", &num);
	dectobin(num);
}
