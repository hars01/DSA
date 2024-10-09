#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int tap;
    int *arr;
};
int isEmpty(struct stack *p)
{
    if(p->tap==-1)
    return 1;
    else
    return 0;
}
int isFull(struct stack *p)
{
    if(p->tap==p->size-1)
    return 1;
    else
    return 0;
}
int push(struct stack * p,int val) {
    if(isFull(p))
    {
        printf("Stack Over Flow So we could not push %d in stack \n",val);
    }
    else {
        p->tap++;
        p->arr[p->tap]=val;
    }
}
int pop(struct stack * p) {
    if(isEmpty(p))
    {
        printf("Stack is Empty \n");
    }
    else {
       int val=p->arr[p->tap];
        p->tap--;
        return val;
    }
}
void display(struct stack *st)
{
    for(int i=st->tap; i>=0; i--)
    printf("%d\t",st->arr[i]);
}
void main(){
    //struct stack s;
    //s.size=80;
    //s.tap=-1;
    //s.arr=(int*)malloc(s.size*sizeof(int));
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size=5;
    s->tap=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    // s->arr[s->tap]=10;
    //s->tap++;
    //printf("%d\n",isFull(s));
    //printf("%d\n",isEmpty(s));
    //push(s,59);
    //push(s,56);
    //push(s,57);
    //push(s,56);
    //push(s,56);
    //display(s);
    //push(s,06);
    //printf("\n%d\n",isFull(s));
    //printf("\n%d\n",isEmpty(s));
    //printf("Popped %d from stack\n",pop(s));
    
    push(s,10);
    push(s,20);
    push(s,30);
    display(s);
    pop(s);
    //pop(s);
    printf("\n%d\n",pop(s));
    printf("%d\n",s->size);
    push(s,40);
    push(s,50);
    push(s,60);
    display(s);
    pop(s);
    pop(s);
    printf("\n%d\n",pop(s));
    display(s);
    
}
