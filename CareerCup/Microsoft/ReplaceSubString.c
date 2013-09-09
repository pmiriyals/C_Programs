#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256

//void copystring(char* front, char* res

void Cleanup(char* str)
{
	int i = 0, j = 0;
	while(str[i] != '\0')
	{
		if(str[i] != '%')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void FindSubStr(char* str, char* pat, int ls, int lp, char* rep, int isCleanupReq)
{
	int bad_char_skip[257];
	int i;
	for(i = 0; i< 257; i++)
		bad_char_skip[i] = lp;

	int last = lp-1;
	for(i = 0; i < last; i++)
		bad_char_skip[pat[i]] = last-i;
		
	char* front = str;	

	while(ls >= lp)
	{

		for(i = last; str[i] == pat[i]; i--)
		{		
			if(i<=0)
			{
				for(i=0; i<=last;i++)
				{
					str[i] = rep[i];
				}
			}
		}
	
		ls -= bad_char_skip[str[last]];
		str += bad_char_skip[str[last]];					
	}

	if(isCleanupReq > 0)
		Cleanup(front);
	printf("\nreplaced string = %s\n", front);
}

char* boyer_moore_horspool_memmem(char* haystack,char* needle,int hlen,int nlen)
{
	if(nlen > hlen || nlen<= 0 || haystack == NULL || needle == NULL) return NULL;

	char bad_char_skip[MAX];
	int i, scan;
	for(i = 0; i < MAX; i++)
	{
		bad_char_skip[i] = nlen;
	} 

	int last = nlen-1;
	printf("\nlast = %d\n", last);
	for(scan = 0; scan < last; scan++)
		bad_char_skip[needle[scan]] = last - scan;

	while(hlen >= nlen)
	{	
		for(scan = last; haystack[scan] == needle[scan]; scan--)
		{		
			if(scan == 0)
				return haystack;
		}

		hlen -= bad_char_skip[haystack[last]];
		haystack += bad_char_skip[haystack[last]];
	}
	return NULL;
}

void main()
{
	char haystack[] = "This is a string in a stream of strolling places for street view strenching streak.";
	int hlen = sizeof(haystack)/sizeof(char);	//includes '\0', where as strlen excludes this.
	char needle[] = "str";
	int nlen = strlen(needle);
	char rep[] = "X";
	int rlen = strlen(rep);
	char* nrep;
	int i=0;
	nrep = malloc(sizeof(char)*nlen);

	if(nlen >= rlen)
	{
		strcpy(nrep, rep);
		for(i=rlen; i < nlen; i++)
			nrep[i] = '%';
	}
	else
		return;
	printf("\n string before replace = %s\n\n", haystack);

	FindSubStr(haystack, needle, hlen, nlen, nrep, nlen-rlen);
	printf("\n");
}
