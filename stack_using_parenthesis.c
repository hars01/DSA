#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int tap;
    char *s;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->tap == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->tap == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* st, char n)
{
    if(st->tap==st->size-1) {
    printf("Stack Over Flow\n");
    }
    else{
        st->tap++;
        st->s[st->tap]=n;
    }
}
char pop(struct stack *st)
{
    if(st->tap==-1) {
    printf("Stack is Under Flow");
    return -1;
    }
    else{
        char n=st->s[st->tap];
        st->tap--;
        return n;
    }
}
void display(struct stack *st)
{
    for(int i=st->tap; i>=0; i--)
    printf("%d\t",st->s[i]);
}
int sol(char * s)
{
 struct stack* st;
 st->size=100;
 st->tap=-1;
 st->s=(char *)malloc(st->size * sizeof(char));
    for(int i=0; s[i]!='\0'; i++) 
    {
       if(s[i]=='(') {
       push(st,'(');
       }
       else if(s[i]=')') {
        if(isEmpty(st))
        return 0;
        else
        pop(st);
       }
    }
   if(isEmpty(st))
   return 1;
   else
   return 0;
}
int main()
{
    char * s="((a+b)*(c+d)))";
    if(sol(s))
    printf("Parenthesis Matching\n");
    else
    printf("Parenthesis is not matching\n");
    return 0;
}