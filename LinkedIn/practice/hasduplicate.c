#include<stdio.h>

int fromDecimal1(int n, int b)
{
   int result=0;
   int multiplier=1;
      
   while(n>0)
   {
      result+=n%b*multiplier;
      multiplier*=10;
      n/=b;
   }
      
   return result;
}

int fromDecimal(int n, int b)
{
	int result = 0;
	int m = 1;

	while(n > 0)
	{
		result += (n%b) * m;
		m *= 10;
		n /= b;
	}
	printf("\n binary = %d\n", result);
	return result;
}

int hasdup(char* s)
{
	int checker = 0;
	int i = 0, val;

	while(*(s+i) != '\0')
	{
		if(*(s+i) >= 'a' && *(s+i) <= 'z')
			val = *(s+i) - 'a';
		else
			val = *(s+i) - 'A';
//		printf("\n checker = %d\tbin(checker) = %d\t1<<val = %d\tval = %d\t *(s+i) = %c", checker, fromDecimal1(checker, 2), fromDecimal(1 << val, 2), val, *(s+i));
		if((checker & (1 << val)) > 0)
			return 0;
		checker |= (1<< val);
		i++;
	}
	return 1;
}

void remdup(char* s)
{
	int i = 0, j = 0;
	int lchecker = 0, uchecker = 0, lval, uval;

	while(*(s+i) != '\0')
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			lval = *(s+i) - 'a';
			if((lchecker & (1 << lval)) > 0)
			{
				i++;
				continue;
			}
			lchecker |= 1<<lval;
		}
		else if(s[i] >= 'A' && s[i] <= 'Z')
		{
			uval = s[i] - 'A';
			if((uchecker & (1 << uval)) > 0)
			{
				i++;
				continue;
			}
			uchecker |= 1<<uval;
		}		

		s[j++] = s[i++];		
	}
	s[j] = '\0';
	printf("\nafter removing duplicates = %s\n", s);
}

void main()
{
	char s[] = "aAaABb";
	printf("\nhas duplicate = %s\n", hasdup(s) ? "No duplicates" : "Yes");
//	remdup(s);
	printf("\n1<<5 = %d\n", 1<<5);
	fromDecimal(1<<5, 2);
	fromDecimal((1 << 5) -1, 2);
}
