#include <stdio.h>
#include "quicksort.h"

// 3 arrays are parallel. Arr is sorted and arr1,arr2 should follow new arrangement.//

int quicksort(int *const arr,int *const arr1,int *const arr2, int const left, int const right, int const size){
    int pos_pivot;
    static int error = 0;

    if((error == 0) && ((arr == NULL) || (arr1 == NULL) || (arr2 == NULL) || (left < 0) || (right < 0) || (right >= size) || (size <= 0)))
        return 1;

    if(error == 0)
        error = 1;
    
    // Terminate condition: current array should have two or more elements.//

    if(left < right){
        
        pos_pivot = partition(arr,arr1,arr2,left,right,size);
        quicksort(arr,arr1,arr2,left,pos_pivot- 1,size);
        quicksort(arr,arr1,arr2,pos_pivot + 1,right,size);
    }

    return 0;
}

int partition(int *const arr,int *const arr1, int *const arr2, int const left, int const right, int const size){
    
    if((arr == NULL) || (arr1 == NULL) || (arr2 == NULL) || (left < 0) || (right >= size) || (right < 0) || (size <= 0))
        return -1;
    
    int pos_pivot = left; // Position of pivot - initial.
    int val_pivot = arr[left]; // Value of pivot.
    int i;

    // Left elements of pivot are less or equal than pivot and right elements of pivot are greater than pivot.//

    for(i = left + 1; i < right + 1; i++){
        
        if(arr[i] <= val_pivot){
         
            pos_pivot += 1;
            
            swap(&arr[i],&arr[pos_pivot]);
            swap(&arr1[i],&arr1[pos_pivot]); // Fix parallel arrays.
            swap(&arr2[i],&arr2[pos_pivot]);
        }
    } // End for.
    
    swap(&arr[left],&arr[pos_pivot]); 
    swap(&arr1[left],&arr1[pos_pivot]); 
    swap(&arr2[left],&arr2[pos_pivot]); 

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
