#include<stdio.h>
#include<stdlib.h>
#include"tree.h"



void init(BST *t)
{
    *t = NULL;
    return;
}
void insert(BST *t, int key)
{
    node *nn = (node*)malloc(sizeof(node));
    if(!nn)
    {
        return;
    }
    nn->data = key;
    nn->left = NULL;
    nn->right = NULL;

    node *p, *q = NULL;
    p = *t;
    if(!p)
    {
        *t = nn;
        return;
    }
    while(p)
    {
        q = p;
        if(p->data == key)
        {
            return;
        }
        if(p->data < key)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    if(key < q->data)
    {
        q->left = nn;
    }
    else
    {
        q->right = nn;
    }
    return;
}
int search(BST t, int key)
{
    if(!t)
    {
        return 0;
    }
    node *p = t;
    while(p)
    {
        if(p->data == key)
        {
            return 1;
        }
        if(p->data < key)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return 0;
}