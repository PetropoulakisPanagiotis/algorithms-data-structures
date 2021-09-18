#ifndef __TAIL__
#define __TAIL__

#define MAX 5 // Max elements of tail.
#include <stdio.h>

typedef struct Tail_Node{ // Node of tail.
    int Arr[MAX]; // Array of elements.
    int front;
    int rear;
    int logic; // Logical variable.

}Tail;

void Create_Tail(Tail *T);

int Emtpy_Tail(Tail T);

int Emtpy_Tail(Tail T);

void Add_Tail(Tail *T, int x);

void Remove_Tail(Tail *T);

#endif



