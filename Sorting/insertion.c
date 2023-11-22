#include<stdio.h>
void insertion( int arr[], int n )
{
    int i , key , j ;
    for ( i = 1 ; i < n ; i ++)
    {
        key = arr[i];
        j = i - 1 ;

        while( j>= 0 && arr[j]>key)
        {
            arr[j+1] = arr[j] ;
            j = i -1 ;
        }
        arr[ j + 1 ] = key ;
    }
}
void printArray( int arr[] , int n )
{
    int i ;
    for ( i = 0 ; i < n ; i++)
    {
        printf("  %d  ",arr[i]);
    }
    printf("\n");
}
void main()
{
    int arr[5] = {2,34,55,21,1};
    int n = (sizeof(arr))/sizeof(arr[0]);

    insertion( arr , n);
    printArray( arr , n);
    return ;
}