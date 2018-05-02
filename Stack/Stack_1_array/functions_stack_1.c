#include "stack_1.h"

void start_stack(stack_1 *stackptr){ // We begin from NULL stack.

    stackptr->position = -1; // Null is for us position == -1. 

}

int check_empty(stack_1 stack){ // We have an empty stack.

    if(stack.position == -1) return 1;
    else return 0;

}

void pop(stack_1 *stackptr, type_s *saveptr, int *underflow){ // Take element.

    if(check_empty(*stackptr)) *underflow = 1; // We have not elements.

    else { // Take this element.

       *underflow = 0; // Valid pop.

        *saveptr = stackptr->array[stackptr->position]; // Save element.
        stackptr->position--; // Go to previous element.
        }
}

void push(stack_1 *stackptr, type_s x, int *overflow){ // Insert element/

    if(stackptr->position == MAX - 1) *overflow = 1; // Full stack/

    else { // Not full we are ok.
        
        *overflow = 0; 

        stackptr->position++; // Go next position.
        stackptr->array[stackptr->position] = x; // Save value.
        }

}
