#ifndef __LINKEDLIST__
#define __LINKEDLIST__

// Declerations //
typedef struct linkedList* linkedListPtr; 
typedef struct node* nodePtr; 

// Definitions // 
typedef struct linkedList{
    int size;
    nodePtr head;
} linkedList;

typedef struct node{
    int value; // Element
    nodePtr nextNode; // Next node
}node;

// Functions //

linkedListPtr createLinkedList(void);
int destroyLinkedList(linkedListPtr*);

nodePtr createNode(int value);

int insertStartLinkedList(linkedListPtr, int value);
int insertEndLinkedList(linkedListPtr, int value);

int insertMidlePointersLinkedList(linkedListPtr, int value);
int insertMidleSizeLinkedList(linkedListPtr, int value);

int existsValueLinkedList(linkedListPtr, int value);
int deleteValueLinkedList(linkedListPtr, int value);

// Merge sort //
void sortLinkedList(nodePtr* listPtr);
void divideLinkedList(nodePtr initialList, nodePtr* aSubList, nodePtr* bSubList);
nodePtr mergeLinkedList(nodePtr aSubList, nodePtr bSubList);

void printLinkedList(linkedListPtr);
#endif
