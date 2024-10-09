#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};

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
    head=insertafternode(head,second,9);
    t(head);
    return 0;
}