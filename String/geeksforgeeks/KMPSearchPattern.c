#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//O(m)
void ComputeLPS(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;

	while(i < M)
	{
		if(pat[len] == pat[i])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len-1]; //Backtrack. We do not increment i here.
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

//O(n)
void KMPSearch(char* txt, char* pat)
{
	int N = strlen(txt);
	int M = strlen(pat);
	int* lps = (int*)malloc(sizeof(int)* M);
	ComputeLPS(pat, M, lps);

	int iTxt = 0, iPat = 0; // index of text and pattern

	while(iTxt < N)
	{
		if(txt[iTxt] == pat[iPat])
		{
			iTxt++;
			iPat++;
		}
		if(iPat == M)
		{
			printf("\n Match found at index = %d, remaining string = %s\n", iTxt-iPat, txt+iTxt-iPat);
			//printf("\n Match found at index = %d", iTxt-iPat);
			iPat = lps[iPat-1];	//similar to mismatch case
		}
		else if(txt[iTxt] != pat[iPat])
		{
			if(iPat != 0)
				iPat = lps[iPat-1];
			else
				iTxt++;
		}
	}
	free(lps);
}

void main()
{
	char txt[] = "Finding a patterning in this in texting";
	char pat[] = "ing";

	KMPSearch(txt, pat);
}
