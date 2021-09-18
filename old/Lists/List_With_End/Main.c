#include <stdio.h>
#include "F_End_List.h"
#include "Type_List.h"

int main(void){
    Info info;
    Node head;
    TL x;
    int error;


    x.x = 6;
    head = NULL;


    info = Create_List();
    
    Insert_List(&info,head,x,&error);
    
    x.x = 7;
    Insert_List(&info,head,x,&error);

    Go_Last_Node_List(info, &head,&error);

    x.x = 12;

    Insert_List(&info,head,x,&error);
    Print_List(info,&error);

    return 0;

}
