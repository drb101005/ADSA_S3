#include<stdio.h>

int a[100];

void mergesort(int l,int r);
void conquer(int l,int mid,int r);

void main()
{
    int n , j,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("Enter the no: \n");
        scanf("%d",&a[i]);
    }

    mergesort(0,n-1);

    printf("sorted array is:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d ",a[i]);
    }
}

void mergesort(int l , int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(l,mid);          
        mergesort(mid+1, r);
        conquer(l,mid,r);         
    }
}

void conquer(int l,int mid,int r)
{
    int w[100];                    
    int h=0;
    int i=l;
    int j=mid+1;

    while(i<=mid && j<=r)
    {
        if(a[i] < a[j])           
        {
            w[h]=a[i];
            i++;
        }
        else
        {
            w[h]=a[j];
            j++;
        }
        h++;
    }

    while(i<=mid)                  
    {
        w[h]=a[i];
        i++;
        h++;
    }

    while(j<=r)
    {
        w[h]=a[j];
        j++;
        h++;
    }

    
    int k;
    for(k=0; k<h; k++)
    {
        a[l+k]=w[k];
    }
}