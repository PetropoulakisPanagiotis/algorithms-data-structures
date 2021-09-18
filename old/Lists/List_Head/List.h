#ifndef __LIST__
#define __LIST__
#include "Type_List.h" // Include type of list.

typedef struct Info_List* Info_Ptr; // Create "* Info_Ptr" points in Info_List.

typedef struct Node_List* Go_Next; // Create "* Go_Next" points in Node_List.

// Prototypes of functions .//

Info_Ptr List_Create(void);

void List_Destroy(Info_Ptr *);

int List_Empty(Info_Ptr );

void Print_List(const Info_Ptr , int * const );

void Get_Element_List(const Go_Next , T_List * const ,  int * const );

void Change_Element_List(const Go_Next *, T_List  , int * const );

void Insert_Node_List(Info_Ptr * const , Go_Next , T_List , int * const);

void Delete_Node_List(Info_Ptr * const , Go_Next , int  * const );

void Next_Node_List(Go_Next * const p, int * const error);

void Previous_Node_List(const Info_Ptr , Go_Next * const, int * const );

void Go_First_Node_List(Info_Ptr const , Go_Next * const , int * const );

void Go_Last_Node_List(Info_Ptr const , Go_Next * const , int * const );


#endif
