#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int atoint(char* s)
{
	int l = strlen(s);
	int i = 0, num = 0;

	while(isspace(s[i]))
		i++;

	if(i >= l) 
		return -1;

	int sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '-' || s[i] == '+')
		i++;

	while(isdigit(s[i]))
		num = (num*10) + s[i++]-'0';

	printf("\nconverted number = %d\n", num*sign);
	return num*sign;
}

double atofloat(char* s)
{
	int i, sign;
	double val, power;

	for(i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++)
		val = val*10.0 + s[i] - '0';

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = val*10 + s[i] -'0';
		power *= 10.0;
	}

	val = (sign * val)/power;
	printf("\n atof(%s) = %lf\n", s, val);
	return val;
}

void itoa(int n)
{
	int sign;
	int i = 11;
	char* s = malloc(sizeof(char) * 12);
	s[i--] = '\0';

	if((sign = n) < 0)
		n = -n;

	while(i >= 0 && n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	if(sign < 0 && i >= 0)
		s[i] = '-';
	else if(i >= 0)
		s[i] = '+';

	s += i;
	printf("\nitoa(%d) = %s\n", sign, s);
}

int htoi(char* s)
{
	int i = 0;
	int l = strlen(s);
	int num = 0;

	while(isspace(s[i]))
		i++;
	
	if(i < l-1 && s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
		i+=2;

	for(; isalnum(s[i]); i++)
	{
		num *= 16;
		if(isdigit(s[i]))
		{
			num += s[i] - '0';
		}
		else if(s[i] >= 'a' && s[i] <= 'f')
		{
			num += s[i] - 'a' + 10;
		}
		else if(s[i] >= 'A' && s[i] <= 'F')
		{
			num += s[i] - 'A' + 10;
		}
	}

	printf("\n htoi(%s) = %d\n", s, num);
	return num;
}

//itob(int n, char s, int b): convert integer n to base b into character rep in s. 3-5

void main()
{
	atoint("       +123");
	htoi("        0x1A2");
	itoa(-1313);
	atofloat("          -1231.2352");
}
