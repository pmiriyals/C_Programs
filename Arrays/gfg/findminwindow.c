#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void findMinWindow(char* s, char* pat)
{
	int ls = strlen(s);
	int lp = strlen(pat);

	int* needToFind = calloc(256, sizeof(int));
	int* hasFoundSoFar = calloc(256, sizeof(int));

	int i;
	//Construct count array
	for(i = 0; i < lp; i++)
	{
		needToFind[pat[i]]++;
	}

	int cnt = 0;
	int si = 0, ei = 0; //start and end indexes
	int reset = 1;
	for(i = 0; i< ls; i++)
	{
		if(needToFind[s[i]] > 0)	//if there is a match
		{
			if(hasFoundSoFar[s[i]] < needToFind[s[i]])
				cnt++;
			hasFoundSoFar[s[i]]++;
			if(cnt == 1)
				si = i;

			if(cnt == lp && s[si] == s[i])	//advance start index
			{
				while(si < ls && ((needToFind[s[si]] == 0) || (hasFoundSoFar[s[si]] > needToFind[s[si]])))
				{
					if(hasFoundSoFar[s[si]] > 0)
					{
						hasFoundSoFar[s[si]]--;
					}
					si++;
				}
				reset = 1;	//reset end index
			}

			if(cnt == lp && reset == 1)
				ei = i;
			reset = 0;
		}
	}

	printf("\n start index = %d && end index = %d\n", si, ei);
}

void main()
{
	char s[] = "acbbaca";
	char pat[] = "aba";
	findMinWindow(s, pat);
}
