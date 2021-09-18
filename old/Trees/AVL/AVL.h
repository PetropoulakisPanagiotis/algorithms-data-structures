#ifndef __AVLTREE__
#define __AVLTREE__
#include "TypeAVL.h"

typedef struct AVLNode *AVLN; // Pointer in nodes.

typedef enum{TRUE, FALSE} boolean; // If hight is increased.

typedef enum{LH, EH, RH} producing_r; // Type of node.

void CreateAVL(AVLN *root);

int EmptyAVL(AVLN root);

void RightRotationAVL(AVLN *root, int *error);

void LeftRotationAVL(AVLN *root, int *error);

void RightWeightAVL(AVLN *root, boolean *higher, int *error);

void LeftWeightAVL(AVLN *root, boolean *higher, int *error);

void InsertAVL(AVLN *root, AVLN tmp, TEL element, boolean *higher, int *error);

void PrintAVL(AVLN root);

#endif
