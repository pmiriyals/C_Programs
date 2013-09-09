#include<stdio.h>
#include<string.h>

void append(char* a, char* b)
{
	int i = strlen(a);
	while(*b)
	{
		a[i++] = *b;
		b++;
	}
	a[i] = '\0';
}

void computelps(int lps[], char* pat, int l)
{
	int i = 1, len = 0;
	lps[0] = len;
	while(i < l)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i++] = len;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int kmp(char* txt, char* pat, int lt, int lp)
{
	int lps[lp];
	int i = 0, j = 0;
	computelps(lps, pat, lp);
	while(i < lt)
	{
		if(txt[i] == pat[j])
		{
			i++;
			j++;
		}
		if(j == lp)
		{
			return 1;			
		}
		else if(txt[i] != pat[j])
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	return 0;
}

int isrot(char* s, char* p)
{
	int ls = strlen(s);
	int lp = strlen(p);
	if(ls != lp)
		return 0;

	char txt[2*ls + 1];
	append(txt, s);
	append(txt, s);

	return kmp(txt, p, strlen(txt), lp);
}

//O(n)
//concatenate the same string and check if the other is a substring.
void main()
{
	char s[] = "tionrota";
	char p[] = "rotation";
	printf("\nis rotation = %s\n", isrot(s, p) ? "Yes" : "no");
}
