#include "Stack.h"



void stack_create(stack *stack_ptr){
  
    // NULL stack is equal to say top == -1.//

    stack_ptr->top = - 1; 
}

int stack_empty(stack stack_s){

    // Empty stack return 1 else 0.//

    return(stack_s.top == -1 );
}

int stack_full(stack stack_s){

    // If stack is full return 1 else 0.//

    return(stack_s.top == MAX -1);
}

void stack_push(stack *stack_ptr, type x, int *overflow){

    if(stack_full(*stack_ptr)){
        *overflow = 1;
    } // Full stack means overflow.
    
    else{ // Save given element.
        *overflow = 0;
        stack_ptr->top++; // Rise top, to place element.
        stack_ptr->arr[stack_ptr->top] = x;
    }


}

void stack_pop(stack *stack_ptr, type *x, int *underflow){

    if(stack_empty(*stack_ptr)){
        *underflow = 1;
    } // Empty stack means underflow.
    
    else { // Take first element from stack.
        *underflow = 0;
        *x = stack_ptr->arr[stack_ptr->top];
        stack_ptr->top = stack_ptr->top--; // Top of stack reduced.
    }

}

