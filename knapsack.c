//0/1knapsack
#include<stdio.h>
int profit[10];
int wt[10];
int knap(int, int);
void main()
{
    int m, n;
    printf("Enter sack size and number of objects\n");
    scanf("%d%d",&m,&n);

    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter profit and weight of the object number %d:\n",i+1);
        scanf("%d%d",&profit[i],&wt[i]);
    }
    int maxprofit=knap(m,n);
    printf("Maximum profit is %d\n",maxprofit);
}

int knap(int m, int n)
{
    int dp[n+1][m+1];
    int obj, rw;
    for(obj=0;obj<= n;obj++)
    {
        dp[obj][0]=0;
    }
    for(rw=0;rw<=m;rw++)
    {
        dp[0][rw]=0;
    }
    for(obj=1;obj<=n;obj++)
    {
        for(rw=1;rw<=m;rw++)
        {
            if(wt[obj-1]<=rw)
            {
                if(dp[obj-1][rw-wt[obj-1]]+profit[obj-1]>dp[obj-1][rw])
                {
                    dp[obj][rw]=dp[obj-1][rw-wt[obj-1]]+profit[obj-1];
                }
                else
                {
                    dp[obj][rw]=dp[obj-1][rw];
                }
            }
            else
            {
                dp[obj][rw] = dp[obj-1][rw];
            }
        }
    }
    return dp[n][m];
}