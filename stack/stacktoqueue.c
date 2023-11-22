#include<stdio.h>
#include<stdlib.h>

typedef struct stack 
{
    int *arr ;
    int top ;
    int size ;

}stack ;

typedef struct queue 
{
    stack s1 , s2 ;
    int size ;

}queue ;

void initStack( stack *s , int size )
{
    s -> arr = ( int* ) malloc( sizeof ( int )) ;
    s -> top = -1 ;
    s -> size = size ; 
}
int isEmpty( stack s )
{
    return s.top = s.size-1 ;

}

void push( Stack *s , int key )
{
    if(isFull(*s))
    {
        printf("\n OOPS \n NO SPACE ");
    }
    s -> top ++ ;
    s -> arr[s -> top] = key ;
    return ;
}
int pop( Stack *s)
{
    if( isEmpty(*s))
    {
        printf("\n OOPS , NO SPACE ... \n");
        return -1 ;
    }
    else 
    {
        int element = s -> arr [ s -> top ] ;
        s -> top -- ;
        return element ;
    }
}
void display( Stack s )
{
    for( int i = 0 ; i <= s.top ; i++ )
    {
        printf("  %d  " , s.arr[i]);
    }
    printf("\n");
}

void initQueue( queue *q , int size )
{
    initStack( &q->s1 , size );
    initStack( &q->s1 , size );
    q -> size = size ;
}


void enqueue( queue *q ,int data  )
{
    push( &q -> s , data );
}

void dequeue( queue *q )
{
    int item ;
    while( !isEmpty( q -> s1 ))
    {
        int element = pop( &q -> s1 ) ;
        push( &q -> s2 , element );
    }
    return
}