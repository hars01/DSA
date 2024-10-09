#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int x;
    struct node*nex;
}*first=NULL;
void create(int a[],int n)
{
    struct node*t,*l;
    first=(struct node*)malloc(sizeof(struct node));
    first->x=a[0];
    first->prev=NULL;
    first->nex=NULL;
    l=first;
    for(int i=1;i<n;i++) {
    t=(struct node*)malloc(sizeof(struct node));
    t->x=a[i];
    t->nex=NULL;
    t->prev=l;
    l->nex=t;
    l=t;
    }
}
void display(struct node*p)
{
    while(p->nex!=NULL)
    {
        printf("%d\t",p->x);
        p=p->nex;
    }
}
int main() {
    int a[]={2,3,4,5,6};
    int n=6;
    create(a,n);
    display(first);
}

