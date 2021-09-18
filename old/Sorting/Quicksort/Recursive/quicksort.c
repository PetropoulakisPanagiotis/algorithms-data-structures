#include <stdio.h>
#include "quicksort.h"

// Recursive quicksort.//
// O(nlogn).//
// Left begins with the value of 0 and right with the value of size - 1.//
// First call:array with 5 elements-> size = 5, left = 0 and right = 4.//

int quicksort(int *const arr, int const left, int const right, int const size){
    int pos_pivot; // Position of pivot.
    static int error = 0;

    if((error == 0) && ((arr == NULL) || (right >= size) || (left < 0) || (right < 0) || (size <= 0))) // Check for invalid parameters.
        return 1;

    if(error == 0)
        error = 1;

    // Terminate condition: array should have two or more elements.//
    if(left < right){   
        
        pos_pivot = partition(arr,left,right,size); 
        quicksort(arr,left,pos_pivot - 1,size);
        quicksort(arr,pos_pivot + 1,right,size);
    }
    
    return 0;
}

int partition(int *const arr, int const left, int const right, int const size){ // O(n).
    
    if((arr == NULL) || (left < 0) || (right < 0) || (right >= size) || (size <= 0))
        return 1;
    
    int pos_pivot = left; // Position of pivot.
    int val_pivot = arr[left]; // Value of pivot.
    int i;

    // Fix array, so as left of pivot there are numbers less or equal than pivot and right of pivot//
    // there are numbers greather than pivot.//

    for(i = left + 1; i < right + 1; i++){  
        
        if(arr[i] <= val_pivot){
            
            pos_pivot += 1;
            
            swap(&arr[i],&arr[pos_pivot]);
        }
    } // End for.
    
    swap(&arr[left],&arr[pos_pivot]); 

    return pos_pivot; 
}

int swap(int *const x, int *const y){ // Swap given numbers.
    
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
