#include<stdio.h>
int merging(int A[],int B[],int m,int n)
{
    int C[16];
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
    if(A[i]<B[j])
        C[k++]=A[i++];
    else
        C[k++]=B[j++];
    }
     while(i<n)
     C[k++]=A[i++];
     while(j<m)
     C[k++]=B[j++];
    for(int l=0; l<=(m+n+1);l++)
    {
        printf("%d\t",C[l]);
    }
}
void mergingonearray(int A[],int l,int m,int h)
{
    int C[h];
    int i=l,j=m+1,k=l;
    while(i<m && j<h)
    {
    if(A[i]<A[j])
        C[k++]=A[i++];
    else
        C[k++]=A[j++];
    }
     while(i<=m)
     C[k++]=A[i++];
     while(j<h)
     C[k++]=A[j++];
   // for(int l=0; l<h;l++)
    //{
      //  printf("%d\t",C[l]);
    //}
    return C;
}
int mergeSort(int a[],int l,int h)
{
    while(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        mergingonearray(a,l,mid,h);
    }
    return a;
}
int p(int a[],int n)
{
    for(int l=0; l<n;l++)
    {         
      printf("%d\t",a[l]);
    }
}
int main()
{
    int a[]={10,40,50,60,80,80};
    int b[]={12,24,39,43,51,62,74,90,94};
    int n=6,m=9;
    int d[]={2,3,4,5,1,6,7,8};
    int l=0,h=8,mid=(l+h/2);
    mergingonearray(d,l,mid,h);
    p(d,h);
    //printf("\n");
    //merging(a,b,m,n);
    //printf("\n");
    //value(a,b,m,n);
}