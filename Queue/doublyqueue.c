#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data ;
    struct node* next ;
    struct node* prev ;
}node ;

typedef struct Queue 
{
    node* front ;
    node* rear ;
}Queue ;

void initQueue( Queue* q )
{
    q -> front = NULL ;
    q -> rear = NULL ;
}

int isEmpty( Queue q )
{
    return q.front == NULL ;
}
void enqueue ( Queue *q , int data )
{
    node* newnode = (node*) malloc( sizeof( node ));
    if( !newnode){ return ;} 

    newnode -> data = data ;
    newnode -> next = NULL ;
    newnode -> prev = NULL ;

    if( isEmpty( *q )) 
    {
        q -> front = newnode ;
        q -> rear = newnode ;
        return ;
    } 
    newnode -> prev = q -> rare ;
    q -> rare -> next = newnode ;
    q -> rear = newnode ;
}

int dequeue( Queue *q)
{
    if(isEmpty(*q))
    {
        return -1 ;
    }
    node* freenode =q -> front ;
    if( q -> front == q -> rear )
    {
        q -> front = NULL ;
        q -> rear = NULL ;
    }
    else
    {
        q -> front = q-> front -> next ;
    }
    free( freenode);
    return freenode -> data ;
}