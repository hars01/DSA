#include<stdio.h>
void v(int a[],int n,int k)
{
  int p=n-k;
  int b[n];
  int j=0;
  for(int i=p-1; i<=n; i++)
  {
     b[j]=a[i];
     j++;
  }
  for(int i=0; i<p-1; i++)
  {
     b[j]=a[i];
     j++;
  }
  for(int i=0; i<=n; i++)
  {
    printf("%d\t",b[i]);
  }
}
int findArray(int pref[], int prefSize, int* returnSize) {
    int arr[prefSize];
    for(int i=0; i<prefSize; i++)
    {
        arr[i]=pref[i]^pref[i-1];
    }
    return arr;
}
int p(int *a, int n)
{
  for(int i=0; i<=n; i++)
  {
    printf("%d \t",a[i]);
  }
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=5;
    p(a,n);
    printf("\n");
    v(a,n,3);
    findArray(a,n,5);
    p(a,n);
}