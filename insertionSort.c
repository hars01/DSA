#include<stdio.h>
int p(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void insertion(int a[], int n)
{




}
int main()
{
    int a[]={8,2,5,3,7,0,9};
    int n=7;
    p(a,n);
    bubble(a,n);
    p(a,n);
}