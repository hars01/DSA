#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int tap;
    int *arr;
};
void create(struct stack *st)
{
    st=(struct stack *)malloc(sizeof(struct stack));
    scanf("%d",st->size);
    st->tap=-1;
    st->arr=(int*)malloc(st->size*sizeof(int));
    st=(struct stack *)malloc(sizeof(struct stack));
}
void push(struct stack * st,int n)
{
    if(st->tap==st->size-1)
    printf("Stack Over Flow\n");
    else{
        st->tap++;
        st->arr[st->tap]=n;
    }
}
int pop(struct stack *st)
{
    if(st->tap==-1)
    printf("Stack is Under Flow");
    else{
        int n=st->arr[st->tap];
        st->tap--;
        return n;
    }
}
void display(struct stack *st)
{
    for(int i=st->tap; i>=0; i--)
    printf("%d\t",st->arr[i]);
}
int main(){
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    display(&st);
    pop(&st);
    printf("\n%d\n",pop(&st));
    printf("\n%d\n",st.size);
    push(&st,40);
    push(&st,50);
    push(&st,60);
    display(&st);
    pop(&st);
    pop(&st);
    printf("\n%d\n",pop(&st));
    display(&st);
}
