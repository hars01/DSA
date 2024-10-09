#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
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
void t(struct node * p)
{
    while(p!=NULL)
    {
        printf("%d \t",p->data);
        p=p->next;
    }
}

int main() {
    struct node*head;
        struct node*second;
            struct node*third;
                struct node*fourth;
    head=(struct node*)malloc(sizeof(struct node));
        second=(struct node*)malloc(sizeof(struct node));
            third=(struct node*)malloc(sizeof(struct node));
                fourth=(struct node*)malloc(sizeof(struct node));
    head->data=5;
    head->next=second;
        second->data=6;
        second->next=third;
            third->data=7;
            third->next=fourth;
                fourth->data=8;
                fourth->next=NULL;
    t(head);
    head=dv(head,6);
    printf("\n");
    t(head);
    return 0;
}