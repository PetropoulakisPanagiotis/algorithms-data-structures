#include <stdio.h>
#include "List.h"
#include "Type.h"

void Options(void);

int main(void){
    In In = NULL;
    Node current = NULL;
    TE element;
    int choose,found;


    while(1){ 

        Options();
        scanf("%d",&choose);

        switch(choose){

            case 1:

                Create_List(&In);

                break;

            case 2:

                printf("List is: %d\n.",Empty_List(In));
                
                break;

            case 3:

                Element_List(current);

                break;

            case 4:

                Print_List(In);

                break;

            case 5:
            
                printf("Give element to change.\n");
                Read_Value(&element);
                Change_Node_List(In,current,element);
        
                break;

            case 6:
        
                printf("Give element to add.\n");
                Read_Value(&element);
                
                Insert_List(In,element);

                break;
            case 7:

                current = First_Node_List(In);

                break;

            case 8:

                current = Last_Node_List(In);

                break;

            case 9:

                current = Next_Node_List(current);

                break;

            case 10:

                current = Previous_Node_List(In,current);

                break;

            case 11:

                Destroy_List(&In);

                break;

            case 12:

                Delete_Node_List(In,&current);
                
                break;

            case 13:

                printf("Size of list is: %d.\n",Print_Size_List(In));

                break;

            case 14:

                printf("Give element to search.\n");
                Read_Value(&element);

                Search_List(In,&current,element,&found);

                if(found == 1) printf("FOUND.\n\n");
                else printf("NOT FOUND.\n\n");
                
                break;


            default: 

                return 0;

                break;


        } // End switch.

    } // Wnd while
    




    return 0;
}

void Options(void){

    printf("Press 1 to create list.\n");
    printf("Press 2 to check if list is empty.\n");
    printf("Press 3 to print current node.\n");
    printf("Press 4 to print all list.\n");
    printf("Press 5 to change node.\n");
    printf("Press 6 to insert element in list.\n");
    printf("Press 7 to go to the first node.\n");
    printf("Press 8 to go to the last node.\n");
    printf("Press 9 to go to next node.\n");
    printf("Press 10 to go to previous node.\n");
    printf("Press 11 to delete list.\n");
    printf("Press 12 to delete current node.\n");
    printf("Press 13 to print size of list.\n");
    printf("Press 14 to search an element into list.\n");
    printf("Press 0 to exit.\n");
}
