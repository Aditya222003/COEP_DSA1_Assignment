#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data ;
    struct node* left ;
    struct node* right ;
} node ;
typedef node* BST ;
void initBST( BST *t )
{
    *t = NULL ;
    return ;
}
void recurssion_createBST( BST *t , int key )
{
   
    if( !*t )
    {
        node* newnode = ( node* ) malloc ( sizeof( node ));
        newnode ->data = key ;
        newnode -> left = newnode -> right = NULL ;
        *t = newnode;
        return ;
    }

    node *temp = *t;

    if(key > temp -> data)
        recurssion_createBST(&(temp -> right), key);
    else if (key < temp -> data)
        recurssion_createBST(&(temp -> left), key);
    else 
        return;
   
}

void inorder( BST t )
{
    
    if( !t )
    {
        return ;
    }
    inorder( t -> left );
    printf("%d\t", t -> data );
    inorder( t -> right );
    return ;
}

void main()
{
     BST t ;
    initBST( &t ) ;
    recurssion_createBST( &t , 10 );
    recurssion_createBST( &t , 20 );
    recurssion_createBST( &t , 30 );
    recurssion_createBST( &t , 23 );
    recurssion_createBST( &t , 45 );
    recurssion_createBST( &t , 26 );
    recurssion_createBST( &t , 63 );
    recurssion_createBST( &t , 74 );
    recurssion_createBST( &t , 24 );
    recurssion_createBST( &t , 11 );
    recurssion_createBST( &t , 55 );
    recurssion_createBST( &t , 77 );
    recurssion_createBST( &t , 113 );
    recurssion_createBST( &t , 554);
    recurssion_createBST( &t , 332 );
    recurssion_createBST( &t , 66);
    recurssion_createBST( &t , 112 );
    printf("\n INORDER TRAVERSAL :- ");
    inorder( t );
}