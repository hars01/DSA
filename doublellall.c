#include <stdio.h>
#include<stdlib.h>
struct d{
    struct d*p;
    int x;
    struct d*n;
}*f=NULL;
void c(int a[],int n)
{
    struct d*t,*l;
    f=(struct d*)malloc(sizeof(struct d));
    f->x=a[0];
    f->p=NULL;
    f->n=NULL;
    l=f;
    for(int i=1;i<n;i++) {
    t=(struct d*)malloc(sizeof(struct d));
    t->x=a[i];
    t->n=NULL;
    t->p=l;
    l->n=t;
    l=t;
    }
}
int display(struct d*p)
{
    while(p->n!=NULL)
    {
        printf("%d\t",p->x);
        p=p->n;
    }
}
void insertfirst(struct d*h,int y)
{
    struct d*t;
    t=(struct d*)malloc(sizeof(struct d));
    t->x=y;
    t->p=NULL;
    t->n=h;
    h->p=t;
    h=t;
}
void insertend(struct d*h,int y)
{
    struct d*t;
    t=(struct d*)malloc(sizeof(struct d));
    t->x=y;
    t->n=NULL;
    if(h==NULL)
    h=t;
    while(t->p!=NULL)
    h=h->n;
    t->p=h;
    h->n=t;
}
void insertgiven(struct d*h,int pos,int x)
{
    struct d*t;
    for(int i=0; i<pos-1;i++)
    {
        t=(struct d*)malloc(sizeof(struct d));
        t->n=h->n;
        h->n->p=t;
        h->n=t;
        t->p=h;
    }
    
}
int main() {
    int a[]={10,20,30,40,50};
    c(a,6);
     display(f);
    //insertgiven(f,3,60);

    //insertfirst(f,90);
    insertend(f,60);
    printf("\n");
    display(f);

    return 0;
}