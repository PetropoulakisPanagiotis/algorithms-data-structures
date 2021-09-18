#include <stdio.h>
#include "Tail.h"


void Create_Tail(Tail *T){ // Create empty tail.
    
    T->front = 0;
    T->rear = 0;
    T->counter = 0;
}

int Emtpy_Tail(Tail T){ // Check if tail is empty.
    
    return(T.counter == 0);
}


int Full_Tail(Tail T){ // Check if tail if full.

    return(T.counter == MAX);
}

void Add_Tail(Tail *T, int x){ // Add element into tail.

    if(Full_Tail(*T)){
        printf("Full Tail.");
    }
    else{

        T->Arr[T->rear] = x; // Add element.
        T->rear = (T->rear + 1) % MAX; // Set rear.
        T->counter++;
    }
}

void Remove_Tail(Tail *T){ // Remove element from tail.

    if(Emtpy_Tail(*T)){
        printf("Tail is empty.");
    }
    else{

        printf("%d\n",T->Arr[T->front]);
        T->front = (T->front + 1) % MAX;
        
    }
    
    T->counter--;

}
