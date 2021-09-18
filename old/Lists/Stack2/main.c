#include <stdio.h>
#include "Stack.h"


int main(void){
    Stack S;
    int choose = 0;
    
    while(1){

        scanf("%d",&choose);

        switch(choose){

            case 1: 
                 
                Create_Stack(&S);
                printf("%d\n",S.top);
                break;

            case 2:

                Pop_Stack(&S);

                break;

            case 3:
    
                scanf("%d",&choose);
                Push_Stack(&S,choose);

                break;
        
            default:

                return 0;
                break;

        }
    
    } // End while.


    return 0;
}
