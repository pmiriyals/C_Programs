#include<stdio.h>
#include<time.h>

int binsearch(int x, int v[], int n)
{
	int low = 0;
	int high = n-1;
	int mid;

	while(low <= high)
	{
		mid = low + (high-low)/2;

		if(x < v[mid])
			high = mid-1;
		else if(x > v[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}

int binoptimized(int x, int v[], int n)
{
	int low = 0;
	int high = n-1;
	int mid = low + (high-low)/2;

	while(low<=high && v[mid] != x)
	{
		if(v[mid] < x)
			low = mid+1;
		else
			high = mid-1;
		mid = low + (high-low)/2;
	}
	return v[mid] == x;
}

void main()
{
	int v[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 8, 9, 12, 15, 20};
	int n = sizeof(v)/sizeof(int);
	int x = 15;
	clock_t t;	
	t = clock();	
	printf("\nis element found = %s\n", binsearch(x, v, n) == -1 ? "No" : "Yes");
	t = clock() - t;
	double time_taken = ((double)t);///CLOCKS_PER_SEC; // in seconds
	printf("\ntime taken = %lf\n", time_taken);
	printf("\nis element found = %s\n", binoptimized(x, v, n) ? "Yes" : "No");
}
