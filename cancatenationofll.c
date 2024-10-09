#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL,*head2=NULL;
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
    head2=(struct node *)malloc(sizeof(struct node));
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
struct node* concatenation(struct node * p)
{
    while(p!=NULL)
    {
        p=p->next;
    }
    p->next=head2;
    head2=NULL;
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