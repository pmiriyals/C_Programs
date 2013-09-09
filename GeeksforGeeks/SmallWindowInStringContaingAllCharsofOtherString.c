#include<stdio.h>

void cpyArr(int a[], int b[])
{
	int i = 0;
	while(i < 256)
		a[i] = b[i++];
}

void FindMinSub(char str[], int arr[], int l)
{
	int found = 0;
	int temp[256];
	cpyArr(temp, arr);
	int size = l;
	int i = 0,sndx = 0, endx = 0, min = 256, s = 0, e = 0, j;
	while(str[i] != '\0')
	{		
		if(temp[str[i]] > 0)
		{
			temp[str[i]]--;
			printf("\ntemp[%c] = %d\n", str[i], temp[str[i]]);
			if(size == l)
				sndx = i;
			size--;
				printf("\nfound at s= %d, e = %d i = %d, sndx = %d, endx = %d, min = %d, size = %d\n", s, e, i, sndx, endx, min, size);
			if(size == 0)
			{

				endx = i;				
				if((endx-sndx) < min)
				{
					min = endx-sndx;
					s = sndx;
					e = endx;
					found = 1;
					printf("\n%s\n", str);
					for(j = s; j<= e; j++)
					{
						putchar(str[j]);
					}
					putchar('\n');
				}
				size = l;
				i = sndx + 1;
				cpyArr(temp,arr);
			}
			
		}
		i++;
	}
	if(found)
	{
		for(j = s; j<= e; j++)
		{
			putchar(str[j]);
		}
		printf("\nMin len = %d\n", e-s);
	}
}

void main()
{
	int arr[256];
	int i;
	for(i=0; i< 256; i++)
		arr[i] = 0;
	char c;
	int len = 0;
	while((c=getchar()) != 'q')
	{
		len++;
		arr[c]++;
	}
	FindMinSub("this is a test string", arr, len);	
}
