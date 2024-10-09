#include <stdio.h>
#include <limits.h>
int maximum(int a[],int n)
{
    int max=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(max<a[i])
        max=a[i];
    }
    return max;
}
void count(int a[],int n)
{
    int m=maximum(a,n);
    int c[m];
    int j=0;
    for(int i=0; i<=m; i++)
    {
        c[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        c[a[i]]=1;
    }
    for(int i=0; i<=m; i++)
    {
        if(c[i]>0)
        {
        a[j]=i;
        j++;
       }
    }
}
int p(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int main() {
    int a[]={8,4,5,6,3,1,2};
    int n=7;
    p(a,n);
    count(a,n);
    p(a,n);
    return 0;
}