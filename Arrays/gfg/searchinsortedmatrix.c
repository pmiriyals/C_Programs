#include<stdio.h>

int search(int mat[4][4], int n, int x)
{
	int i = 0, j = n-1;

	while(i < n && j >=0)
	{
		if(mat[i][j] == x)
		{
			printf("\n Found at %d, %d", i, j);
			return 1;
		}
		else if(mat[i][j] < x)
			i++;
		else
			j--;
	}
}

void main()
{
	int mat[4][4] = {{5, 10, 15, 20}, 
			 {7, 12, 17, 25},
			 {8, 13, 18, 29},
			 {9, 14, 19, 30}};
	printf("\n Is element exists = %s\n", search(mat, 4, 29) ? "Yes" : "No");
}
