#ifndef __LIST__
#define __LIST__

#include <stdio.h>
#include "Type.h"

typedef struct Info_Node *In;

typedef struct Each_Node *Node;

// Prototypeds of functions.//

void Create_List(In *I);

void Destroy_List(In *I);

int Empty_List(In I);

void Element_List(Node N);

void Change_Node_List(Node N, TE elm);

void Print_List(In I);

void Insert_List(In I, Node tmp, TE elm);

void Insert_At_Start_List(In I, TE elm);

void Insert_After_Node_List(In I, Node tmp, TE elm);

Node Next_Node_List(Node tmp);

Node Previous_Node_List(In I, Node tmp);

Node First_Node_List(In I);

Node Last_Node_List(In I);

void Delete_Node_List(In I, Node *tmp);

int Print_Size_List(In I);

void Search_List(In I, Node *tmp, TE elem, int * found);

#endif
