#include <stdio.h>
#include "linked_list.h"

int main(void){

    linkedListPtr myListPtr;
    
    myListPtr = createLinkedList();

    insertEndLinkedList(myListPtr, 1);
    insertEndLinkedList(myListPtr, 2);
    insertEndLinkedList(myListPtr, 3);
    printLinkedList(myListPtr);
    printf("\n\n\n");
    
    insertStartLinkedList(myListPtr, 5);
    printLinkedList(myListPtr);  
    printf("\n\n\n");

    insertStartLinkedList(myListPtr, 6);
    printLinkedList(myListPtr);
   
    printf("\nExists:%d\n",existsValueLinkedList(myListPtr, 3));

    deleteValueLinkedList(myListPtr, 2);
    printf("\n\n");
    printLinkedList(myListPtr);
   

    destroyLinkedList(&myListPtr);

    return 0;
}
