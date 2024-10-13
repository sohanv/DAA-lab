#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N_MAX 20 // Maximum board size supported

int answers = 0;
// Function prototypes
void printBoard(bool board[][N_MAX], int N);
bool isSafe(bool board[][N_MAX], int N, int row, int col);
bool solveNQueens(bool board[][N_MAX], int N, int row);
void solveNQueensWrapper(int N);

// Global variable to count comparisons
int comparisons = 0;

// Function to print the board configuration
void printBoard(bool board[][N_MAX], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j]) printf(" Q ");
            else printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(bool board[][N_MAX], int N, int row, int col) {
    comparisons++; // Increment comparison count

    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        comparisons++; // Increment comparison count
        if (board[i][col]) return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        comparisons++; // Increment comparison count
        if (board[i][j]) return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        comparisons++; // Increment comparison count
        if (board[i][j]) return false;
    }

    return true;
}

// Function to solve the N Queens problem using backtracking
bool solveNQueens(bool board[][N_MAX], int N, int row) {
    // Base case: If all queens are placed, return true
    if (row == N) {
        printBoard(board, N);
        answers++;
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, N, row, col)) {
            // Place the queen
            board[row][col] = true;

            // Recur to place the rest of the queens
            res = solveNQueens(board, N, row + 1) || res;

            // If placing queen at board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = false;
        }
    }

    return res;
}

// Function to initialize and solve the N Queens problem
void solveNQueensWrapper(int N) {
    bool board[N_MAX][N_MAX] = { false }; // Initialize board with all false values

    clock_t start = clock(); // Start timing

    if (!solveNQueens(board, N, 0)) {
        printf("No solution exists\n");
    }

    clock_t end = clock(); // End timing

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", cpu_time_used);
    printf("Comparisons: %d\n", comparisons);
}

int main() {
    int N;

    // Input board size from user
    printf("Enter the size of the board (N, max %d): ", N_MAX);
    scanf("%d", &N);

    if (N < 1 || N > N_MAX) {
        printf("Invalid board size. Please enter a size between 1 and %d.\n", N_MAX);
        return 1; // Exit program with error code
    }

    solveNQueensWrapper(N);
    printf("\nnumber of solutions = %d",answers);
    return 0;
}

