//floyd warshall
#include<stdio.h>
#include<limits.h>
int main()
{
    int n;
    printf("enter number of vertices: ");
    scanf("%d",&n);
    int dist[10][10];
    int i,j;
    printf("enter the adjacency matrix(use 999 for no edge): \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&dist[i][j]);
        }
    }
    int k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }    
        }
    }
    printf("shortest distance matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}