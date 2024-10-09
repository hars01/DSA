#include<stdio.h>
#include<stdlib.h>
struct stack {
    int top;
    int size;
    char *s;
};
void prec(char x)
{
    if(x=='+'||x=='-')
    return -1;
    else if(x=='*'||x=='/')
    return 2;
    else 
    return 0;
} 
void  ifoper(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else
    return 1;
}
char * intopost(char *infix)
{
    struct stack *st;
    st->top=-1;
    st->size=100;
    st->s=(char *)malloc(st->size*sizeof(char));
    int i=0;
    int j=0;
    int len=strlen(infix);
    char*postfix=(char*)malloc(len*sizeof(char));
    while(infix[i]!='/0')
    {
        if(isoper(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
          if (precd(infix[i])>precd(top(st)))
          {
             push(st,infix[i]);
          }
          else
          {
            pop(st);
            postfix[j++]=pop(st);
          }
          
        }
    }
    while(!isempty(st))
    {
       postfix[j++]=pop(st);
    }
    postfix[j]='\0';
    return postfix;
    
}