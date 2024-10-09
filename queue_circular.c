#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int cap;
    int *arr;
};
void create (struct queue *q,int cap)
{
    q->f=q->r=-1;
    q->size=0;
    q->cap=cap;
    q->arr=(int*)malloc(q->cap*sizeof(int));
}
void eneque(struct queue *q, int val)
{
    if(((q->r+1)%q->cap)==q->f)
    printf("Queue is over flow\n");
    else
    {
        q->r=(q->r+1)%q->cap;
        q->arr[q->r]=val;
        
    }
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(q->f==q->r)
    return a;
    else {
        //a=q->arr[q->f];
        q->f=(q->f+1)%q->cap;
         a=q->arr[q->f];
    }
    return a;
}
int display(struct queue *q)
{
    int l=q->f+1;
    int i=(l+1)% q->cap;
    while(i!=(q->r+1)%q->cap)
    {
    printf("Element : %d\n",q->arr[i]);
    i = (i + 1) % q->cap;
    }
}
 int main()
{
struct queue *q = (struct queue *)malloc(sizeof(struct queue));
create(q,6);
eneque(q,10);
eneque(q,20);
//dequeue(q);
//dequeue(q);
eneque(q,30);
eneque(q,40);
//dequeue(q);
//dequeue(q);
eneque(q,50);
eneque(q,60);
display(q);

}