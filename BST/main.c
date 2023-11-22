#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int main()
{
    BST t;
    init(&t);
    insert(&t,23);
    insert(&t,3);
    insert(&t,38);
    insert(&t,140);
    insert(&t,57);
    insert(&t,91);
    printf("%d\n", search(t, 100));
    printf("%d\n", search(t, 3));
    printf("%d\n", search(t, 10));
    printf("%d\n", search(t, 57));
    return 0;
}