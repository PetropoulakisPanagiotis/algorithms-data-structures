#include <stdio.h>
#include <stdlib.h>
#include "partition.h"

int main(void){
    int *arr; 
    int i;

    arr = malloc(5 * sizeof(int)); // Allocate memory for array.

    if(arr == NULL)
        return 1;

    // Add numbers.//
    arr[0] = 5;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 6;
    arr[4] = 3;

    printf("Initial values");
    printf("\n");

    for(i = 0; i < 5; i++)
        printf("%d ",arr[i]);

    printf("\n");
    
    int pos_p = partition(arr,5);
    
    printf("Position of pivot: %d  ",pos_p);
    
    printf("\n");

    printf("Final array");
    printf("\n");

    for(i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    free(arr);
    
    return 0;
}

// Editor:
// Panagiotis
// Petropoulakis
