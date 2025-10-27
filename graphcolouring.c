#include <stdio.h> 
#define MAX 10 
int V; 
int graph[MAX][MAX]; 
int color[MAX]; 
int isSafe(int v, int c) { 
for (int i = 0; i < V; i++) { 
if (graph[v][i] && color[i] == c) 
return 0; 
} 
return 1; 
} 
int graphColoring(int v, int m) { 
if (v == V) 
return 1; 
for (int c = 1; c <= m; c++) { 
if (isSafe(v, c)) { 
color[v] = c; 
if (graphColoring(v + 1, m)) 
return 1; 
color[v] = 0; 
} 
} 
return 0; 
} 
int main() { 
int m; 
printf("Enter number of vertices: "); 
scanf("%d", &V); 
printf("Enter adjacency matrix (%d x %d):\n", V, V); 
for (int i = 0; i < V; i++) { 
for (int j = 0; j < V; j++) { 
scanf("%d", &graph[i][j]); 
} 
} 
printf("Enter number of colors: "); 
scanf("%d", &m); 
for (int i = 0; i < V; i++) 
color[i] = 0; 
if (graphColoring(0, m)) { 
printf("\nColor assignment:\n"); 
for (int i = 0; i < V; i++) 
printf("Vertex %d ---> Color %d\n", i, color[i]); 
} else { 
printf("\nSolution does not exist with %d colors.\n", m); 
} 
return 0; 
}