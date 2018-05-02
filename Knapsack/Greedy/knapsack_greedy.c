#include <stdio.h>
#include <stdlib.h>
#include "knapsack_greedy.h"
#include "quicksort.h"

int knapsack_greedy(int *const weight, int *const pick, int *const value, int size, int const length){
    int *arr = malloc(length * sizeof(int));
    int i;
    
    if((arr == NULL) || (weight == NULL) || (pick == NULL) || (value == NULL)) return 1;
    
    if((size <= 0) || (length <= 0)) return 1;

    for(i = 0; i < length; i++) arr[i] = value[i] / weight[i];

    // Sort arr and weight/value should be fixed.//

    my_sort(arr,weight,value,length);

    // Pick biggest element from arr.//

    i = 0;
    while(1){
        
        if(weight[i] <= size){ // Element can be inserted into sack.

            pick[i] = 1; // Element has been selected.
            size = size - arr[i]; // Increase size of sack.
        }

        else break;
        
        i++;
    } // End while.

    free(arr);

    return 0;
}

void my_sort(int *const arr, int *const weight, int *const value, int const length){

    // Sort arr using quicksort(+ weight/value).//

    quicksort(arr,weight,value,0,length - 1,length);
}

// Editor:
// Panagiotis
// Petropoulakis
