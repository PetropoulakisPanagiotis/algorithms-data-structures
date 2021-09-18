#include <stdio.h>
#include "List.h"

int main(void){
    Info_Ptr List_Info;
    int error;
    T_List x,y;
    Go_Next List_Ptr;
    
    List_Ptr = NULL;
    
    x.x = 5;
    y.x = 6;

    List_Info = List_Create();
   
    

    Insert_Node_List(&List_Info,List_Ptr,x,&error);
    
    Go_First_Node_List(List_Info,&List_Ptr,&error);


    Insert_Node_List(&List_Info,List_Ptr,y,&error);
      
    x.x = 45;
    y.x = 123;
    
    
    Insert_Node_List(&List_Info,List_Ptr,x,&error);
       
    Print_List(List_Info,&error);
    printf("\n");
    
    Delete_Node_List(&List_Info,&List_Ptr,&error);

    Print_List(List_Info,&error);
    
    return 0;
}
