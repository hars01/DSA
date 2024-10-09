#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head=NULL;
struct ht
{
    int n;
    struct node** t;
};
int hash(int x)
{
    return x%10;
}
int print(int a[],int n)
{
    for(int i=0; i<n; i++)
    printf("%d\t",a[i]);
    printf("\n");
}
int main()
{
    int a[]={30,22,44,79,56,43,11,15};
    int n=9;
    int *ht[10];
    for(int i=0; i<10; i++)
    {
        ht[i]=NULL;
    }
    print(a,n);
    for(int i=0; i<n; i++)
    {
        ht[hash(a[i])]=a[i];
    }
    print(ht,10);
}