#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q )
{
   if(q->r==q->size-1){
     return 1;
   }
   return 0;
}
int isEmpty(struct queue *q )
{
   if(q->r==q->f)
     return 1;
   return 0;
}
void enqueue(struct queue *q,int v)
{
    if(isFull(q)){
    printf("This Queue is FULL\n");
    }
    else {
        q->r++;
        q->arr[q->r]=v;
    }
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    printf("This Queue is Empty\n");
    else {
         q->f++;
        a=q ->arr[q->f];
        //q->f++;
    }
    return a;
}
int display(struct queue *q)
{
for(int i=0; i<q->size;i++)
{
    printf("Element : %d\n",q->arr[i]);
}
}
int main()
{
    struct queue q;
    q.size=10;
    q.f= q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
    printf("dequeue element %d \n",dequeue(&q));
    printf("dequeue element %d \n",dequeue(&q));
    display(&q);
    if(isEmpty(&q)) {
      printf("Queue is Empty\n");
    }
    if(isFull(&q)) {
      printf("Queue is Full\n");
    }
    return 0;
}
    
    
    
    
    
    
    
   

