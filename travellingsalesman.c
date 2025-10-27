#include <stdio.h>  
#define INF 9999  
int n;  
int cost[20][20];  
int visited[20];  
int tsp(int city, int count, int dist)  
{  
if (count == n && cost[city][0])  
{  
return dist + cost[city][0];  
}  
int ans = INF;  
for (int i = 0; i < n; i++)  
{  
if (!visited[i] && cost[city][i])  
{  
visited[i] = 1;  
int newAns = tsp(i, count + 1, dist + cost[city][i]);  
if (newAns < ans) ans = newAns;  
visited[i] = 0;  
}}  
return ans;  
}  
int main()  
{  
printf("Enter number of cities: ");  
scanf("%d", &n);  
printf("Enter cost matrix (use 0 if no path):\n");  
for (int i = 0; i < n; i++)  
{  
for (int j = 0; j < n; j++)  
{  
scanf("%d", &cost[i][j]);  
}  
}  
for (int i = 0; i < n; i++) visited[i] = 0;  
visited[0] = 1;  
int ans = tsp(0, 1, 0);  
printf("Minimum cost of travelling salesman tour = %d\n", ans);  
return 0;  
}