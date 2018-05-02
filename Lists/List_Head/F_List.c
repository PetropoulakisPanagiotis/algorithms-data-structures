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
    Info_Ptr In; // Create an info node.
    Go_Next x; // Create the head list.

    In = malloc(sizeof(Info_List)); // Create memory for Info.
    if(In == NULL) exit(-1);

    x = malloc(sizeof(Node_List)); // Create memory for head list.
    if(x == NULL) exit(-1);
    x->next = NULL; // Make an empty list.

    In->size = 0; // Begin from 0 elements in list.
    In->head = x; // Start from head node.
    
    return In;
}

void List_Destroy(Info_Ptr *In){
    Go_Next tmp1, tmp2; // Create two assist pointers in nodes.
    // Also detroy head list.//
    
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

    return(In->head->next == NULL);

}

void Print_List(const Info_Ptr In, int * const error){ // Print stdout elements of list.
    Go_Next tmp; // Create an assist pointer to nodes.

    tmp = In->head->next; // Set tmp at the beggining of list.
    
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

void Change_Element_List(const Go_Next *p, T_List  x, int * const error){ // Change an element in list.

    *error = 0;

    if((*p) != NULL) SetValue(&(*p)->x,x); // Check if node is valid.

    else *error = 1;
    
}

void Insert_Node_List(Info_Ptr * const In, Go_Next p, T_List x, int * const error){ // Insert node at list.
    Go_Next y; // Create new node.

    *error = 0;

    y = malloc(sizeof(Node_List));
    if(y == NULL){
        *error = 1;
        return;
    }
    if(p == NULL){
        y->next = (*In)->head->next;
        (*In)->head->next = y;
    
    SetValue(&y->x,x);
    }
    else{
    y->next = p->next;
    p->next = y;
    
    SetValue(&y->x,x);
    }
    (*In)->size++;


}

void Delete_Node_List(Info_Ptr * const In, Go_Next *p, int  * const error){ // Delete given node.
    Go_Next tmp1, tmp2

        *error = 0;


    if(List_Empty(*In) || *p == NULL){
        *error = 1;
        return;
    }
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

    *p = In->head->next; // Go at start.

}

void Go_Last_Node_List(Info_Ptr const In, Go_Next * const p, int * const error){ // Go to the end of list.
    Go_Next tmp; // Create an assist pointer to nodes.


    tmp = In->head->next; // Start at the first node.

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

