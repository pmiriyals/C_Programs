#include<stdio.h>
#include<stdlib.h>

//O(n), Space: O(n)
int ischarunique(char* s)
{
	int* cnt = calloc(256, sizeof(int));
	while(*s)
	{
		if(cnt[*s])
			return 0;		
		cnt[*s++] = 1;
	}
	return 1;
}

//no extra space; works for only lower case chars
//idea is to generate unique binary numbers for each char
//ranging from 1e0 to 1e26
//anding each binary should give 0
//O(n)
int ischaruniqueInline(char* s)
{
	int checker = 0;
	int val;
	while(*s)
	{
		val = *s - 'a';
		if((checker & (1 << val)) > 0)
			return 0;
		checker |= 1<<val;
		s++;
	}
	return 1;
}

//other methods include,
//Use two loops O(n2)
//Sort the string and iterate, O(nlogn)
void main()
{
	char s[] = "is chara";
	printf("\nis char unique = %s\n", ischarunique(s) ? "Yes" : "No");
	printf("\nis char unique with no extra space = %s\n", ischaruniqueInline(s) ? "Yes" : "no");
}
