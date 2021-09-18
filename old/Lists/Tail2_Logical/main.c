#include <stdio.h>
#include "Tail.h"

int main(void){
    Tail T;
    int choose;
    

    while(1){

        scanf("%d",&choose);

        switch(choose){

            case 1: 

                Create_Tail(&T);

                break;

            case 2:
                scanf("%d",&choose);

                Add_Tail(&T,choose);

                break;

            case 3:

                Remove_Tail(&T);

                break;

            default:
                
                return 0;
                
                break;

        } // End switch.
    } // End while.

    return 0;
}
