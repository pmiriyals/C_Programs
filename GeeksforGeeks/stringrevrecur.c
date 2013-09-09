#include<stdio.h>
#include<string.h>

void printrev(char* s)
{
	if(*s == '\0')
		return;
	printrev(s+1);
	putchar(*s);
}

void main()
{
	char a[] = "reverse this";
	printrev(a);
	printf("\n");
}
