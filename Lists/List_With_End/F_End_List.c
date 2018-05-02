#include <stdio.h>
#include <stdlib.h>
#include "F_End_List.h"
#include "Type_List.h"

typedef struct Info_Node{ // Info node.
    int size; // Represents number of nodes.
    Node head; // Points at first node.
    Node end; // Points at last node.

}Info_Node;

typedef struct Each_Node{ // Each node.
    TL element; // Elements.
    Node next; // Next node.

}Each_Node;

Info Create_List(void){ // Create an info node and empty list.
    Info x;

    x = malloc(sizeof(Info_Node)); // Create node.
    if(x == NULL) exit(1);

    x->size = 0; // Zero elements.
    x->head = NULL; // Empty list.
    x->end = NULL; // Empty list

    return(x);
}

void Destroy_List(Info * In){ // Delete info node and list.
    Node tmp1, tmp2; // Create pointer to nodes and an assisting pointer.

    tmp1 = (*In)->head; // Begin at the start of list.

    while(tmp1){ // cross list.

        tmp2 = tmp1; // Save current node.
        tmp1 = tmp1->next; // Go next node.
        free(tmp2); // Delete current node.
    } // End while.

    (*In)->head = NULL; 
    (*In)->end = NULL;
    (*In)->size = 0;
    free(*In); // Delete info node.

    *In = NULL; // Set to null.

}

int Empty_List(Info In){ // Check if list is empty.

    return(In->head == NULL);

}

void Get_Value_List(Node p , TL *x, int * const error){ // Get element from given node.
    
    *error = 0;

    if(p == NULL){ // Check if node is valid.
        *error = 1;
        return;
    }

    else setvalue(x,p->element);
}

void Change_Node_List(Node p, TL x, int *const error){ // Change element in given node.

    *error = 0;

    if(p == NULL){ // Check if node is valid.
        *error = 1;
        return;
    }
    else setvalue(&p->element,x);

}

void Print_List(const Info In, int * const error){ // Print list.
    Node tmp; // Create pointer to nodes.

    *error = 0;

    tmp = In->head; // Begin from the start.

    if(Empty_List(In)){ // Check if list is empty.
        *error = 1;
        return;
    }
    else{
        while(tmp){ // Cross list.
            printf("%d\n",tmp->element.x);
            tmp = tmp->next;

        } // End while.

    }

}


void Go_First_Node_List(Info const In, Node * const p, int * const error){ // Go to first node of list.

    *error = 0;

    if(Empty_List(In)){ // Check if list is empty.
        *error = 1;
        return;
    }

    else *p = In->head; 
}

void Go_Last_Node_List(Info const In, Node * const p, int * const error){ // Go to last node of list.
    
    *error = 0;

    if(Empty_List(In)){ // Check if list is empty.
        *error = 1;
        return;
    }
    
    else *p = In->end; // Go to last node.
}

void Insert_At_Start_List(Info *In, TL y,int * const error){ // Add node at begin of list.
    Node x; // Create new node.

    *error = 0;

    x = malloc(sizeof(Each_Node)); // Create new node.
    if(x == NULL){
        *error = 1;
        return;
    }

    setvalue(&x->element,y); // Add element.
    
    if((*In)->head != NULL){ // There are more nodes.
            x->next = (*In)->head;

    }
    else{ // This is first node.
        x->next = (*In)->head;
        (*In)->end = x; // And the last node.
    }
    

    (*In)->size++; // Increase size.
    (*In)->head = x; // Set new node the begin of list.

}

void Insert_Next_List(Info *In, Node p, TL x, int * const error){ // Insert node in list.
    Node y; // Create new node.

    *error = 0;

    y = malloc(sizeof(Each_Node));
    if(y == NULL){
        *error = 1;
        return;
    }
    else{
        setvalue(&y->element,x); // Set element in node.
        y->next = p->next; // Next of new node is next of current. 
        if(p->next == NULL) (*In)->end = y; // If current node is last, new node is last now.
        p->next = y; // Current node points to new node.
        
    }
    (*In)->size++;
    
}

void Insert_List(Info *In, Node p, TL x, int *error){ // Insert node at list.

    *error = 0;

    if(p == NULL) Insert_At_Start_List(In,x,error);
    else Insert_Next_List(In,p,x,error);

}
