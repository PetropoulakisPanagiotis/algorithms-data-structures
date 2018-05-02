#include <stdio.h>
#include "List_Double.h"

int main(void){
    Info In;
    Node head;
    Node tmp;
    int error;
    TD x;

    x.x = 7;


    head = NULL;
    
    In = Create_List();
   
    Insert_List(&In,head,x,&error);
    x.x = 6;
    Insert_List(&In,head,x,&error);
    x.x = 8;
    
    Insert_List(&In,head,x,&error);
    x.x = 9;

    Insert_List(&In,head,x,&error);
    
    Go_Last_Node_List(In, &head,&error);
    x.x = 10;

    Insert_List(&In,head,x,&error);

    Print_List(In,&error);


    return 0;
}
