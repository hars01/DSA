#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL;
void create(int a[],int n)
{
    struct node *temp,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
void t(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
}
struct node *loop(struct node *head)
{
    struct node *p,*q;
    do {
        p=p->next;
        q=q->next->next;
    } while(p!=q&&p!=NULL);
    if(p==q) 
    printf("true\n");
    else
   printf("false\n");
}
struct node *loop2(struct node *head)
{
    struct node *p=head;
    struct node *q=head;
    while(q!=NULL && q->next!=NULL) {
        p=p->next;
        q=q->next->next;
         if(p==q) 
         return p;
    }
   return NULL;
}
struct node *middle(struct node *head)
{
    struct node *p=head;
    struct node *q=head;
    while(q!=NULL && q->next!=NULL) {
        p=p->next;
        q=q->next->next;
    }
    return p;
}
int main() {
    int a[]={10,20,30,40,50};
    create(a,5);
    t(head);
    printf("\n");
    printf("%d",middle(head));
    return 0;
}