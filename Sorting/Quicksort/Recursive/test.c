#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

int main(void){
    int *arr = malloc(5 * sizeof(int));
    int i;

    if(arr == NULL)
        return 1;

    arr[0] = 10;
    arr[1] = 2;
    arr[2] = 1;
    arr[3] = 30;
    arr[4] = 25;

    printf("Quick Sort\n");
    printf("----------\n");

    printf("\nInitial array:");

    for(i = 0; i < 5; i++) printf("%d ",arr[i]);

    printf("\n");

    
    quicksort(arr,0,4,5);

    
    printf("\nFinal array:");

    for(i = 0; i < 5; i++) printf("%d ",arr[i]);

    printf("\n");

    free(arr);

    return 0;
}

