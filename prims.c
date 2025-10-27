#include <stdio.h> 
#define INF 999999 
int main() { 
int n, i, j, a, b, edges = 0, total = 0, min; 
int cost[10][10], visited[10] = {0}; 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
printf("Enter cost adjacency matrix:\n"); 
for (i = 0; i < n; i++) 
for (j = 0; j < n; j++) { 
scanf("%d", &cost[i][j]); 
if (cost[i][j] == 0) cost[i][j] = INF; 
} 
visited[0] = 1; 
while (edges < n - 1) { 
min = INF; 
for (i = 0; i < n; i++) 
if (visited[i]) 
for (j = 0; j < n; j++) 
if (!visited[j] && cost[i][j] < min) { 
min = cost[i][j]; 
a = i; b = j; 
} 
printf("Edge %d: %d - %d cost: %d\n", edges + 1, a, b, min); 
visited[b] = 1; 
total += min; 
edges++; 
} 
printf("Minimum cost = %d\n", total); 
return 0; 
}