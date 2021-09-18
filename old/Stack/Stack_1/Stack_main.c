#include <stdio.h>
#include "Stack.h"


int main(void){
    stack my_stack;
    int option, x, overflow, underflow;

    while(1){
    
        fprintf(stdout,"Give option:\n");
        fprintf(stdout,"Give 0 to create stack\n");
        fprintf(stdout,"Give 1 to push an element in stack\n");
        fprintf(stdout,"Give 2 to pop an element from stack\n");
        fprintf(stdout,"Give 3 to see if stack is empty\n");
        fprintf(stdout,"Give 4 to see if stack is full\n");
        fflush(stdout);
    
        fscanf(stdin, "%d", &option); 

        switch(option){

            case 0:
            
                stack_create(&my_stack);
                break;
       
            case 1:
            
                printf("Give element:");
                fflush(stdout);
                fscanf(stdin, "%d", &x);
            
                stack_push(&my_stack, x, &overflow);
                if(overflow == 1) fprintf(stdout,"Full stack\n");
                break;

            case 2:

                stack_pop(&my_stack, &x, &underflow);
            
                if(underflow == 1) fprintf(stdout,"Cant pop\n");

                fprintf(stdout,"Element is %d\n",x);
                break;
        
             case 3: 
        
                if(stack_empty(my_stack)) fprintf(stdout, "Stack is empty\n");
                else fprintf(stdout, "Stack is not empty\n");
                break;

            case 4:
        
                if(stack_full(my_stack)) fprintf(stdout, "Stack is full\n");
                else fprintf(stdout, "Stack is not full\n");
                break;
            
            default:
                return 0;
                break;


        } // End switch.


        fflush(stdout);
    } // End while.

    return 0;

}
