#include <stdio.h> 
#include <stdbool.h> 
 
#define MAX 20 
 
void printSolution(int board[MAX][MAX], int N) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            if (board[i][j]) 
                printf(" Q "); 
            else 
                printf(" . "); 
        } 
        printf("\n"); 
    } 
} 
 
bool isSafe(int board[MAX][MAX], int row, int col, int N) { 
    for (int i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
 
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
 
    return true; 
} 
 
bool solveNQUtil(int board[MAX][MAX], int col, int N) { 
    if (col >= N) 
        return true; 
 
    for (int i = 0; i < N; i++) { 
        if (isSafe(board, i, col, N)) { 
            board[i][col] = 1; 
 
            if (solveNQUtil(board, col + 1, N)) 
                return true; 
 
            board[i][col] = 0; 
        } 

 
    } 
    return false; 
} 
 
bool solveNQ(int N) { 
    int board[MAX][MAX] = {0}; 
 
    if (!solveNQUtil(board, 0, N)) { 
        printf("Solution does not exist"); 
        return false; 
    } 
 
    printSolution(board, N); 
    return true; 
} 
 
int main() { 
    int N; 
    printf("Enter the number of queens: "); 
    scanf("%d", &N); 
    solveNQ(N); 
    return 0; 
}