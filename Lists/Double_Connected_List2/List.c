#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Type.h"


typedef struct Info_Node{ // Info node.
    Node list; // First node of list.
    int size; 

}Info_Node;

typedef struct Each_Node{ // ELements of each node.
    TE element; 
    Node next; // Next node;
    Node previous; // Previous node.
}Each_Node;

void Create_List(In *I){ // Create info node and empty list.

    if(*I != NULL) return;

    *I = malloc(sizeof(Info_Node)); // Create info node.

    (*I)->size = 0; 
    (*I)->list = NULL; // Empty list.
}

void Destroy_List(In *I){ // Destroy info node and all nodes.
    Node tmp1,tmp2; // Tmp: Pointer in nodes, so as cross all list.

    if(*I == NULL) return;

    tmp1 = (*I)->list; // Start from the beginning.

    while(tmp1){ // Cross list
    
            
        tmp2 = tmp1; // Keep current node.

        tmp1 = tmp1->next; // Go next.

        free(tmp2); // Delete current node.
    } // End while.

    free(*I); // Delete info node.

    *I = NULL;
}


int Empty_List(In I){ // Check if list is empty.

    if(I == NULL) return -1;

    return(I->list == NULL);
}

void Element_List(Node N){ // Take element of given node.

    if(N != NULL) Write_Value(N->element);
}

void Change_Node_List(Node N, TE elm){ // Change element of given node.

    if(N != NULL) Set_Value(&N->element,elm);
}

void Print_List(In I){ // Print all list.
   Node tmp; // Tmp: Cross list.

   if(I == NULL) return;

   if(Empty_List(I)) printf("List is empty.\n");

    tmp = I->list; // Start from the beginning.

    while(tmp){ // Cross list.

        Write_Value(tmp->element); // Print node.

        tmp = tmp->next; // Go next node.

    } // End while.
}

void Insert_List(In I, Node tmp, TE elm){ // Insert node in list.

    if(tmp == NULL) Insert_At_Start_List(I,elm);
    else Insert_After_Node_List(I,tmp,elm);
}

void Insert_At_Start_List(In I, TE elm){ // Insert element at start of the list.
    Node new; // New: New created node.

    new = malloc(sizeof(Each_Node));

    if(new == NULL) return;

    Set_Value(&new->element,elm); // Set data.

    new->next = I->list; // Set next of new node.
    
    new->previous = NULL;

    if(!Empty_List(I)) I->list->previous = new; 
    
    I->list = new; // Set main list.

    I->size++; // Increase size of list.
}

void Insert_After_Node_List(In I, Node tmp, TE elm){ // Insert element after given node.
    Node new; // New: New node of list.

    new = malloc(sizeof(Each_Node));

    if(new == NULL) return;

    Set_Value(&new->element,elm); // Set data.

    new->next = tmp->next;
    
    new->previous = tmp;

    tmp->next->previous = new;

    tmp->next = new;
    
    I->size++;
}

int Print_Size_List(In I){ // Take size of list.

    if(I == NULL) return -1;

    return(I->size);
}


Node Next_Node_List(Node tmp){ // Give next node of list.
    
    if(tmp != NULL && tmp->next != NULL) return tmp->next;
    else return NULL;
}

Node Previous_Node_List(In I, Node tmp){ // Give previous node of list.
    
    if(tmp == NULL) return NULL;   

    if(tmp->previous == NULL) return NULL;

    return tmp->previous;
}

Node First_Node_List(In I){ // Give first node of list.

    if(Empty_List(I)) return NULL;
    else return I->list;
}

Node Last_Node_List(In I){ // Give last node of list.
    Node tmp; // Tmp: Cross list.

    tmp = I->list;

    if(tmp->next == NULL) return NULL;

    while(tmp->next) tmp = tmp->next;

    return tmp;
}


void Delete_Node_List(In I, Node *tmp){ // Delete given node of list.
    Node prev; // Prev: Keep previous node of given node.

    if(I == NULL) return;
    if(Empty_List(I)) return;

    if(I->list == *tmp){ // Delete first node.

        I->list = I->list->next;
        I->list->previous = NULL;
        free(*tmp);
        *tmp = NULL;
    }

    else{ // Delete random node.

        prev = Previous_Node_List(I,*tmp);

        prev->next = (*tmp)->next;

        if(prev->next != NULL) prev->next->previous = prev;

        free(*tmp);
        
        *tmp = NULL;

    }

    I->size--;
}


void Search_List(In I, Node *tmp, TE elem, int * found){
    Node curr; // Curr: Cross list.

    if(I == NULL) return;

    if(Empty_List(I)) return;

    *found = 0;
    *tmp = NULL;
    
    curr = I->list; // Start from the beginning.

    while(curr){ // Cross list.

        if(Equal_Value(curr->element,elem)){
            *found = 1;
            *tmp = curr;
            break;
        }

        curr= curr->next;

    } // End while.
}










