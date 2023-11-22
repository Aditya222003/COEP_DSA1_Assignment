#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int *arr , int start , int end , int key )
{
    if( start <= end )
    {
        int mid = start + (end - start)/2;
        if( key == arr[mid])
        {
            return mid ;
        }
        if( key < arr[mid] )
        {
            return BinarySearch( arr , start ,mid-1 , key);

        }
        return BinarySearch( arr , mid+1,end , key );

    }
return -1 ;
}
void display(int arr[] , int end )
{
    
    printf("\n\n");
    for ( int i = 0 ; i < end ; i++)
    {
        printf("   %d   ", arr[i]);
    }
    printf("\n");
}
void main()
{
    int arr[5] = { 10 , 20 , 30 , 40 , 50 };
    int key = 40 ;
    int size = sizeof(arr) / sizeof(int) ;

    display( arr ,5);
    printf(" \n\n KEY TO BE SEARCHED IS = %d \n\n", key );   
    
    int res = BinarySearch(arr , 0 ,size,40);
    printf("=================%d",res);
    if( res == -1)
    {
        printf("\n ----- THE ELEMENT %d IS NOT PRESENT IN THE LIST ----- \n\n",key);
    }  
    else
    {
        printf("\n ----- THE ELEMENT %d IS  PRESENT IN THE LIST ----- \n\n",key);
    }    
}