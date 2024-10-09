#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push(struct node *top,int n)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Heap Over Flow\n");
    else
    {
        t->data=n;
        t->next=top;
        top=t;
    }
}
void pop(struct node *top)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t=NULL)
    printf("Stack Underflow\n");
    else{
        t=top;
        top=top->next;
        int n=t->data;
        free(t);
        return n;
    }
}
void display(struct node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
       top = top->next;
    }
}
void main()
{
 struct node* top=NULL;
 top = push(top,35);
 top = push(top,45);
 top = push(top,55);
 top = ush(top,65);
 top = push(top,75);
 display(top);
 //pop(top);
 display(top);
}