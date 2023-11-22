#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int data ;
    struct node* next ;
}node ;

typedef struct node* List ;

void append ( List *l , int key )
{
    node* newnode = ( node* ) malloc ( sizeof ( node ) ) ;
    newnode -> data = key ;
    newnode -> next = NULL ;

    if( !newnode )  
    {
        return ;
    }
    if( !*l )
    {
        *l = newnode ; 
        return ;
    }

    node* temp = *l ;
    while( temp -> next )
    {
        temp = temp -> next ;
    }
    temp -> next = newnode  ;
    return ; 
}

void addnode( List *l1 , List *l2 )
{
    int tempsum = 0 ;
    int carry = 0 , data1 , data2 ; 
    node* temp1 = *l1 ;
    node* temp2 = *l2 ;
    node* sum = NULL ;
    node* tail = NULL ;

    while( temp1 || temp2 || carry )
    {
        if( temp1 )
        {
            data1 = temp1 -> data ;
        }
        if( temp2 )
        {
            data2 = temp2 -> data ;
        }
        tempsum = data1 + data2 + carry  ;
        carry = tempsum / 10 ;

        node* newnode = ( node* ) malloc ( sizeof( node )) ;
        newnode -> data = tempsum % 10 ;
        newnode -> next = NULL ;

        if( !sum )
        {
            sum = newnode ;
        }
        else 
        {
            tail -> next = newnode ;
        }
        if( temp1 )
        {
            temp1 = temp1 -> next ;
        }
        if( temp2 )
        {
            temp2 = temp2 -> next ;
        }
    }
}
void display( List l )
{
    node* temp = l ;
    printf("\n");

    while ( temp )
    {
        printf("   %d   -> ", temp -> data );
        temp = temp -> next ;
    }
    printf(" NULL \n");
    return ;
}
void initList( List *l )
{
    *l = NULL ;
    return ;
}
void main()
{
    List l , l1 ;
    initList( &l );
    initList( &l1 );
    append( &l , 1 );
    append( &l , 2 );
    append( &l , 3 );
    append( &l , 4 );
    append( &l , 5 );
    display(l);
    append( &l1 , 6 );
    append( &l1 , 7 );
    append( &l1 , 5 );
    append( &l1 , 7 );
    append( &l1 , 8 );
    display(l1);

    addnode( &l , &l1 ) ;

}