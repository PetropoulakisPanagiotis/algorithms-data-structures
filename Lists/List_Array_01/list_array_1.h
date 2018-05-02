#ifndef LIST_ARRAY_1 // Compile once.
#define LIST _ARRAY_1
#include <stdio.h>
#include "TList_array_1.h"
#define MAX 10 // Max elements of list.

typedef struct list{
    
    TElementList array[MAX]; // Array of list.    
    int elements; // Total elements in list.

}TList; // New name "list".

// Prototypes of functions.//

void Create_List(TList *list_ptr);

void Destroy_List(TList *list_ptr);

int Empty_List(TList list);

int Next_List(TList *list_ptr, int position, int *error);

int Previous_List(TList *list_ptr, int position, int *error);

void Contents_List(TList *list_ptr, int position, TElementList *x, int *error);

void Change_list(TList *list_ptr, int position, TElementList x, int *error);

void Path_List(TList list);

int Go_First_List(TList *list_ptr, int *error);

int Go_Last_List(TList *list_ptr, int *error);

void Add_Element_Next_List(TList *list_ptr, int position, TElementList x, int *error);

void Add_Element_List(TList *list_ptr, int position, TElementList x, int *error);

int Get_Number_Elements(TList list);

int Full_List(TList list);

void Delete_Element_List(TList *list_ptr, int position, int *error);

int Search_Element_List(TList *list_ptr, TElementList x, int *found);

#endif
