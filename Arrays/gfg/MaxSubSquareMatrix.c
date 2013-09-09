#include<stdio.h>

#define R 6
#define C 5

int min(int a, int b, int c)
{
	int x = (a < b) ? a : b;
	return (c < x) ? c : x;
}

void printMaxSubSquare(int M[R][C])
{
	int i, j;
	int S[R][C];
	int max_of_s, max_i, max_j;

	for(j = 0; j < C; j++)
	{
		S[0][j] = M[0][j];
	}
	for(i = 0; i< R; i++)
	{
		S[i][0] = M[i][0];
	}	

	for(i=1; i< R; i++)
	{
		for(j = 1; j < C; j++)
		{
			if(M[i][j] == 1)
			{
				S[i][j] = min(M[i][j-1], M[i-1][j], M[i-1][j-1]) + 1;
			}
			else
				S[i][j] = 0;
		}
	}

	max_of_s = 0;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			if(S[i][j] > max_of_s)
			{
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	printf("\n %d\n", max_of_s);

	for(i = max_i; i > max_i - max_of_s; i--)
	{
		for(j = max_j; j > max_j - max_of_s; j--)
		{
			printf(" %d ", M[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int M[R][C] = { {0, 1, 1, 0, 1},
		      {1, 1, 0, 1, 0},
        	      {0, 1, 1, 1, 0},
	 	      {1, 1, 1, 1, 0},
	     	      {1, 1, 1, 1, 1},
		      {0, 0, 0, 0, 0}};

	printMaxSubSquare(M);
}
