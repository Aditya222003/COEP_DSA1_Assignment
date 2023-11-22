#include<stdio.h>

void merge ( int arr[] , int l , int r )
{
     int mid = (l + r ) /2 ;
     int n1 = mid -l + 1 ;
     int n2 = r - mid ;

     int a[ n1 ] ; // temps array 
     int b[ n2 ] ; 

     for ( int i = 0 ; i < n1 ; i++)
     {
        a[i] = arr [ l + i ];
     }
     for ( int i = 0 ; i < n2 ; i++)
     {
        b[i] = arr [ mid+1+i ];
     }
     int i = 0 ; int j = 0 ; int k = l ;

     while ( i < n1  && j < n2 )
     {
        if ( a[i] < b[j])
        {
            arr[k] = a[i] ;
            k++ ; i++ ;
        }
        else 
        {
            arr[ k ] = b[ j ];
            k++ ; j ++ ;
        }
     }
     while( i< n1 )
     {
        arr[ k ] = a[i] ;
        k++ ; i++ ;
     }
     while( j < n2 )
     {
        arr[k] = b [j] ;
        k++ ; j ++ ;
     }
}


void mergeSort ( int arr[] , int l , int r)
{
    if( l < r )
    {
       
    int mid = ( l + r ) / 2 ;
    // left part sort 
    mergeSort( arr , l , mid);
    //Right part sort
    mergeSort( arr , mid +1 , r );
    merge( arr , l , r );
    }

}

int main()
{
    int arr[5] = { 2 , 5 , 1 , 6 , 9} ;
    int n = 5 ;
    mergeSort( arr , 0 , n-1);
    printf("\n\n");
    for( int i = 0 ; i <5 ; i++)
    {
        printf( "   %d   ",arr[i]);
        
    }
    printf("\n");
    return  0 ;
}