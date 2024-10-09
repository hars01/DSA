#include<stdio.h>
int p(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void bubble(int a[], int n) {
    int issorted=0;
    for(int i=0; i<n-1; i++)
    {
        printf("Number of Passes %d\n",i+1);
        issorted=1;
        for(int j=0; j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                issorted=0;
            }
        }
    }
    if(issorted)
    {
        return;
    }
}
int main()
{
    int a[]={8,2,5,3,7,0,9};
    int n=7;
    p(a,n);
    bubble(a,n);
    p(a,n);
}