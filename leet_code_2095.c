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
void deletemid(struct node *head)
{
    struct node *p=head;
    struct node *q=head;
    int a=count(head);
    a=a/2;


}
int count(struct node *head)
{
    struct node *p=head;
    int c=0;
    if(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}
void t(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
}
int main()
{
  int a[]={10,20,30,40,50};
  create(a,5);
  printf("%d\n",count(head));
  t(head);
}