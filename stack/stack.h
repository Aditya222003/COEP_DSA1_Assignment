typedef struct Stack{
    char *arr;
    int top;
    int size;
}Stack;


void initStack(Stack*,int);
void push(Stack*,char);
void display(Stack);
int isFull(Stack);
int isEmpty(Stack);
void insertIntoStack(Stack*,char*);
int checkPalindrome(Stack,Stack);
int pop(Stack*);
void reverse(Stack*);