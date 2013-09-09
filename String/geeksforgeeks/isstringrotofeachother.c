#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isrot(char* s1, char* s2)
{
	char* s = malloc(sizeof(char) * strlen(s1) * 2 + 1);
	strcat(s, s1);
	strcat(s, s1);
	void* ptr = NULL;
	ptr = strstr(s, s2);
	if(ptr)
		return 1;
	else
		return 0;
}

void main()
{
	char s1[] = "CDABA";
	char s2[] = "ABCD";
	printf("\n isrot = %s\n", isrot(s1, s2) ? "true" : "false");
}
