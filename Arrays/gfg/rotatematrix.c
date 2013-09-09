#include<stdio.h>

#define m 2
#define n 3

void printMatrix(int mat[m][n], int x, int y)
{
	int i, j;

	for(i = 0; i < x; i++)
	{
		for(j = 0; j< y; j++)
		{
			printf(" %2d ", mat[i][j]);
		}
		printf("\n");
	}
}

void printMatrixB(int mat[n][m], int x, int y)
{
	int i, j;

	for(i = 0; i < x; i++)
	{
		for(j = 0; j< y; j++)
		{
			printf(" %2d ", mat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int A[m][n] = {{1, 2, 3}, {4, 5, 6}};
	int B[n][m];

	int x, y, i, j;
	printf("\nMatrix A = %d\n", A[1][1]);
	printMatrix(A, m, n);

	for(x = 0; x < m; x++)
	{
		for(y = 0; y < n; y++)
		{
			B[y][m-x-1] = A[x][y];
		}
	}
	printf("\nMatrix B = \n");
//		n = 2; m = 3;
	printMatrixB(B, n, m);
}
