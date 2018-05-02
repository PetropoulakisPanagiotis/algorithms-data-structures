#include <stdio.h>
#include "Stack.h"

void Create_Stack(Stack *St){ // Create an empty stack.

    St->top = -1;
}

int Empty_Stack(Stack St){ // Check if stack is empty.

    return(St.top == -1);
}

int Full_Stak(Stack St){ // Check if stack is full.

    return(St.top == MAX - 1);
}


void Pop_Stack(Stack *St){ // Take element from stack.

    if(Empty_Stack(*St)){
        printf("Stack is empty.");
    }
    else{
        printf("%d\n",St->arr[St->top]);
        St->top--;

    }

}

void Push_Stack(Stack *St, int x){ // Add element into stack.

    if(Full_Stak(*St)){
        printf("Full stack.");
    }
    else{
        St->top++;
        St->arr[St->top] = x;

    }
}
