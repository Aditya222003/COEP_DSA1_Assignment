#include<stdio.h>
void quickSort( int num[] , int first , int last )
{
    int i , j , pivot, temp ;
    if( first < last )
    {
        pivot  = first ;
        i = first ;
        j = last ;

        while( i< j)
        {
            while( num[i]<=num[pivot]&& i < last)
            i++ ;
            while ( num[j] > num[pivot])
            j-- ;

            if( i< j)
            {
                temp = num [i];
                num[i] = num[j];
                num[j] = temp ;
            }

        }
        temp = num[pivot];
        num[pivot] = num[j];
        num[j] = temp ;

        quickSort( num , first , j-1 );
        quickSort( num , j+1 , last );

    }
}

void main()
{
    int num[10] = {22 , 44, 1 , 3 , 24 , 17, 6,78 ,99,11};
    int size = 10 ;
    quickSort(num ,0, size-1);
    printf("\n");
    for(int i = 0 ; i < size ; i ++ )
    {
        printf("  %d  ",num[i]);

    }
    printf("\n");
    return;
}