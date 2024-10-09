#include<stdio.h>
int print(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}