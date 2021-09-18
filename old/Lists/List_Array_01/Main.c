#include <stdio.h>
#include <stdlib.h>
#include "list_array_1.h"
#include "TList_array_1.h"

int main(void){
    TList list;
    int error;
    int po;

    Create_List(&list);
    
   
    
    Add_Element_List(&list,0,5,&error);
    Add_Element_List(&list,1,6,&error);
   
    Path_List(list);

    Search_Element_List(&list,11,&error);
    printf("%d\n",error);
   

    return 0;
}
