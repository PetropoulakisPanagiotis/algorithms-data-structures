#include <stdio.h>
#include "List.h"
#include "Type_List.h"

int main(void){
    Info_Ptr In;
    Go_Next head;
    T_List k;
    int error;
   

    
    head = NULL;
    In = List_Create();
    printf("%d\n",List_Empty(In));

    k.x = 6;
    Insert_Node_List(&In,head,k,&error);

    k.x = 7;





    k.x = 12;



    k.x = 13;

    List_Destroy(&In);

   return 0;
}


