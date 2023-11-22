#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data ;
	struct node* next ;
	
}node;

typedef struct node* List ; 

void initList( List *l1)
{
	*l1 = NULL ;
	return ;
}
void append (List *l , int key )
{
	node* newnode = (node*)malloc(sizeof(node*));
	newnode -> data = key ;
	newnode -> next = NULL ;
	
	if (!newnode)
	{
		return ;
	}
	if (!*l)
	{
		*l = newnode ;
		return ;
	}
	
	node* temp = *l ;
	while(temp -> next)
	{
		temp = temp-> next ;
	}
	temp -> next = newnode ;
	return ;
}

void display( List l1 )
{
	node* temp = l1 ;
	printf("\n");
	while( temp  )
	{
		printf("  %d  -> ", temp -> data );
		temp = temp -> next ;
	}
	printf(" NULL \n");

}

void main()
{
	List l1 ;
	initList( &l1 );
	append( &l1 , 10 );
	display( l1 );
	append( &l1 , 20 );
	display( l1 );
	append( &l1 , 30 );
	display( l1 );
	append( &l1 , 40 );
	display( l1 );
	append( &l1 , 50 );
	display( l1 );
	append( &l1 , 60 );
	display( l1 );
}
