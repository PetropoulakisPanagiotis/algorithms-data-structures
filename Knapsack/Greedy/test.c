#include <stdio.h>
#include <stdlib.h>
#include "knapsack_greedy.h"

int main(void){
    int *weight, *value, *pick; // Weight per element, value(how it is worth), pick(0 or 1): if element has been picked. 
    int size_sack;
    int size_elem; // Total elements.
    int i,sum_w = 0,sum_v = 0; // Sum_w: total weight of elements indise sack, sum_v: total earnings.
    
    printf("Knapsack Greedy\n");
    printf("---------------\n\n");

    printf("Give max size of sack:");
    scanf("%d",&size_sack);

    printf("\nGive size of total elements:");
    scanf("%d",&size_elem);

    // Allocate memory for arrays.//
    
    weight = malloc(size_elem * sizeof(int));
    if(weight == NULL) return 1;

    value = malloc(size_elem * sizeof(int));
    if(value == NULL) return 1;

    pick = malloc(size_elem * sizeof(int));
    if(pick == NULL) return 1;   

    for(i = 0; i < size_elem; i++) pick[i] = 0; // Initial value for pick.

    for(i = 0; i < size_elem; i++){ // Add values for elements.

        printf("Give weight for %d element:", i + 1);
        scanf("%d",&weight[i]);

        printf("\nGive value for %d element:", i + 1);
        scanf("%d",&value[i]);

    } // End for.

    printf("\n");
    
    // Perform knapsack.//
    knapsack_greedy(weight,pick,value,size_sack,size_elem);
    
    printf("Elements inside sack:");
    printf("\n\n");

    // Find elements that exists in sack.//
    for(i = 0; i < size_elem; i++){
    
        if(pick[i] == 1){
            
            sum_w += weight[i];
            sum_v += value[i];

            printf("Element %d is inside with weight %d and value %d\n",i + 1,weight[i],value[i]);
        }
    } // End for.
    
    // Printf results.//

    if(sum_w == 0)
        printf("There aren't elements indise sack!!\n");
    else
        printf("Finally our elements inside sack weight %d and we have earned %d\n",sum_w,sum_v);


    free(weight);
    free(pick);
    free(value);

    return 0;
}

// Editor:
// Panagiotis
// Petropoulakis
