#include <stdio.h>
#include <stdlib.h>
#include "List_Double.h"
#include "Type_D_List.h"

// Typedef same nam.//

typedef struct Info_Node{ // Info node.
    int size; // Size of list.
    Node head; // Start of list.

}Info_Node;

typedef struct Node_D{ // Each node.
    TD element; // Elements of node.
    Node previous; // Previous node.
    Node next; // Next node.

}Node_D;

Info Create_List(void){ // Create an info node and empty list.
    Info x; // Create an info node.

    x = malloc(sizeof(Info_Node));
    if(x == NULL) exit(1);

    x->size = 0; // 0 elements in list.
    x->head = NULL; // Empty list.

    return(x); // Return info node.
}

void Destroy_List(Info * In){ // Destroy all list and info node.
    Node tmp1, tmp2; // Create one pointer at nodes and one assist pointer to nodes.

    tmp1 = (*In)->head; // Begin at the start of list.

    while(tmp1 != NULL){ // Delete list.
        tmp2 = tmp1; // Save current node.
        tmp1 = tmp1->next; // Go next node. 
        free(tmp2); // Delete current node.
    }

    (*In)->head = NULL; 
    (*In)->size = 0;
    free(*In); // Delete info node.
    (*In) = NULL;
}

int Empty_List(Info In){ // Check if list is empty.

    return(In->size == 0);

}


void Element_List(Node p, TD * x, int * const error){ // Get element from given node.
  
    *error = 0;

    if(p == NULL){ // If node not exists.
        *error = 1;
        return;
    }

    else setvalue(x, p->element);
    
}

void Change_List(Node *p, TD x, int * const error){ // Change elements of given node.

    *error = 0;

    if((*p) == NULL){ // If node not exists.
        *error = 1;
        return;
    }

    else setvalue(&(*p)->element ,x);
}

void Print_List(Info In, int * const error){ // Print all list.
    Node tmp; // Assist pointer to nodes.

    tmp = In->head; // Begin from the start.

    *error = 0;
    if(Empty_List(In)){ // Check if list is empty.
        *error = 1;
        return;
    }

    else{

        while(tmp){ // Print nodes.
            printf("%d\n",tmp->element.x);
            tmp = tmp->next;
        } // End while.

    }
}


void Insert_At_Start(Info  * const In, TD x, int * const error){ // Add node at the start of list.
    Node y; // Create new node.

    y = malloc(sizeof(Node_D));
    if(y == NULL){
        *error = 1;
        return;
    }

    setvalue(&y->element,x); // Add elements in node.

    y->next = (*In)->head; // Current node points to beginning node.

    y->previous = NULL; // Current node has no previous, as it is the start of list.
    
    // !!!.//
    if((*In)->head != NULL) (*In)->head->previous = y; // If there is node before, this old node must points previous at this new node.

    (*In)->head = y; // Now list starts from this new node.
    (*In)->size++; // Increase size.


}

void Insert_After_List(Info * const In, Node p, TD x, int * const error){ // Add node next of given node.
    Node tmp; // Create new node.
    
    *error = 0;
    tmp = malloc(sizeof(Node_D));
    if(tmp == NULL){
        *error = 1;
        return;
    }
    else{
        
        setvalue(&tmp->element,x); // Add elements in node.
        tmp->next = p->next; // Next of current node is next of given node.
        tmp->previous = p; // Previous of current node is given node.
        if(p->next != NULL) p->next->previous = tmp; // If there is next of given node, then this next node of given must points previous to new node.
        p->next = tmp; // Next of given node is new node.
        (*In)->size++; // Increase size.
    }
}

void Insert_List(Info * const In, Node p, TD x, int * const error){ // Insert node in list.

    *error = 0;

    if(p == NULL) Insert_At_Start(In,x,error); // Choose method to insert element in list.
    else Insert_After_List(In,p,x,error);

}

void Delete_List(Info * const In, Node *p, int * const error){ // Delete node from list.
    Node tmp1, tmp2;

    *error = 0;

    if(Empty_List(*In) || (*p) == NULL){ // Check if list is empty or given node exists.
        *error = 1;
        return;
    }

    if((*In)->head == (*p)){ // If given node is first.
        tmp1 = (*p); // Save current node.
        (*p) = (*p)->next; // Go to next node.
        if((*p) != NULL) // If there is next node.
        (*p)->previous = tmp1->previous; // Previous of next node is null.
        (*In)->head = (*p); // Now begin from next node.

    }
    else{
        tmp1 = (*p); // Save current node.
        tmp2 = tmp1->previous; // Save previous node.
        (*p) = (*p)->next; //Go next node.
        tmp2->next = tmp1->next; // Previous node points to next node, as midle deleted.
        if((*p)) // If there is previous node.
            (*p)->previous = tmp2; // Next node must have the previous node.

    }
    
    free(tmp1); // Delete current node.
    (*p) = NULL; // Set it to null.
    (*In)->size--; // Reduce total size of list.
}

void Go_Next_Node_List(Info const In, Node * const p, int * const error){ // Go to next node of given.

    *error = 0;

    if((*p) == NULL){ // Check if given node exists.
        *error = 2;
        return;
    }

    if((*p)->next != NULL){ // Check if there is next node.
        (*p) = (*p)->next; // Go next.
    }
    else{
        *error = 1;
        return;
    }
}

void Go_Previous_List(Info const In, Node * const p, int * const error){ // Go to previous node of given.


    *error = 0;

    if((*p)){ // If node exists.
        if((*p) == (In)->head){ // If given node is first ther is not previous node.
            *error = 1;
            return;
        }
        else{
            (*p) = (*p)->previous; // Go previous node.
        }
    }
    else{
        *error = 2;
        return ;
    }
}

void Go_First_Node_List(Info const In, Node * const p, int * const error){ // Go at the beginign of list.

    *error = 0;

    if(Empty_List(In)){ // Check if list is empty.
        *error = 1;
        return;
    }
    else (*p) = In->head; // Go first node.

}

void Go_Last_Node_List(Info const In, Node * const p, int * const error){ // Go at the end of list.
    Node tmp; // Create an assist node to cross list.

    *p = NULL;


    *error = 0;

    if(Empty_List(In)) { // Check if list is empty.
        *error = 1;
        return;
    }
    tmp = (In)->head; // Begin from start.

    while(tmp){ // Search end of list.

        *p = tmp;
        tmp = tmp->next;
    }

}



