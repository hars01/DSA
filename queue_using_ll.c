#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int h;
    int r;
    int cap;
    int *arr;
};
struct node {
    int data;
    struct node *next;
};
struct node *f=NULL;
struct node *r=NULL;
void create(struct queue *q, int cap) {
    q->h = q->r = -1;
    q->size = 0;
    q->cap = cap;
    q->arr = (int*)malloc(q->cap * sizeof(int));
}
void enqueue(int v)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("Queue is Full \n");
    }
    else
    {
        n->data=v;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else 
        {
        r->next=n;
        r=n;
        }
    }
}
int dequeue(struct node *p)
{
    int v=-1;
    struct node *n=f;
    if(f==NULL)
    {
        printf("Stack is Empty \n");
    }
    else
    {
        f=f->next;
        v=n->data;
        free(n);
    }
    return v;
}
void Display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main() {
    Display(f);
    //printf("%d",dequeue(f));
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("deque eelement%d \n",dequeue(f));
    enqueue(40);
    Display(f);
}