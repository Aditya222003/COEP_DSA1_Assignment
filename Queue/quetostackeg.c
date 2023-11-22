#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data ;
    struct node* next ;
}node ;

typedef struct queue{
    struct node* front ;
    struct node* rear ;
    int count ;
}queue ;
typedef struct stack
{
    queue q1 , q2 ;
}stack ;

int isEmpty( queue q)
{
    return (q.rear == NULL || q.front == NULL) ;
}
void initqueue( queue *q )
{
    q -> front = NULL ;
    q -> rear = NULL ;
    q -> count = 0 ;
}
void initstack( stack *s )
{
    initqueue(&s->q1);
    initqueue(&s->q2);
}
void enqueue( queue *q , int data )
{
    node* newnode = ( node* ) malloc ( sizeof ( node ));
    newnode -> data = data ;
    newnode -> next = NULL ;
    q -> count++ ;
    if( isEmpty( *q ))
    {
        q -> front = newnode ;
        q-> rear = newnode ;
        return ;
    }
    q -> rear -> next = newnode ;
    q -> rear = q -> rear -> next ;
    return ;
}

int dequeue( queue *q )
{
    q -> count-- ;
    if( isEmpty(*q))
    {
        printf("\nStack is empty\n");
        return -1 ;
    }
    if(q -> front == q -> rear )
    {
        int element = q -> front -> data ;
        q -> front = NULL ;
        q -> rear = NULL ;
        return element ;
    }
    node* temp = q -> front ; 
    int element2 = temp -> data ;
    q -> front = q -> front -> next  ;
    free( temp ) ;
    return element2; 
}

void push( stack *s  , int data )
{
    enqueue( &s -> q1 , data );
}

int pop( stack *s )
{
   while(s->q1.count != 1 )
   {
    enqueue( &s->q2 , dequeue( &s->q1)) ;
   }
   int element = dequeue( &s->q1 );
   while( s -> q2.count!=0)
   {
    enqueue( &s -> q1 , dequeue(&s -> q2 ));

   }
   return element ;
}
void display(queue *q)
{
    node * temp = q -> front;

    while(temp)
    {
        printf("%d\t",temp->data);
        temp = temp -> next;
    }
    printf("\n");

    return;

}

int main()
{
    stack s;
    initstack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    display(&s.q1);

    pop(&s);
    pop(&s);

    display(&s.q1);

    return 0;
}