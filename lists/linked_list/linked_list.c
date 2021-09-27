#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

linkedListPtr createLinkedList(){

    linkedListPtr myListPtr;

    // Create new head node //
    myListPtr = malloc(sizeof(linkedList));
    if(myListPtr == NULL)
        return NULL;

    // Init members //
    myListPtr->size = 0;
    myListPtr->head = NULL;
    
    return myListPtr;
}

int destroyLinkedList(linkedListPtr* myListPtr){

    if(*myListPtr == NULL)
        return 0;

    // Save the nodes of the list //
    nodePtr currNode = (*myListPtr)->head, nextNode; 
    
    // Delete head //
    free(*myListPtr);
    *myListPtr = NULL;

    // Delete nodes //
    while(currNode != NULL){
        nextNode = currNode->nextNode; 
        free(currNode);
        currNode = nextNode;
    }


    return 0;
}

int insertStartLinkedList(linkedListPtr myListPtr, int value){
    nodePtr newNode;
   
    // Create the new node //
    newNode = malloc(sizeof(node));
    if(newNode == NULL)
        return -1;
    
    newNode->value = value;
    newNode->nextNode = NULL;
   
    // Update head node //
    myListPtr->size += 1;

    // Save sublist //
    nodePtr subList = myListPtr->head;

    // Empty sublist //
    if(subList == NULL)
        myListPtr->head = newNode;
    else{
        // Concatenate newnode with sublist //
        myListPtr->head = newNode; 
        newNode->nextNode = subList;
    }

    return 0;
}

int insertEndLinkedList(linkedListPtr myListPtr, int value){
    nodePtr newNode;
   
    // Create the new node //
    newNode = malloc(sizeof(node));
    if(newNode == NULL)
        return -1;
    
    newNode->value = value;
    newNode->nextNode = NULL;
   
    // Update head node //
    myListPtr->size += 1;

    // Add the new node //
    nodePtr currentNodePtr = myListPtr->head;

    // Empty list //
    if(currentNodePtr == NULL)
        myListPtr->head = newNode;
    else{
        
        // Go to the last node //
        while(currentNodePtr->nextNode != NULL)
            currentNodePtr = currentNodePtr->nextNode;  
    
        currentNodePtr->nextNode = newNode;
    }

    return 0;
}

int existsValueLinkedList(linkedListPtr myListPtr, int value){
    nodePtr currNode = myListPtr->head;

    while(currNode != NULL){
        if(currNode->value == value)
            return 1;
        currNode = currNode->nextNode;
    }

    return 0;
}

int deleteValueLinkedList(linkedListPtr myListPtr, int value){
    nodePtr currNode = myListPtr->head, prevNode = myListPtr->head;

    while(currNode != NULL){

        // Value found. Delete the node //
        if(currNode->value == value){

            if(prevNode == currNode)
                myListPtr->head = currNode->nextNode;
            else    
                prevNode->nextNode = currNode->nextNode;
            free(currNode);
            return 1;
        }

        prevNode = currNode;
        currNode = currNode->nextNode;
    }

    return 0;
}

void printLinkedList(linkedListPtr myListPtr){
    nodePtr currentNodePtr = myListPtr->head;

    while(currentNodePtr != NULL){
        printf("%d\n", currentNodePtr->value);
        currentNodePtr = currentNodePtr->nextNode;  
    }
}
