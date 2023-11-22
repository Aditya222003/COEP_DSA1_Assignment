#include<stdio.h>

int Binary_Search(int arr[] , int start , int end , int key )
{
	if ( start <= end )
		 {
		 	int mid = start + ( end - start ) / 2 ;
		 	if ( key == arr[mid])
		 	{
		 		return mid ;
		 	}
		 	if (key < arr[mid])
		 	{
		 		return Binary_Search(arr , start , mid - 1 , key );
		 	}
		 	return Binary_Search(arr , mid + 1 , end , key );
		 }
		 return -1 ;

}
void main()
{
	int arr[10] = {10 , 20 , 30 , 40 , 50 , 60 , 70 };
	int n = sizeof(arr) / sizeof(arr[0] );
	int res = Binary_Search(arr , 0 , n-1 , 10 );

	if (res == -1 )
	{
		printf("\n\n The Number is Not present in the Array ...... \n\n");
	}
	else 
	{
		 printf("\n\n The Number is Present in the Array \n\n");
	}
}
