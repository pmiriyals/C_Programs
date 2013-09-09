#include<stdio.h>

void revArr(int* a, int start, int end)
{
	int temp;
	while(start < end)
	{
		temp = a[start];
		a[start++] = a[end];
		a[end--] = temp;
	}
}

//O(n), 2 passes
void RightRotateArr(int* a, int len, int rot)
{
	revArr(a, 0, len-rot);
	revArr(a, len-rot+1, len);
	revArr(a, 0, len);
}
//O(n)
void LeftRotate(int* a, int len, int rot)
{
	revArr(a, 0, rot-1);
	revArr(a, rot, len);
	revArr(a, 0, len);
}

void main()
{
	int a[] = {5, 2, 9, 10, 15, 20};
	int len = sizeof(a)/sizeof(int);
	RightRotateArr(a, len-1 , 2);
	int i;
	printf("\n Rotate array = ");
	for(i = 0; i< len; i++)
	{
		printf(" %d ", a[i]);
	}
	printf("\n");
}
