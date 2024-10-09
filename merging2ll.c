#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL,*second=NULL;
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
void createtwo(int a[],int n)
{
    struct node *temp,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
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
struct node* merge(struct node * p, struct node * q )
{
    //*head=NULL;
    //*second=NULL;
    if(p->data<=q->data)
    {
        head=second=p;
        p=p->next;
        second->next=NULL;
    }
    else 
    {
        head=second=q;
        q=q->next;
        second->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data <= q->data)
        {
            second->next=p;
            second=p;
            p=p->next;
            second->next=NULL;
        }
        else
        {
           second->next=q;
            second=q;
            q=q->next;
            second->next=NULL;
        }
    }
    if(p==NULL)
    second->next=q;
    else
    second->next=p;
    return head;
}
struct node *loop(struct node *head)
{
    struct node *p,*q;
    do {
        p=p->next;
        q=q->next->next;
    } while(p!=q&&p!=NULL);
    if(p==q) 
    return 1;
    else
    return 0;
}

int main() {
    int a[]={10,20,30,40,50};
    int a2[]={60,70,80,90,100};
    create(a,5);
    t(head);
    printf("\n");
    createtwo(a2,5);
    t(head);
    printf("\n");
    head=concatenation(head);
    t(head);
    return 0;
}