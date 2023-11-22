#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

typedef node *BST;

void init(BST *t);
void insert(BST *t, int key);
int search(BST t, int key);