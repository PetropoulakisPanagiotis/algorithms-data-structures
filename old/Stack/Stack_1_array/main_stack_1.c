#include <stdio.h>
#include "stack_1.h"


int main(void){
    
    stack_1 stack_test; // We have one stack named: stack_test. 
    int status; // Overflow or underflow.
    type_s save; // So as to take a value from stack.

    start_stack(&stack_test); // Begin from empty stack.

    push(&stack_test,50,&status);

    push(&stack_test,35,&status);

    pop(&stack_test,&save,&status);



    return 0;

}
