#ifndef __DLIST__
#define __DLIST__
#include "Type_D_List.h"

typedef struct Info_Node *Info; // Pointer to infonode.

typedef struct Node_D *Node; // Pointer to node.

Info Create_List(void);

void Destroy_List(Info *);

int Empty_List(Info );

void Element_List(Node , TD * , int * const );

void Change_List(Node *, TD , int * const );

void Print_List(Info , int * const );

void Insert_At_Start(Info *  const , TD , int * const );

void Insert_After_List(Info  * const , Node , TD , int * const );

void Insert_List(Info  * const , Node , TD , int * const );

void Delete_List(Info * const , Node *, int * const );

void Go_Next_Node_List(Info const , Node * const , int * const );

void Go_Previous_List(Info const , Node * const , int * const );

void Go_First_Node_List(Info const , Node * const , int * const );

void Go_Last_Node_List(Info const , Node * const , int * const );
#endif
