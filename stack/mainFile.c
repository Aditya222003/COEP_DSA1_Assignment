#include<stdio.h>
#include "stack.h"

int main(){
    Stack s;
    initStack(&s,5);
 insertIntoStack(&s,"ababa");
    // display(s);
    reverse(&s);
    Stack s1 = s;
    printf("%d",checkPalindrome(s,s1));

  return 0;
}