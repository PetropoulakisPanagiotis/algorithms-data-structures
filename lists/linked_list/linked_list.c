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

nodePtr createNode(int value){
    nodePtr newNode;

    newNode = malloc(sizeof(node));
    if(newNode == NULL)
        return NULL;

    newNode->value = value;
    newNode->nextNode = NULL;

    return newNode;
}

int insertStartLinkedList(linkedListPtr myListPtr, int value){
    nodePtr newNode;
   
    // Create the new node //
    newNode = createNode(value);
    if(newNode == NULL)
        return -1;
   
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
    newNode = createNode(value);
    if(newNode == NULL)
        return -1;
   
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

int insertMidlePointersLinkedList(linkedListPtr myListPtr, int value){
    nodePtr newNode;
   
    // Create the new node //
    newNode = createNode(value);
    if(newNode == NULL)
        return -1;
   
    // Update head node //
    myListPtr->size += 1;

    nodePtr singleStepPtr = myListPtr->head;

    // Insert at start //
    if(singleStepPtr == NULL)
        myListPtr->head = newNode;
    else{
        nodePtr doubleStepPtr = myListPtr->head->nextNode;

        // First condition: for odd lists or lists with one node            //
        // Second condition: for even lists                                 //
        // A previous point could be usefull if we want, for instance,      //
        // to add an element to a 3-items list after the first time and not //
        // after the second one (doubleStep will be NULL)                   //
        while(doubleStepPtr != NULL && doubleStepPtr->nextNode != NULL){

            singleStepPtr = singleStepPtr->nextNode;
            doubleStepPtr = doubleStepPtr->nextNode->nextNode;
        } // End while

        // Insert at the middle //
        newNode->nextNode = singleStepPtr->nextNode;
        singleStepPtr->nextNode = newNode;
    }

    return 0;
}

int insertMidleSizeLinkedList(linkedListPtr myListPtr, int value){
    nodePtr newNode;
   
    // Create the new node //
    newNode = createNode(value);
    if(newNode == NULL)
        return -1;
   
    // Update head node //
    myListPtr->size += 1;

    nodePtr currNodePtr = myListPtr->head;

    // Insert at start //
    if(currNodePtr == NULL)
        myListPtr->head = newNode;
    else{
        int middle = (myListPtr->size - 1) / 2;

        for(int i = 0; i < (middle - 1); i++)
            currNodePtr = currNodePtr->nextNode;

        // For odd lists, use an additional if, in case //
        // we care for a different insertion            //

        newNode->nextNode = currNodePtr->nextNode;
        currNodePtr->nextNode = newNode; 
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

// Mergesorting //
void sortLinkedList(nodePtr* listPtr){
    
    if (*listPtr == NULL || (*listPtr)->nextNode == NULL)
        return;

    nodePtr aSubList, bSubList;

    divideLinkedList(*listPtr, &aSubList, &bSubList);
    
    sortLinkedList(&aSubList);
    sortLinkedList(&bSubList);
    
    *listPtr = mergeLinkedList(aSubList, bSubList);

    return;
}

void divideLinkedList(nodePtr initialList, nodePtr* aSubList, nodePtr* bSubList){

    nodePtr singleStepPtr = initialList;
    nodePtr doubleStepPtr = initialList->nextNode;     
    printf("sasa\n");
    while(doubleStepPtr != NULL && doubleStepPtr->nextNode != NULL){
        singleStepPtr = singleStepPtr->nextNode;
        doubleStepPtr = doubleStepPtr->nextNode->nextNode;
    } // End while

    *aSubList = initialList; 
    printf("sasa\n");
    *bSubList = singleStepPtr->nextNode;
    singleStepPtr->nextNode = NULL;
}

nodePtr mergeLinkedList(nodePtr aSubList, nodePtr bSubList){

    nodePtr resultNode;

    if(aSubList == NULL)
        return bSubList;
    if(bSubList == NULL)
        return aSubList;

    if(aSubList->value <= bSubList->value){
        resultNode = aSubList;
        resultNode->nextNode = mergeLinkedList(aSubList->nextNode, bSubList);
    }
    else{
        resultNode = bSubList;
        resultNode->nextNode = mergeLinkedList(aSubList, bSubList->nextNode);
    }

    return resultNode;
}

void printLinkedList(linkedListPtr myListPtr){
    nodePtr currentNodePtr = myListPtr->head;

    while(currentNodePtr != NULL){
        printf("%d\n", currentNodePtr->value);
        currentNodePtr = currentNodePtr->nextNode;  
    }

    printf("\n");
}
