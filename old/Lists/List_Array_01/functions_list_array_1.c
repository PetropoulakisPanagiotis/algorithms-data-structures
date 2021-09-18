#include <stdio.h>
#include <stdlib.h>
#include "list_array_1.h"

void Create_List(TList *list_ptr){ // Create a NULL list.
    
    list_ptr->elements = 0;
}

void Destroy_List(TList *list_ptr){ // Destroy list.
    
    list_ptr->elements = -1;
}

int Empty_List(TList list){ // Check if list is empty.

    // Returns 1 if list is empty, else 0.//

    return(list.elements == 0);
}

int Next_List(TList *list_ptr, int position, int *error){ // Return next position of list.

    if((position < 0) || (position > list_ptr->elements - 2)){ // Check position for errors.
        *error = -1;
        return -1;
    }
    else{

        *error = 0;
        return (++position);
    }
}

int Previous_List(TList *list_ptr, int position, int *error){ // Return previous position of list.

    if((position < 1) || (position > list_ptr->elements - 1)){ // Check position for errors.
        *error = -1;
        return -1;
    }
    else {

        *error = 0;
        return (--position);
    }
}

void Contents_List(TList *list_ptr, int position, TElementList *x, int *error){ // Take an element from list.

    if((position < 0) || (position >= list_ptr->elements)){ // Check position for errors.
        *error = -1;
    }
    else {

        *error = 0;
        Set_Value(x, list_ptr->array[position]); // Save value.
    }
} // Pass *list_ptr, as if not in line Set_Value cant give adress.


void Change_list(TList *list_ptr, int position, TElementList x, int *error){ // Change value in list.


    if((position < 0) || (position >= list_ptr->elements)){ // Check position for errors.
        *error = -1;
    }
    else{
    
        *error = 0;
        Set_Value(&(list_ptr->array[position]), x);         
    }
}

void Path_List(TList list){ // Print list.
    int i;
     
    for(i = 0; i < list.elements; i++){
        printf("%d\n", list.array[i]);
    }
}

int Go_First_List(TList *list_ptr, int *error){ // Go at the beginning of list.

    if(Empty_List(*list_ptr)){ // Check if list is empty.
        *error = -1;
        return -1;
    }

    else {
        
        *error = 0;
        return 0;
    }
}

int Go_Last_List(TList *list_ptr, int *error){ // Go at the end of list.

    if(Empty_List(*list_ptr)){ // Check if list is empty.
        *error = -1;
        return -1;
    }

    else {

        *error = 0;
        return list_ptr->elements - 1;
    }
}

void Add_Element_Next_List(TList *list_ptr, int position, TElementList x,  int *error){ // Add element next of given position.
    int i;
    
    if(list_ptr->elements == MAX) *error = -1; // Cant insert element, list is full.
    
    else{ // List not full.
        
        if(((position < 0) || (position > list_ptr->elements)) && (position != -1)) // Check for position errors.
            *error = -1;
        
        else{
            *error = 0; 
            for(i = list_ptr-> elements - 1; i > position; i--) // Move elements. Begin from end until "position - 1".
                Set_Value(&(list_ptr->array[i + 1]), list_ptr->array[i]);
            Set_Value(&(list_ptr->array[position + 1]), x);
            list_ptr->elements++;
        }
    }
}

void Add_Element_List(TList *list_ptr, int position, TElementList x, int *error){
    int i;

    if(list_ptr->elements == MAX) *error = -1; // Cant insert element, list is full.
    
    else{ // List is not full.
    
        if(((position < 0) || (position > list_ptr->elements)) && (position != 0)) // Check for position errors.
            *error = -1;

        else{ 
            *error = 0;
            for(i = list_ptr->elements - 1; i >= position; i--) // Move elements. Begin from end until "position".
                Set_Value(&(list_ptr->array[i + 1]), list_ptr->array[i]);
            Set_Value(&(list_ptr->array[position]), x);
            list_ptr->elements++;
        }
    }
}

int Full_List(TList list){ // Check if list is full.

    // Returns 1 if list is full, esle 0.

    if(list.elements == MAX);

}

int Get_Number_Elements(TList list){ // Return total elements inside list.

    return(list.elements);

}


void Delete_Element_List(TList *list_ptr, int position, int *error){ // Delete an element from list.
    int i;

    if(Empty_List(*list_ptr)) // Check if list is empty.
        *error = -1;
    
    else{

        if((position < 0) || (position > list_ptr->elements - 1)) // Check for position errors.
            *error = -1;
        else{
            
            *error = 0;
            for(i = position; i < list_ptr->elements - 1; i++) // Move elements to the left.
                Set_Value(&(list_ptr->array[i]), list_ptr->array[i + 1]);

            list_ptr->elements--;
        }
    }

}

int Search_Element_List(TList *list_ptr, TElementList x, int *found){
    TElementList tmp; // Current element we find each loop.
    int pos; // Positon.
    int error; // Check for errors.


    error = 0;
    pos = 0;
    *found = 0;

    while((!(*found)) && (error != -1)){ // Search until we havent found value and dont pass error.

       Contents_List(list_ptr,pos,&tmp,&error);
       
       if(error == -1) // If position is not in list. 
           return -1;
       

       else{
    
            if(tmp == x) // If we find element.
                *found = 1;
    
            else
               pos = Next_List(list_ptr,pos,&error);
       }

    } // End while.

}
