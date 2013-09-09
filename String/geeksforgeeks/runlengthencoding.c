#include<stdio.h>
#include<string.h>

void RunLengthEncoding(char* s)
{
	char* temp = s;
/*** If each char in s is different then destination string size will be 
 *** twice that of the original size***/
	char* dest = malloc(sizeof(char) * (strlen(s) * 2 + 1));

	int ndx = 0, cnt = 0;
	char c = *s;
	while(*temp)
	{
		if(c == *temp)
		{
			cnt++;
		}
		if(c != *temp || *(temp+1) == '\0')
		{
			dest[ndx++] = c;
			dest[ndx++] = '0' + cnt;
			c = *temp;
			cnt = 1;
		}
		temp++;
	}
	dest[ndx] = '\0';
}

void main()
{
	char s[] = "aaaaaxxxxxxxpppppuuu";
	RunLengthEncoding(s);
	printf("\nAfter length encoding = %s\n", s);
}
