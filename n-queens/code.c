//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
#include <stdio.h>

#define MAX 20

int board[MAX];
int n;
int solutionCount = 0;

// Check whether queen can be placed at (row, col)
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {

        // Same column
        if (board[i] == col)
            return 0;

        // Same diagonal
        if ((i - board[i]) == (row - col))
            return 0;

        // Same anti-diagonal
        if ((i + board[i]) == (row + col))
            return 0;
    }
    return 1;
}

// Print one solution
void printSolution() {
    solutionCount++;

    printf("\nSolution %d:\n", solutionCount);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Backtracking function
void solve(int row) {

    // All queens placed
    if (row == n) {
        printSolution();
        return;
    }

    // Try every column in current row
    for (int col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            board[row] = col;   // Place queen

            solve(row + 1);     // Recur for next row
        }
    }
}

int main() {

    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(0);

    if (solutionCount == 0)
        printf("No solution exists\n");

    return 0;
}
