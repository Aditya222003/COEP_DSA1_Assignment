#include<stdio.h>
#include "stack.h"
#include<stdlib.h>
#include<string.h>

void initStack(Stack* s,int size){
     s -> arr = (char*)malloc(sizeof(char)*size);
     s -> top = -1;
     s -> size = size;
     return ;
}

int isFull(Stack s){
    return s.top >=  s.size - 1;
}

void push(Stack *s,char data){
  
  if(isFull(*s)){
        return;
  }
   s -> top++;
   s -> arr[s -> top] = data;
   return ;
}

void display(Stack s){

    if(s.top == -1 )
    return ;
    printf("\n");
    for(int i = s.size ; i >= 0 ; i--){
    printf("%c ",s.arr[i]);
    }

}
int isEmpty(Stack s){
    return s.top == -1;
}
void insertIntoStack(Stack* s,char* data)
{
    
    for(int i = 0 ; i < data[i] != '\0'; i++){
         if(i >= s -> size)
             return ;

        push(s,data[i]);
    }
    return ;
}
int pop(Stack *s){
    if(isEmpty(*s))
    return 0;

    int element = s -> arr[s->top];
    s -> top--;
    return element;
}

void reverse(Stack *s){
    Stack s1;
    initStack(&s1,s -> size);
        printf("Top %d",s -> top);
    
    for(int i = (*s).top  ; i >= 0 ; i--  )
    {
        printf("\n%c",(*s).arr[i]);
        push(&s1,s -> arr[i]);
    }
    *s = s1;
}
int checkPalindrome(Stack s1 ,Stack s2){
    if(s1.size != s2.size)
    return 0;
    display(s1);
    display(s2);
    for(int i = 0; i <= s1.size && s1.arr[i] != '\0'; i++){
        if(s1.arr[i] != s2.arr[i])
        return 0;
    }
    return 1;
}
