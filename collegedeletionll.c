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
//Case 1:Deletion in the first
int df(struct node * head)
{
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//Case 2:Deletion at any given index
int db(struct node *head,int x)
{
    struct node * p=head;
    struct node * q=head->next;
    for(int i=0;i<x-1;i++){
          p=p->next;
          q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
//Case 3:Deletion at any last index
int dl(struct node *head)
{
    struct node * p=head;
    struct node * q=p->next;
    while(q->next != NULL){
          p=p->next;
          q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//Case 2:Deletion at any given index
int dv(struct node *head,int x)
{
    struct node * p=head;
    struct node * q=head->next;
    while(q->data!=x && q->next!=NULL){
          p=p->next;
          q=q->next;
    }
    if(q->data==x){
    p->next=q->next;
    free(q);
    }
    return head;
}
void t(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
}

int main() {
    int a[]={10,20,30,40,50};
    creat(a,5);
    display(head);

    return 0;
}
