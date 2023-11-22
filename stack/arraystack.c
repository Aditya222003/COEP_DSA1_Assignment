#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data ;
    struct node* next ;
}node ;

typedef struct Stack
{
    node* top ;
}Stack;

initStack( Stack *s )
{
    s -> top = NULL ;
    return ;
}
int isEmpty( Stack s )
{
    return s.top == NULL ;
}
void push( Stack *s , int key )
{
    node* newnode = (int*)malloc(sizeof (int) );
    newnode -> data = key ;
    newnode -> next = NULL ;
    if(isEmpty(*s))
    {
        s->top = newnode ;
        return ; 
    }
    newnode -> next = s -> top  ;
    s->top = newnode ;
    return ;
}
int pop(Stack *s )
{
    node* temp = s->top ;
    int element = temp -> data ;
    s->top = s -> top -> next ;
    free( temp );
    return element ;
}
display( Stack s )
{
    node* temp = s.top ;
    printf("\n");
    while( temp )
    {
        printf("  %d  <- ", temp -> data );
        temp = temp -> next ;
    }
    printf("\n");
}
void main()
{
    Stack s1 ;
    initStack( &s1 );
    push( &s1 , 10);
    push( &s1 , 20);
    push( &s1 , 30);
    push( &s1 , 40);
    push( &s1 , 50);
    display( s1);   
}