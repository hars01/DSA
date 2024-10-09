#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
}*head=NULL,*second=NULL;
//create function start
//create first linked list
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
//create second list
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
//end of create function
//Deletion Portion
//Case 1:Deletion in the first
struct node * df(struct node * head)
{
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//Case 2:Deletion at any given index
struct node * db(struct node *head,int x)
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
 struct node * dl(struct node *head)
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
//Case 4:Deletion at any given value store in index
struct node * dv(struct node *head,int x)
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
//end of deletion function
//Reversing Linked List
//struct node reverseList(struct node* head)
void reverseList(struct node* head) {
     struct node *p=head;
     struct node *q=NULL;
     struct node *r=NULL;
     while(p!=NULL){
         r=p->next;
         p->next=q;
         q=p;
         p=r;
     }
     head=q;
     return head;
}
//end of reverse function
// Merging Linked list
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
//end of merging function
//Printing Linked List
void t(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
}
//end of print function
//Delete Middle Linked List
struct node* deleteMiddle(struct node* head) {
   struct node* p=head;
   if(p->next==NULL)
   return NULL;
   int c=0;
   while(p!=NULL)
   {
       p=p->next;
       c++;
   }
   c=c/2;
   p=head;
   for(int i=0; i<c-1; i++)
   {
     p = p->next;
   }
   p->next=p->next->next;
   return head;
}
//end of Middle Linked List function
// count function
int count(struct node *head)
{
    int c=0;
    while(head!=NULL)
    {
        head=head->next;
        c++;
    }
    return c;
}
//end of count function
//start of main function
int main() {
    int a[]={4,5,6,7,8,9,10};
    int n=7;
    create(a,n);
    t(head);
    printf("\n");
    printf("%d\n",count(head));
    head=dv(head,6);
    //printf("\n");
    t(head);
    printf("\n");
    printf("%d\n",count(head));
    return 0;
}
//end of main function