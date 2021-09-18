#ifndef __STACK__
#define __STACK__

#define MAX 10 // Max size of stack. 
#include <stdio.h>

typedef struct Stack_Node{ // Stack elements.
    int arr[MAX];
    int top;

}Stack;

void Create_Stack(Stack *St);

int Empty_Stack(Stack St);

int Full_Stak(Stack St);

void Pop_Stack(Stack *St);

void Push_Stack(Stack *St, int x);
#endif
