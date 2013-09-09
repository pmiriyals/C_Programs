#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void computelps(char* pat, int* lps, int l)
{
	int len = 0;
	lps[0] = 0;
	int i =  1;
	while(i < l)
	{
		if(pat[i] == pat[len])
		{
			len++;
			i++;
			lps[i] = len;
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

void kmp(char* txt, char* pat)
{
	int lt = strlen(txt);
	int lp = strlen(pat);
	int* lps = calloc(lp, sizeof(int));
	computelps(pat, lps, lp);

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
			printf("\n index = %d\n pattern = %s\n\n", i-j, txt+i-j);
			j = lps[j-1];
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
	char txt[] = "Searching for string pattering ending here";
	char pat[] = "ing";
	kmp(txt, pat);
}
