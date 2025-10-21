#include <stdio.h>
#include <stdlib.h>
void s(int*a,int l,int r){if(l>=r)return;
    int m=(l+r)/2,n1=m-l+1,n2=r-m,i=0,j=0,k=l;
    int*L=malloc(n1*4),*R=malloc(n2*4);s(a,l,m);
    s(a,m+1,r);for(;i<n1;i++)L[i]=a[l+i];for(i=0;i<n2;i++)R[i]=a[m+1+i];
    i=0;while(i<n1&&j<n2)a[k++]=(L[i]<=R[j])?L[i++]:R[j++];while(i<n1)a[k++]=L[i++];while(j<n2)a[k++]=R[j++];
    free(L);free(R);}
int main(){int a[]={9,4,8,1,7,0,3,2,5,6},n=10,i; s(a,0,n-1); for(i=0;i<n;i++)printf("%d ",a[i]);}