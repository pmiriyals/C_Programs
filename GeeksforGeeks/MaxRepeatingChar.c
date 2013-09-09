#include<stdio.h>
#include<stdlib.h>

void main()
{
	char arr[] = "LaaaLapere";
	int i, ctr = 0, ch;
	int* s = (int*) calloc(256, sizeof(char));
	i = 0;
	while(arr[i] != '\0')
	{
		s[arr[i]]++;
		if(ctr < s[arr[i]])
		{
			ctr = s[arr[i]];
			ch = arr[i];
		}
		i++;
	}

	printf("\n The character %c appears %d times\n", ch, ctr);
}
