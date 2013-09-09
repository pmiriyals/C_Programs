#include<stdio.h>

int findcandidate(int* arr, int len)
{
	int majority = arr[0];
	int cnt = 1, i;
	for(i = 1; i< len; i++)
	{
		if(majority == arr[i])
			cnt++;
		else
			cnt--;			
		if(cnt == 0)
		{
			majority = arr[i];
			cnt = 1;
		}
	}
	return majority;
}

//O(n)
void main()
{
	int arr[] = {1,3, 2, 3, 20, 15, 3, 3, 3, 10};
	
	int len = sizeof(arr)/sizeof(int);
	int i, cnt = 0;
	int majority = findcandidate(arr, len);
	for(i = 0; i< len; i++)
	{
		if(arr[i] == majority)
			cnt++;
	}
	if(cnt > len/2)
		printf("\nmajority element = %d\n", majority);
	else
		printf("\nMajority element does not exist\n");
}
