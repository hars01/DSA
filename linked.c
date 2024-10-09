#include <stdio.h>
struct node{
    int data;
    struct node*next;
};
void t(struct node*ptr)
{
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
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
    head->data=71;
    head->next=second;
        second->data=17;
        second->next=third;
            third->data=55;
            third->next=fourth;
                fourth->data=72;
                fourth->next=NULL;
    t(head);
    return 0;
}