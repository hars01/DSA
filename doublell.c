#include <stdio.h>
#include<stdlib.h>
struct n{
    struct n*prev;
    int x;
    struct n*nex;
}*f=NULL;
void creat(int a[],int n)
{
    struct n *t,*l;
    f=(struct n*)malloc(sizeof(struct n ));
    f->x=a[0];
    f->nex=NULL;
    f->prev=NULL;
    l=f;
    for(int i=1;i<n;i++) {
    t=(struct n*)malloc(sizeof(struct n ));
     t->x=a[i];
    t->nex=NULL;
    t->prev = l;
    l->nex = t;
    l=t;
    }
}
void display(struct n*temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->x);
        temp=temp->nex;
    }
}
void insertfirst(struct n*h,int y)
{
    struct n*t;
    t=(struct n*)malloc(sizeof(struct n));
    t->x=y;
    t->prev=NULL;
    t->nex=h;
    h->prev=t;
    h=t;
}
int main() {
    int a[]={10,20,30,40,50};
    creat(a,5);
    display(f);

    return 0;
}