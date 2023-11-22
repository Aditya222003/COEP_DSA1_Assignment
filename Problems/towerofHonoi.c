#include<stdio.h>


void TOH (int n , char x , char y , char z )
{
    if( n==1 )
    {
        printf("\nMove disk %c from rod %c \n",x,y);
        return ;
    }
    TOH( n-1 , x ,z , y );
    printf("\nMove disk %c from rod %c \n",x,y);
    TOH( n-1 , y,z,x);
}

void main()
{
    int n =3;
    TOH( n , 'A' , 'B' , 'C');
}