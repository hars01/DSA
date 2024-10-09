#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
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
        top=t;
        t=t->next;
        free(top);
    }
}
int peek(struct node *stack)
{
    if(stack==NULL)
    printf("Stack Is Underflow\n");
   // struct node *t=stack->top;
   // int p=t->data;
   // stack->top=t->next;
    //free(t);
   // return p;
}
void display(struct node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
       top = top->next;
    }
    printf("\n");
}
void main()
{
 struct node *top;
 push(top,35);
 push(top,45);
 push(top,55);
 push(top,65);
 push(top,75);
 display(top);
 pop(top);
 display(top);
}