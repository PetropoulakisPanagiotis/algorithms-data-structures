#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*,int*);

void bubble_sort(int*,int);

int main(void){
    int *array = NULL;
    int size = 10; // Size of array.
    int element, i; 

    array = malloc(size * sizeof(int)); // Allocate memory.

    srand(time(NULL)); // Seed value(current time).

    for(i = 0; i < size; i++) // Add random numbers in array. Range[0 - 100].
        array[i] = (rand() % 100) + 1;

    printf("\nSize of array: %d.Elements before bubble sorting: \n",size); 
    
    for(i = 0; i < size; i++)
      printf("%d ",array[i]);
    
    printf("\n");

    bubble_sort(array,size);

    printf("\nElements after bubble sorting: \n",size); 
    
    for(i = 0; i < size; i++)
        printf("%d ",array[i]);
    
    printf("\n");

    free(array);

    return 0;
}

void swap(int *a, int *b){  
    int temp = *a;
        
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int size){ // O(n^2).
    int i,j;

    for(i = 0; i < size - 1; i ++)
        for(j = 0; j < size - 1 - i; j++)
            if(array[j] > array[j + 1])
                swap(&array[j],&array[j + 1]);
}
// Editor: Panagiotis Petropoulakis.
