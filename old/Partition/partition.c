#include <stdio.h>
#include "partition.h"

// By default pivot is first element of array.//

int partition(int *const arr, int const size){
    
    if(arr == NULL)
        return -1;
    
    int pos_pivot = 0; // Position of pivot.
    int val_pivot = arr[0]; // Value of pivot.
    int i;

    for(i = 1; i < size; i++){
        
        if(arr[i] <= val_pivot){
         
            pos_pivot += 1;
            
            swap(&arr[i],&arr[pos_pivot]);
        }
    } // End for.
    
    swap(&arr[0],&arr[pos_pivot]); 

    return pos_pivot; 
}

int swap(int *const x, int *const y){
    
    if(*x == *y) // Same value. Swap is not necessary.
        return 1;

    int temp = *x; // Keep value.

    *x = *y;
    *y = temp;

    return 0;
}

// Editor: 
// Panagiotis
// Petropoulakis
