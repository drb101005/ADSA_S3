#include <stdio.h> 
#define N 4 
int board[N][N]; 
// Function to check if placing queen at board[row][col] is safe 
int isSafe(int row, int col) { 
int i, j; 
// Check column 
for (i = 0; i < row; i++) 
if (board[i][col]) return 0; 
// Check upper-left diagonal 
for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
if (board[i][j]) return 0; 
// Check upper-right diagonal 
for (i = row, j = col; i >= 0 && j < N; i--, j++) 
if (board[i][j]) return 0; 
return 1; 
} 
// Backtracking function 
int solve(int row) { if (row == N) return 1; // All queens placed 
for (int col = 0; col < N; col++) { 
if (isSafe(row, col)) { 
board[row][col] = 1; // Place queen 
if (solve(row + 1)) return 1; // Move to next row 
board[row][col] = 0; // Backtrack 
} 
} 
return 0; 
} 
// Print the board 
void printBoard() { 
for (int i = 0; i < N; i++) { 
for (int j = 0; j < N; j++) 
printf("%d ", board[i][j]); 
printf("\n"); 
} 
} 
int main() { 
if (solve(0)) 
printBoard(); 
else 
printf("No solution\n"); 
return 0; 
}