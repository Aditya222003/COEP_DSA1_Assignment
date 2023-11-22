#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
typedef struct Stack
{
    char *arr ;
    int size ;
    int top ;
}Stack ;

int isAlphaorNum( char ch )
{
    if( ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch<= 'z')
    {
        return 1 ;
    }
    int digit = ch - '0' ;
    if( digit >= 0 && digit <= 9 )
    {
        return 1;
    }
    return 0;
}
int isNum( char ch )
{
    int digit = ch - '0' ;
    if( digit >= 0 && disit <= 9)
    {
        return 1 ;
    }
    return 0;
}

int precedence( char ch )
{
    if( ch == '(' )
        return 0 ;
    if( ch == '+' || ch == '-')
        return 1 ;
    if( ch == '*' || ch == '/')
        return 2 ;
    return 0;
}

char* infixToPostfix( char que[], int n )
{
    Stack s ;
    initStack( &s , n );
    static char ans[50] ;

    for( int i =0 ; que[i] != '\0' ; i++)
    {
        char ch = que[i] ;
        if( isAlphaorNum(ch))
        {
            ans[k++] = que[i];
        }
        else if ( ch == ')')
        {
            push(&s , ch);
        }
        else if ( ch == ')')
        {
            while( top(s) != ' ' && top(s) != '(')
            {
                ans[k++] = top(s);
                pop(&s);
            }
            pop( &s );
        }
        else
        {
            char ch = que[i];

            while( top(s) != ' ' && precedence( top(s)) >= precedence(ch))
            {
                ans[k++] = top(s);
                pop(&s);
            }
            push(&s)
        }
    }

    while(!isEmpty(s))
    {
        char ch = top(s) ;
        ans[k++] = ch ;
        pop (&s);
    }
    return ;
}

