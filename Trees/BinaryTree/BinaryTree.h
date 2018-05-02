#ifndef __BINARYTREE__
#define __BINARYREEE__
#include "TypeBinaryTree.h"

typedef struct InfoBinaryTree * InfoBT; // Pointer in info node for binary tree.

typedef struct NodeTree * NodeT; // Pointer in every root in binary tree.

void CreateBTree(InfoBT *Tree, int * const error);

void DestroyBTree(InfoBT *Tree, int * const error);

void DeleteNodesBTree(NodeT tmp);

int EmptyBTree(InfoBT Tree, int * const error);

void InsertBTree(InfoBT *Tree, TEL elem, int * const error);

void InBTree(NodeT *tmp, TEL elem, int * const error);

void PrintBTree(InfoBT Tree, int * const error);

void PBTree(NodeT tmp);

NodeT SearchBTree(InfoBT Tree, TEL element, int * const found, int * const error);

NodeT SBTree(NodeT tmp, TEL element);

NodeT SearchNoRecursionBTree(InfoBT Tree, TEL element, int * const found, int * const error);

void InsertNoRecursionBTree(InfoBT Tree, TEL element, int * const error);

NodeT FindFatherBT(InfoBT Tree, TEL element, int * const found);

NodeT FatherBTree(InfoBT Tree, TEL element, int * const found);

void DeleteNodeBTree(InfoBT Tree, TEL element, int * const error);

NodeT FindNextBT(NodeT tmp);

void PrintNodeBTree(NodeT tmp, int * const error);
// Errors.//

// Error = 1 -> Invalid info node.
// Error = 2 -> Empty tree.
// Error = 3 -> Node already exists.
// Error = 4 -> Cant print node.
// Error = 5 -> Already exists.
// Error = 6 -> Cant find node.
#endif
