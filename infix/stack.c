/*
				NAME :: RAUL ADITYA 
				MIS  :: 142203016
				
					ASSIGNMENT 8
				==================
*/



#include<stdio.h>
#include"stack.h"
#include<stdlib.h>
#include<string.h>

void initStack(Stack* s,int size)
{
     s -> arr = (char*)malloc(sizeof(char)*size);
     s -> t = -1;
     s -> size = size;
     return ;
}

int isFull(Stack s)
{
    return s.t >=  s.size - 1;
}

void push(Stack *s,char data)
{
  
  if(isFull(*s))
  {
        return;
  }
   s -> t++;
   s -> arr[s -> t] = data;
   return ;
}


int isEmpty(Stack s)
{
    return s.t == -1;
}
void insert(Stack* s,char* data)
{
    
    for(int i = 0 ; i < data[i] != '\0'; i++)
    {
         if(i >= s -> size)
             return ;

        push(s,data[i]);
    }
    return ;
}
int pop(Stack *s)
{
    if(isEmpty(*s))
    return 0;

    int element = s -> arr[s->t];
    s -> t--;
    return element;
}


int palindrome(Stack s1 ,Stack s2)
{
    if(s1.size != s2.size)
    return 0;
    display(s1);
    display(s2);
    for(int i = 0; i <= s1.size && s1.arr[i] != '\0'; i++)
    {
        if(s1.arr[i] != s2.arr[i])
        return 0;
    }
    return 1;
}

void reverse(Stack *s)
{
    Stack s1;
    initStack(&s1,s -> size);
        printf("Top %d",s -> t);
    
    for(int i = (*s).t  ; i >= 0 ; i--  )
    {
        printf("\n%c",(*s).arr[i]);
        push(&s1,s -> arr[i]);
    }
    *s = s1;
}


void display(Stack s){

    if(s.t == -1 )
    return ;
    printf("\n");
    for(int i = s.size ; i >= 0 ; i--)
    {
    printf("%c ",s.arr[i]);
    }
}