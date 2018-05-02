#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Type_List.h"

typedef struct Info_List{
    int size; // Size of list.
    Go_Next head; // Points at first node of list.

}Info_List; // Info struct of list.


typedef struct Node_List{
    T_List x; // Elements in node.
    Go_Next next; // "Next" points to next node.

}Node_List; // Each node of list.


Info_Ptr List_Create(void){ // Create an Info_List and return a pointer to it.
    Info_Ptr In; 

    In = malloc(sizeof(Info_List)); // Create memory for Info.
    if(In == NULL) exit(-1);

    In->size = 0; // Begin from 0 elements in list.
    In->head = NULL; // No nodes in list - empty list.
    
    return In;
}

void List_Destroy(Info_Ptr *In){
    Go_Next tmp1, tmp2; // Create two assist pointers in nodes.

    tmp1 = (*In)->head; // tmp1 points in first node of list.

    while(tmp1){ // Delete nodes until cross NULL.

        tmp2 = tmp1; // Save current node.
        tmp1 = tmp1->next; // Go to next node.
        free(tmp2); // Delete current node.
        tmp2 = NULL;

    } // End while.

    (*In)->head = NULL; // Delete pointer at first node.
    free(*In); // Delete all Info_List.
    (*In) = NULL; 

}

int List_Empty(Info_Ptr In){ // Check if list is empty.

    // Returns 1 if list is empty, if not 0.//

    return(In->size == 0);

}

void Print_List(const Info_Ptr In, int * const error){ // Print stdout elements of list.
    Go_Next tmp; // Create an assist pointer to nodes.

    tmp = In->head; // Set tmp at the beggining of list.
    
    *error = 0;
    
    if(List_Empty(In)){// Check if list is empty.

        *error  = 1; 
        return;
    }

    while(tmp){ // Cross list until NULL.
    
        printf("%d\n",tmp->x.x); 

        tmp = tmp->next; // Go to next node.
    }

}

void Get_Element_List(const Go_Next p, T_List * const x,  int * const error){ // Get an element from list.
    
    *error = 0;

    if (p != NULL) SetValue(x, p->x); // Check if pointer to node is valid.
    else *error = 1; 


}

void Insert_At_Start_List(Info_Ptr * const  In, T_List x, int * const error){
    Go_Next tmp; // Create an assist node.

    tmp = malloc(sizeof(Node_List)); // Create memory for node.

    if(tmp == NULL) exit(-1);
    
    tmp->x = x; // Give values in node elements.

    tmp->next = (*In)->head; // New node points at the previous start of list.

    (*In)->head = tmp; // Make new start of list to be this node.
    (*In)->size++; // Increase size of nodes, as element was inserted.

}

void Change_Element_List(const Go_Next *p, T_List  x, int * const error){ // Change an element in list.

    *error = 0;

    if((*p) != NULL) SetValue(&(*p)->x,x); // Check if node is valid.

    else *error = 1;
    
}

void Insert_After_Node_List(Info_Ptr * const In, Go_Next p,T_List x, int * const error){ // Add element after giving pointer to node.
    Go_Next tmp;

    tmp = malloc(sizeof(Node_List)); // Create memory for node.

    if(tmp == NULL) exit(-1); 

    tmp->x = x; // Give values in node elements.
    tmp->next = p->next; // New node points where p points previous.
    p->next = tmp; // Change given pointer to node p, and make it point to new node.
    (*In)->size++; // Increase size of nodes, as element was inserted.

}

void Insert_Node_List(Info_Ptr * const In, Go_Next p, T_List x, int * const error){

    *error = 0;

    if(p == NULL) Insert_At_Start_List(In,x,error); // Choose tactic to insert element in list.
    else Insert_After_Node_List(In,p,x,error);

}

void Delete_Node_List(Info_Ptr * const In, Go_Next *p, int  * const error){ // Delete given node.
    Go_Next tmp_1,tmp_2; // To keep current node and previous.

    *error = 0;

    if((List_Empty(*In) == 1) || ((*p) == NULL)){ // Chech if node exists or list is empty.
        *error = 1;
        return;
    }

    if((*In)->head == (*p)){ // If delete first node.
        
        tmp_1 = (*p); // Save current node, that whant delete.
        (*p) = (*p)->next; // Make current to next.
        (*In)->head = tmp_1->next; // Head points to next of current.
    }

    else{
        
        tmp_1 = (*p); // Save current node.
        tmp_2 = (*p); // Save twice current node.

        *p = tmp_1->next; // Go to next node.
        
        Previous_Node_List(*In,&tmp_2,error); // Find previous node.

        if((*error == 1) || (*error == 2)) return; 
        
        tmp_2->next = (*p); // Previous node points to next node of current noce.

    }

    free(tmp_1); // Free memory of node.
    tmp_1 = NULL; 
    (*In)->size--; // Reduce size of list, as element was deleted.

}


void Next_Node_List(Go_Next * const p, int * const error){ // GO next node of given node.
    
    *error = 0;

    if((*p) != NULL){ // If node exists.
        
        if((*p)->next != NULL) (*p) = (*p)->next; // If next node exists go to it.
       
        else *error = 1;

    }

    else *error = 2;


}

void Previous_Node_List(const Info_Ptr In, Go_Next * const p, int * const error){ // Go to previous node of given node.
    Go_Next tmp; // Create assist pointer to node.

    tmp = In->head; // Start from start of list.
    
    *error = 0;

    if((*p) != NULL){ // If node exists.
    
        if((*p) == In->head) *error = 1; // If given node is first, previous doesnt exists.

        else{ 
            
            while(tmp->next != (*p)) tmp = tmp->next; // Move until current node is different with given node.
            *p = tmp; // Save previous node of given.

        }

    }

    else *error = 2;

}


void Go_First_Node_List(Info_Ptr const In, Go_Next * const p, int * const error){ // Go to the first node of list.

    *error = 0;

    if(List_Empty(In)){ // Check if list is empty.
        *error = 1;
        return;
    }

    *p = In->head; // Go at start.

}

void Go_Last_Node_List(Info_Ptr const In, Go_Next * const p, int * const error){ // Go to the end of list.
    Go_Next tmp; // Create an assist pointer to nodes.


    tmp = In->head; // Start at the first node.

    *error = 0;
    
    *p = NULL;

    if(List_Empty(In) == 1){ // Check if list is empty.
        *error = 1;
        return;
    }

    else{
        // Search until next in node points to null.//
        while(tmp->next) tmp = tmp->next;
        *p = tmp;
    }

}

