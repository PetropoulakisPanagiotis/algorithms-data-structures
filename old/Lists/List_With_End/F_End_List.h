#ifndef __ENDLIST__
#define __ENDLIST__
#include "Type_List.h"

typedef struct Info_Node *Info;
typedef struct Each_Node *Node;

// Prototypes of functions.//

Info Create_List(void);

void Destroy_List(Info * In);

int Empty_List(Info );

void Get_Value_List(Node , TL *, int * const );

void Change_Node_List(Node , TL , int *const );

void Print_List(const Info , int * const );

void Go_First_Node_List(Info const , Node * const , int * const );

void Go_Last_Node_List(Info const, Node * const , int * const );

void Insert_At_Start_List(Info *, TL , int * const );

void Insert_Next_List(Info *, Node , TL , int * const );

void Insert_List(Info *, Node , TL , int *);

#endif
