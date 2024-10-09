#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
int cr(int n)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=n;
    p->left=NULL;
    p->right=NULL;
    return p;
}
//preorder=Root->Left->Right
void preorderTrivarsal(struct node* root)
{
    if(root!=NULL)
    {
    printf("%d\t",root->data);
    preorderTrivarsal(root->left);
    preorderTrivarsal(root->right);
    }
}
//Inorder=Left->Root->Right
void InorderTrivarsal(struct node* root)
{
    if(root!=NULL)
    {
    InorderTrivarsal(root->left);
    printf("%d\t",root->data);
    //postorderTrivarsal(root->left);
    InorderTrivarsal(root->right);
    }
}
//postorder=Left->Right->Root
void postorderTrivarsal(struct node* root)
{
    if(root!=NULL)
    {
    //printf("%d\t",root->data);
    postorderTrivarsal(root->left);
    postorderTrivarsal(root->right);
    printf("%d\t",root->data);
    }
}
void main()
{
    /*struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=1;
    p->left=NULL;
    p->right=NULL;
    struct node* q=(struct node*)malloc(sizeof(struct node));
    q->data=2;
    q->left=NULL;
    q->right=NULL;
    struct node* r=(struct node*)malloc(sizeof(struct node));
    r->data=3;
    r->left=NULL;
    r->right=NULL;
    p->left=q;
    p->right=r;*/
    /*         1
             /   \  
            2     3
          /  \   / \
         4    5 6   7

    */ 
    struct node* a=cr(1);
    struct node* b=cr(2);
    struct node* c=cr(3);
    struct node* d=cr(4);
    struct node* e=cr(5);
    struct node* f=cr(6);
    struct node* g=cr(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    // c->right=g;
    printf("Preorder\n");
    preorderTrivarsal(a);
    printf("\nPostorder\n");
    postorderTrivarsal(a);
    printf("\nInorder\n");
    InorderTrivarsal(a);
    return 0;
}