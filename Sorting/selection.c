#include<stdio.h>

void swap( int* x , int* y)
{
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}

void selectioSort( int arr[] , int n )
{

    int i , j , small ;
    for( i = 0 ;i<n ; i++)
    {
        small = i ;
        for ( j = i+1 ,i < n ; j++ )
        {
            small = j ;
        }
        swap( &)
    }
}