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
}Stack ;

void initstack( Stack *s )
{
    s -> top = NULL ;
    return ;
}
int isEmpty( Stack s)
{
    return s.top == NULL ;
}

void push( Stack *s , int key )
{
    node* newnode = (node*) malloc ( sizeof(node));
    newnode -> next = NULL ;
    newnode -> data = key ;

    if( isEmpty(*s) )
    {
        s -> top = newnode ;
        return ;
    }
    newnode -> next = s -> top ;
    s -> top = newnode ;
    return ;
}
void display(Stack s )
{
    node* temp = s.top ;
    printf("\n");
    while(temp)
    {
        printf("  %d ->",temp -> data );
        temp = temp -> next ;
    }
    printf("\n");
}
int pop( Stack *s )
{
    node* temp = s->top ;
    int element = temp -> data ;
    s->top =  s->top-> next ;
    free(temp);
    return element ;
}
int peek( Stack s )
{
    return s.top->data ;
}
void main()
{
    Stack s ;
    initstack(&s);
    push(&s , 10 );
    push(&s , 20 );
    push(&s , 30 );
    push(&s , 40 );
    push(&s , 50 );
    display(s);
    printf(" pop = %d ", pop(&s));
    display(s);
    printf("peek element = %d",peek(s));

}
