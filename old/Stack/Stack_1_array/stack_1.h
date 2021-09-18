#ifndef STACK // Complie once. 
#define STACK

#define MAX 10 // Max elements.

typedef int type_s; // Type of our stack.

typedef struct stack{ // We have position and elements in an array.

    int position;
    type_s array[MAX];
    
}stack_1;



void start_stack(stack_1 *);

int check_empty(stack_1 );

void pop(stack_1 *, type_s *, int *);

void push(stack_1 *, type_s , int *);

#endif
