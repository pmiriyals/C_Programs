#include<stdio.h>
#include<math.h>
#include<string.h>

void bintodec(char* num, int l)
{
	int i = 0, ndx = l-1;
	int res = 0;
	
	while(ndx >= 0)
	{
		if((num[ndx]-'0') & 1)
			res += pow(2, i);
		ndx--;
		i++;
	}
	printf("\ndecimal(%s) = %d\n", num, res);
}

void dectobin(int n)
{
	char s[32];
	int i = 0, num = n;

	while(num > 0)
	{
		if(num&1)
			s[i++] = '1';
		else
			s[i++] = '0';
		num >>=1;
	}
	s[i] = '0';
	printf("\nbinary(%d) = ", n);
	while(i>=0)
		printf(" %c", s[i--]);
}

int countsetbits(int v)
{
	int cnt = 0;
	while(v>0)
	{
		v&=(v-1);
		cnt++;
		dectobin(v);
	}
	printf("\nnumber of set bits = %d\n", cnt);
	return cnt;
}

void setnthbit(int num, int n)
{
	printf("\n\n 1 << n = ");
	dectobin((1) << n);
	printf("\nafter setting nth bit = %d", num | (1 << n));
	dectobin(num | (1 << n));
}

void flipnthbit(int num, int n)
{
	printf("\n\nafter flipping nth bit = %d\n", num ^ (1 << n));
	dectobin(num ^ (1 << n));
}

void clearnthbit(int num, int n)
{
	printf("\n\n ~(1 << n) = ");
	dectobin(~(1 << n));
	printf("\nclear nth bit = %d\n", num & ~(1 << n));
	dectobin(num & ~(1 << n));
}

int iseven(int num)
{
	if(num & 1)
		return 0;
	else
		return 1;
}

int isodd(int num)
{
	if(num & 1)
		return 1;
	else
		return 0;
}

int countbits(int v)
{
	int cnt = 0;
	while(v > 0)
	{
		cnt++;
		v >>=1;
	}
	printf("\n number of bits = %d", cnt);
	return cnt;
}

void twoscomplement(int v)
{
	int n = countbits(v);
	v = pow(2, n+1) - v;
	printf("\ntwoscomplement = ");
	dectobin(v);
}

int alternating0and1(int v)
{
	int cnt = (v&1) ? 0 : 1;
	while(v > 0)
	{
		if(v&1)
			cnt++;
		else
			cnt--;
		if(cnt > 1 || cnt < 0)
			return 0;
		v >>= 1;
	}
	return 1;
}

int countdiffbits(int a, int b)
{
	int c, cnt = 0;
	for(c = a^b; c> 0; c>>=1)
	{
		if(c & 1)
			cnt++;
	}
}

int ispowof2(int v)
{
	return v && !(v & (v-1)); //8 = 1000 and 7 = 0111
}

double log2n(int n)
{
	return n > 1 ? (1 + log2n(n/2)) : 0;
}

void main()
{
	int num;
	printf("\nenter decimal num = ");
	scanf("%d", &num);
	dectobin(num);
	dectobin(7);
	countdiffbits(7, num);
//	twoscomplement(num);
//	printf("\nlog2n(%d) = %lf\n", 5, log2n(5));
//	setnthbit(num, 2);
//	clearnthbit(num, 3);
//	flipnthbit(num, 4);
	countsetbits(num);
	char s[32];
	printf("\n\nenter binary num = ");
	scanf("%s", s);
	bintodec(s, strlen(s));
}
