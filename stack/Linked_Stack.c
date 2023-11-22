#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data ;
    struct node* next ;
}node ;
typedef struct node* Linkstack ;
//struct node* top = NULL ;

void initLinkedStack( Linkstack *ls )
{
    *ls = NULL ;
    return ;
}
void push( Linkstack *ls , int key )
{
    Linkstack newnode = (node*) malloc( sizeof( node ));
    newnode -> next = NULL ;
    newnode -> data = key ;

    if(!newnode)
    {
        return ;
    }
    if(!(*ls) )
    {
        *ls = newnode ;
        return ;
    }
    // 5 5 4 3 2 1
   newnode -> next = (*ls);
   (*ls) = newnode;
   return ;
} 
int pop( Linkstack *ls)
{
    node* temp = *ls ;
    int ele = temp -> data;
    *ls = (*ls) -> next ;
    free(temp );
    return ele;
}
void display( Linkstack ls )
{
    node* temp = ls ;
    printf("\n");
    while( temp )
    {
        printf("  %d  ",temp -> data );
        if(temp -> next )
        {
            printf(" ==>");
        }
        else
        {
            printf(" ==> NULL ");
        }
        temp = temp -> next ;
    }
    printf("\n");
}

void main()
{
    Linkstack ls ;
    initLinkedStack( &ls );
    push( &ls , 10 );
    push( &ls , 20 );
    push( &ls , 30 );
    push( &ls , 40 );
    push( &ls , 50 );
    printf("\n\n POPPED ELEMENT IS =  %d",pop(&ls));
    display(ls);

}