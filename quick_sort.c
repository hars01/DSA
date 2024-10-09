#include<stdio.h>
void p(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d \t",A[i]);
    }
    printf("\n");
}
int partition(int a[],int l,int h)
{
    int temp,p=a[l],i=l+1,j=h;
    do{
        while(a[i]<=p)
        {
            i++;
        }
        while(a[j]>p)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}
void quick(int a[],int l,int h)
{
    int index;
    if(l<h)
    {
       index=partition(a,l,h);
       p(a,h);
       quick(a,l,index-1);
       quick(a,index+1,h);
    }
}
int main(){
    int a[]={1,7,9,3,5,2,0,4,6,8};
    int n=10;
    p(a,n);
    quick(a,0,n);
    p(a,n);
    return 0;
}