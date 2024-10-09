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
struct node* merge(struct node *p, struct node *q) {
    struct node *result = NULL, *last = NULL;

    if (p == NULL) 
    return q;
    if (q == NULL)
    return p;

    if (p->data <= q->data) {
        result = last = p;
        p = p->next;
    } else {
        result = last = q;
        q = q->next;
    }

    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            last->next = p;
            last = p;
            p = p->next;
        } else {
            last->next = q;
            last = q;
            q = q->next;
        }
    }
    if(p==NULL)
    last->next=q;
    else
    result->next=p;
    return head;
}
int main() {
    int a[]={10,30,50,70,90};
    int a2[]={20,40,60,80,100};
    create(a,5);
    t(head);
    printf("\n");
    createtwo(a2,5);
    t(second);
    printf("\n");
    head=merge(head,second);
    t(head);
    return 0;
}