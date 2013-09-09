#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void* memcpy_c(void* dst, const void* src, int len)
{
	int i;
	int numbytes = len/8;
	int leftoverbits = len%8;
	//optimization, pointers and len are word aligned and copy word at a time instead of byte at a time
	if((int)dst % sizeof(long) == 0 && (int)src % sizeof(long) == 0 && numbytes % (sizeof(long)) == 0)
	{
		long* d = dst;
		const long* s = src;
		printf("\n inside long");
		for(i = 0; i<len/(8*sizeof(long)); i++)
			d[i] = s[i];
	}
	else
	{
		char* d = dst;
		const char* s = src;
		printf("\n inside char");
		for(i=0;i<(numbytes+leftoverbits)/(sizeof(char)); i++)
			d[i] = s[i];
	}
	
	return dst;
}

void main()
{
	char* src = "Copythisa";
	printf("\nLength of string = %d\n", strlen(src));

	char* dst = (char*) malloc(sizeof(char)*strlen(src));
	dst = memcpy_c(dst, src, (strlen(src)*8)+2);
	printf("\nDestination string  = %s\n string len = %d", dst, strlent(dst));
}
