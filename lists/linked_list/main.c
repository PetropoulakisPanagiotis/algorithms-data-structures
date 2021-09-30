#include <stdio.h>
#include "linked_list.h"

int main(void){

    linkedListPtr myListPtr;
    
    myListPtr = createLinkedList();

    insertEndLinkedList(myListPtr, 1);
    insertEndLinkedList(myListPtr, 7);
    insertEndLinkedList(myListPtr, 3);
    insertEndLinkedList(myListPtr, 0);
    insertEndLinkedList(myListPtr, 4);
    printLinkedList(myListPtr);
    
    printf("\nSsorted\n"); 
    sortLinkedList(&myListPtr->head);
    printLinkedList(myListPtr);
    /*   
    insertStartLinkedList(myListPtr, 5);
    printLinkedList(myListPtr);  
    printf("\n\n\n");

    insertStartLinkedList(myListPtr, 6);
    printLinkedList(myListPtr);
   
    printf("\nExists:%d\n",existsValueLinkedList(myListPtr, 3));

    deleteValueLinkedList(myListPtr, 2);
    printf("\n\n");
    printLinkedList(myListPtr);
 
    printf("\nInsert Middle\n"); 
    insertMidleSizeLinkedList(myListPtr, 22); 
    printLinkedList(myListPtr);

    printf("\nInsert Middle\n"); 
    insertMidleSizeLinkedList(myListPtr, 211); 
    printLinkedList(myListPtr);


    */
    destroyLinkedList(&myListPtr);

    return 0;
}
