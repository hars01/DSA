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
//Checkin BST is present or not by Inorder=Left->Root->Right
int IsBST(struct node* root)
{
    static struct node* prev=NULL;
    if(root!=NULL)
    {
      if(!IsBST(root->left))
      {
        return 0;
      }
      if(prev!=NULL&&root->data<=prev->data)
      {
        return 0;
      }
      prev=root;
      return IsBST(root->right);
    }
    else
    {
        return 1;
    }
}
//Searching of Element by Recursion in BST
 struct node* search(struct node* root, int key)
{
  if(root==NULL)
  return 0;
  if(key==root->data)
  return root;
  else if(key<root->data)
  return search(root->left,key);
  else 
  return search(root->right,key);
}
//Searching of Element by Iterative in BST
 struct node* IterativeSearch(struct node* root, int key)
{
  if(root==NULL)
  return 0;
  while(root!=NULL)
  {
  if(key==root->data)
  return root;
  else if(key<root->data)
  root=root->left;
  else 
  root=root->right;
  }
  return NULL;
}
//Insertion of Element in BST
 void Insertion(struct node* root, int key)
{
  if(root==NULL)
  return 0;
  struct node* prev=(struct node*)malloc(sizeof(struct node));
  while(root!=NULL)
  {
  prev=root;
  if(key==root->data)
  return root;
  else if(key<root->data)
  root=root->left;
  else 
  root=root->right;
  }
  struct node* new=cr(key);
  if(key<prev->data)
  prev->left=new;
  else
  prev->right=new;

}
//deletion of node
struct node* deletion(struct node *root,int v)
{
  struct node *pre;
  if(root==NULL)
  return NULL;
  if(root->left==NULL && root->right==NULL) 
  {
  free(root);
  return NULL;
  }
  if(v<root->data)
  root->left=deletion(root->left,v);
  else if(v>root->data)
  root->right=deletion(root->right,v);
  else
  {
    pre=InorderPre(root);
    root->data=pre->data;
    root->left=deletion(root->left,pre->data);
  }
return root;
}
//Inorder Pre element finding;
int InorderPre(struct node* root)
{
  root=root->left;
  while(root->right!=NULL)
  {
    root=root->right;
  }
  return root->data;
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
int main()
{
    struct node* a=cr(50);
    struct node* b=cr(40);
    struct node* c=cr(60);
    struct node* d=cr(30);
    struct node* e=cr(45);
    //struct node* f=cr(55);
    struct node* g=cr(70);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
   // c->left=f;
    c->right=g;
  preorderTrivarsal(a);
  printf("\n");
   int t=IsBST(a);
   if(t==1)
    printf("It is a BST\n");
   else
    printf("It is not a BST\n");

  struct node* n=IterativeSearch(a,60);
  if(n!=NULL)
  printf("%d is Searched\n",n->data);
  else
  printf("Element is Not Found\n");
  Insertion(a,55);
  preorderTrivarsal(a);
  printf("\n%d",a->right->left->data);
  printf("\n%d",InorderPre(a));
  deletion(a,50);
  printf("\n");
  preorderTrivarsal(a);
  return 0;
}