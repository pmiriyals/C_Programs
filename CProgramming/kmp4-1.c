#include<stdio.h>
#include<string.h>

void computelps(char* pat, int* lps, int lp)
{
	int len = 0;
	int i = 1;
	lps[0] = 0;

	while(i < lp)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
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

void kmp(char* txt, char* pat)
{
	int lt = strlen(txt);
	int lp = strlen(pat);
	int lps[lp];
	computelps(pat, lps, lp);
	int i = 0, j = 0;;

	while(i < lt)
	{
		if(txt[i] == pat[j])
		{
			i++;
			j++;
		}

		if(j == lp)
		{
			printf("\n string found at ndx = %d\nstring = %s\n", i-j, txt+i-j);
			j = lps[j-1];
		}
		else if(txt[i] != pat[j])
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

void main()
{
	char txt[] = "How would or should could test this pattern";
	char pat[] = "ould";
	kmp(txt, pat);
}
