#include <stdio.h> 
// Function to get the maximum of two numbers 
int max(int a, int b) { 
return (a > b) ? a : b; 
} 
// Knapsack function 
int knapsack(int W, int wt[], int val[], int n) { 
int i, w; 
int dp[n + 1][W + 1]; 
// Build table dp[][] in bottom-up manner 
for (i = 0; i <= n; i++) { 
for (w = 0; w <= W; w++) { 
if (i == 0 || w == 0) 
dp[i][w] = 0; 
else if (wt[i - 1] <= w) 
dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]); 
else 
dp[i][w] = dp[i - 1][w]; 
} 
} 
return dp[n][W]; 
} 
int main() { 
int n, W; 
printf("Enter number of items: "); 
scanf("%d", &n); 
int val[n], wt[n]; 
printf("Enter values of the items:\n"); 
for (int i = 0; i < n; i++) { 
printf("Value of item %d: ", i + 1); 
scanf("%d", &val[i]); 
} printf("Enter weights of the items:\n"); 
for (int i = 0; i < n; i++) { 
printf("Weight of item %d: ", i + 1); 
scanf("%d", &wt[i]); 
} 
printf("Enter capacity of knapsack: "); 
scanf("%d", &W); 
int result = knapsack(W, wt, val, n); 
printf("Maximum value in knapsack: %d\n", result); 
return 0; 
} 