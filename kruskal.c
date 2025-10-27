#include <stdio.h> 
#define INF 999 
int parent[10]; 
int find(int i) { 
while (parent[i]) i = parent[i]; 
return i; 
} 
int uni(int i, int j) { 
if (i != j) { 
parent[j] = i; 
return 1; 
} 
return 0; 
} 
int main() { 
int cost[10][10], n, i, j, ne = 1, min, u, v, a, b, total = 0; 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
printf("Enter cost adjacency matrix (999 for no edge):\n"); 
for (i = 0; i < n; i++) 
for (j = 0; j < n; j++) 
scanf("%d", &cost[i][j]); 
while (ne < n) { 
min = INF; 
for (i = 0; i < n; i++) 
for (j = 0; j < n; j++) 
if (cost[i][j] < min) { 
min = cost[i][j]; 
a = u = i; 
b = v = j; 
} 
u = find(u); 
v = find(v); 
if (uni(u, v)) { 
printf("Edge %d: (%d %d) cost: %d\n", ne++, a, b, min); 
total += min; 
} 
cost[a][b] = cost[b][a] = INF; 
} 
printf("Total cost: %d\n", total); 
return 0; 
}