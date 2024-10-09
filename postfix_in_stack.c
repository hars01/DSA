#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
  int size;
  int top;
  int *arr;
};
void create(struct stack*s){
  //s = (struct stack*)malloc(sizeof(struct stack));
  printf("Enter size of stack: ");
  scanf("%d",&s->size);
  s->top=-1;
  s->arr = (int *)malloc(s->size*sizeof(int));
}
void push(struct stack*s, char key){
  if(s->top==s->size-1){
    printf("Stack overflow");
  }
  else{
    s->top++;
    s->arr[s->top]=key;
  }
}

int pop(struct stack*s){
  char x;
  if(s->top==-1){
  x=-1;
  }
  else
  {
    x=s->arr[s->top];
    s->top--;
  }
  return x;
}

int is_operator(char a){
  if(a=='+'||a=='-'||a=='*'||a=='/'){
    return 1;
  }
  return 0;
}

int precedence(char a){
  if(a=='*'||a=='/'){
    return 2;
  }
  else
  return 1;
}

int is_empty(struct stack*s){
  if(s->top==-1){
    return 1;
  }
  else
  return 0;
}

void postfix(char*exp){
   struct stack s;
   create(&s);
  int len = strlen(exp);
  //printf("String length: %d",len);
  char output[len];
  int i=0,j=0;
  while(exp[i]!='\0' && j<=len){
    if(is_operator(exp[i])){
      if(is_empty(&s)){
        push(&s,exp[i++]);
      }
      else {
        if((precedence(exp[i]))>(precedence(s.arr[s.top]))){
        push(&s,exp[i++]);
      }
        else{
        while(s.top!=-1){
        output[j++]=pop(&s);
      }
    }
    }
  }
      else{
        output[j++]=exp[i++];
      }
    }
    while(s.top!=-1){
    output[j++]=pop(&s);
  }
    for(i=0;i<len;i++){
      printf("%c",output[i]);
    }
//printf("string length: %d",strlen(output));
  }

  void main(){
    char exp[]="a+b*c-d/e";

    postfix(exp);
  }