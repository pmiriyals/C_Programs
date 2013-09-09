#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void computelps(int* lps, char* pat, int lp)
{
	int len = 0;
	int i = 1;
	lps[0] = 0;

	while(i < lp)
	{
		if(pat[i] == pat[len])
		{
			len++;
			pat[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				pat[i] = 0;
				i++;
			}
		}
	}
}

void kmp(char* txt, char* pat)
{
	int lt = strlen(txt);
	int lp = strlen(pat);

	int* lps = calloc(lp, sizeof(int));

	int i = 0, j = 0;

	while(i < lt)
	{
		if(txt[i] == pat[j])
		{
			i++;
			j++;
		}

		if(j == lp)
		{
			printf("\npat found at ndx = %d, rest  = %s", i-j, txt+i-j);
			j = 0;
		}
		else if(txt[i] != pat[j])
		{
			if(j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
}

void main()
{
	char txt[] = "bubblebubble whats the trouble";
	char pat[] = "bble";
	kmp(txt, pat);
}
