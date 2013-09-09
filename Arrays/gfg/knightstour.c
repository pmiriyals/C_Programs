#include<stdio.h>
#include<stdlib.h>

#define N 8

int isSafe(int x, int y, int sol[N][N])
{
    if ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
        return 1;
    return 0;
}


void printSolution(int sol[N][N])
{
	int x, y;
    for (x = 0; x < N; x++)
    {
        for ( y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N],
                int yMove[N])
{
   int k, next_x, next_y;
   if (movei == N*N)
       return 1;
 
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
printf("\nxnext = %d\nynext = %d\nmove = %d\nk = %d", next_x, next_y, movei, k);
       if (isSafe(next_x, next_y, sol))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove) == 1)
             return 1;
         else
             sol[next_x][next_y] = -1;// backtracking
       }
   }
 
   return 0;
}


int KTUtil(int x, int y, int imove, int chess[N][N], int* xmove, int* ymove)
{
	if(imove == N*N)
		return 1;

	int k;
	for(k = 0; k<N; k++)
	{
		int x_next = x + xmove[k];
		int y_next = y + ymove[k];
	printf("\nxnext = %d\nynext = %d\nmove = %d\nk = %d", x_next, y_next, imove, k);
		if(isSafe(x_next, y_next, chess))
		{
			chess[x_next][y_next] = imove;
			if(KTUtil(x_next, y_next, imove+1, chess, xmove, ymove) == 1)
				return 1;
			else
				chess[x_next][y_next] = -1;	//backtrack
		}
	}
	return 0;
}

int solveKT()
{
    int sol[N][N], x, y;
 
    /* Initialization of solution matrix */
    for (x = 0; x < N; x++)
        for (y = 0; y < N; y++)
            sol[x][y] = -1;
 
    /* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
 
    // Since the Knight is initially at the first block
    sol[0][0]  = 0;
 
    /* Start from 0,0 and explore all tours using solveKTUtil() */
    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }
    else
        printSolution(sol);
 
    return 1;
}

void KnightsTour()
{
	int chess[N][N];
	int x, y;
	for(x = 0; x < N; x++)
		for(y = 0; y < N; y++)
			chess[x][y] = -1;

	chess[0][0] = 0;	//starting position

	int xmove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int ymove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

	printf("\n has found a tour = %d\n", solveKTUtil(0, 0, 1, chess, xmove, ymove)); 
	for(x = 0; x<N; x++)
		for(y = 0; y<N; y++)
			if(chess[x][y] >= 0)
				printf(" (%d, %d) -> ", x, y);

	printf("\n");
	printSolution(chess);
}

void main()
{
//	solveKT();
	KnightsTour();
}
