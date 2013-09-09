#include<stdio.h>
#include<string.h>

void revstr(char* s, int sndx, int endx)
{
	char temp;
	while(sndx < endx)
	{
		temp = s[sndx];
		s[sndx] = s[endx];
		s[endx] = temp;
		sndx++;
		endx--;
	}
}

void rev(char* begin, char* end)
{
	char temp;
	while(begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

void RevWordSeq(char* s)
{
	char* temp = s;	
	char* begin = NULL;
	while(*temp != '\0')
	{
		
		if(begin == NULL && (*temp != ' ' || *temp!= '\t'))
			begin = temp;

		if(begin && (*(temp+1) == ' ' || *(temp+1) == '\t' || *(temp+1) == '\0'))
		{
					
			rev(begin, temp);
			begin = NULL;
		}
		temp++;
	}
	rev(s, temp-1);
}

void main()
{
	char s[500];
	char c;
	int i = 0;
	while((c = getchar()) != 'q')
		s[i++] = c;

	s[i] = '\0';
	RevWordSeq(s);
	printf("\nrev = %s\n", s);	
}
