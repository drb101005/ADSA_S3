#include <stdio.h>

#define INF 99999 // large value to represent no edge

void floydWarshall(int V, int graph[V][V]) {
    int dist[V][V], i, j, k;
    // Initialize distance matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == -1 && i != j)
                dist[i][j] = INF; // no edge
            else
                dist[i][j] = graph[i][j];
        }
    }
    // Main algorithm
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    // Print result
    printf("\nShortest distance matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter adjacency matrix (use -1 if no edge):\n");
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    floydWarshall(V, graph);
    return 0;
}