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
void reverse(struct node *nrxt)
{
    struct node *p,*q,*r;
    p=head;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head=p;
    //return head;
}
void reverserec(struct node *p,struct node *q)
{
    if(p->next != NULL)
    {
        reverserec(p,p->next);
        p->next=q;
    }
    head=q;
}
int main() 
{
    int a[]={10,20,30,40,50};
    create(a,5);
    t(head);
    reverse(head);
    printf("\n");
    t(head);
    return 0;
}