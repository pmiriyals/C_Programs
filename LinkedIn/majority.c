#include<stdio.h>

int findcandidate(int a[], int l)
{
	if(l <= 0)
		return -1;

	int cnt = 1;
	int maj = a[0];
	int i = 1;
	while(i < l)
	{
		if(maj == a[i])
			cnt++;
		else
		{
			cnt--;
			if(cnt == 0)
			{
				cnt = 1;
				maj = a[i];
			}
		}
		i++;
	}	
	return maj;
}

int ismajority(int a[], int l, int maj)
{
	int cnt = 0;
	int i = 0;
	while(i < l)
	{
		if(a[i++] == maj)
		{
			cnt++;
			if(cnt > l/2)
				return 1;
		}
	}
	return 0;
}

int findmajority(int a[], int l)
{
	int x = findcandidate(a, l);
	if(ismajority(a, l, x))
		return x;
	else
		return -1;
}

void main()
{
	int a[] = {1, 4, 2, 6, 1, 1, 6, 1, 1};
	printf("\n majority element = %d\n", findmajority(a, sizeof(a)/sizeof(int)));
}
