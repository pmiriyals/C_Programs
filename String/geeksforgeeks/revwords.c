#include<stdio.h>
#include<string.h>

#define IN 1
#define OUT 0

void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

void reverseWords(char *s)
{
  char *word_begin = s;
  char *temp = s; 
  int state = OUT;
  while( *temp )
  {
    if (isalnum(*temp) && state == OUT)
    {
      word_begin = temp;
      state = IN;
    }
    else if((*temp == ' ' || *temp == '\t') && state == IN)
    {
      reverse(word_begin, temp-1);
      state = OUT;
    }
    else if(*(temp+1) == '\0' && state == IN)
    {
	reverse(word_begin, temp);
    }
    temp++;
  } 

  reverse(s, temp-1);
}

void main()
{
  char s[] = "  i    like this program very much";
  reverseWords(s);
  printf("\n%s\n", s);
}
