#include <stdio.h>
#define N 5
void printBoard(int board[N][N])
{
    int i, j;
    int solutionArr[N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(board[i][j]==1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}
int isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for(i=0;i<row;i++)
    {
        if(board[i][col]==1)
            return 0;
    }
    for(i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j]==1)
            return 0;
    }
    for(i=row-1,j=col+1; i>=0 && j<N; i--,j++)
    {
        if(board[i][j]==1)
            return 0;
    }

    return 1;
}
int solveNQueens(int board[N][N], int row)
{
    int col;
    if(row==N)
    {
        printBoard(board);
        return 1;
    }
    for(col=0; col<N; col++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]=1;
            if(solveNQueens(board,row+1))
                return 1;
            board[row][col]=0;
        }
    }
    return 0;
}
int main()
{
    int board[N][N]={0};
    if(solveNQueens(board,0)==0)
        printf("No Solution Exists");
    return 0;
}
