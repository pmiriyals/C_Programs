#include<stdio.h>
#include<string.h>

#define MAX 256

void SearchsubStringVariation(char* haystack,char* needle,int hlen,int nlen)
{
	if(nlen > hlen || nlen<= 0 || haystack == NULL || needle == NULL) return;

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
				printf("\n%s\n", haystack);
		}

		hlen -= bad_char_skip[haystack[last]];
		haystack += bad_char_skip[haystack[last]];
	}
	return;
}

//Avg case O(n) where n is length of haystack and m is length of needle
//Worst case O(mn)

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
	int nlen = sizeof(needle)/sizeof(char);
	SearchsubStringVariation(haystack, needle, hlen, nlen-1);
}
