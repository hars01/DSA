#include<stdio.h>
int f(int a[],int n)
{
    int d=a[0];
    for(int i=1; i<n; i++)
    {
       if(a[1]-i!=0)
       {
        while(d<a[i]-i)
        {
          printf("%d\t",d+i);
          d++;
        }
       }
    }
    
}
int main()
{
    int a[]={1,2,3,5,6,7,8};
    int n=7;
    f(a,n);
}