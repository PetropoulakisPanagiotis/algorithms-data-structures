#ifndef STACK_1
#define STACK_1

#define MAX 10 // Max members of stack.

typedef int type; // Type of stack.

typedef struct{
    int top; // Top of stack, at the first element of stack.
    type arr[MAX]; // Array of stack.

    
}stack;

void stack_create(stack *);

int stack_empty(stack );

int stack_full(stack );

void stack_push(stack *, type , int *);

void stack_pop(stack *, type *, int *);

#endif 
