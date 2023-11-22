/*
				NAME :: RAUL ADITYA 
				MIS  :: 142203016
				
					ASSIGNMENT 8
				==================
*/


typedef struct Stack{
    char *arr;
    int t;
    int size;
}Stack;


void initStack(Stack*,int);
void push(Stack*,char);
void display(Stack);
int isFull(Stack);
int isEmpty(Stack);
void insert(Stack*,char*);
int palindrome(Stack,Stack);
int pop(Stack*);
void reverse(Stack*);
