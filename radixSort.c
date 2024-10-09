#include<stdio.h>
#include<limits.h>
int maximum(int a[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
      if(max<a[i])
      {
        max=a[i];
      }
    }
    return max;
}
void countSort(int a[],int n, int pos)
{
    int count[10]={0};
    int b[n];
    for(int i=0; i<n; i++)
    ++count[(a[i]/pos)%10];
    for(int i=1; i<10; i++)
    count[i]=count[i]+count[i-1];
    for(int i=n-1;i>=0;i--)
    b[--count[(a[i]/pos)%10]]=a[i];
    for(int i=0;i<n;i++)
    a[i]=b[i];
}
void radixSort(int a[],int n)
{
    int max=maximum(a,n);
    for(int pos=1;max/pos>0;pos=pos*10)
    {
        countSort(a,n,pos);
    }
}
int p(int a[],int n)
{
    for(int i=0; i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[]={10,2,48,35,101,200,400,677,988,11,15};
    int n=11;
    p(a,n);
    radixSort(a,n);
    p(a,n);
    return 0;

}