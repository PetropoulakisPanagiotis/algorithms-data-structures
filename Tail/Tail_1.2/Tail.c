#include "Tail.h"

void tail_create(s_tail *tail_ptr){ // Create tail-NULL.
    
    tail_ptr->front = 0;
    tail_ptr->back = 0;
    tail_ptr->count = 0;
}

int tail_empty(s_tail tail){ // Is tail empty.

    // Returns 1 if tail is empty else 0.//

    return(tail.count == 0);
}

int tail_full(s_tail tail){ // Is tail full.

    // Return 1 if tail is full else 0.//
    
    return(tail.count == MAX);
}

int tail_add(s_tail *tail_ptr, type x){ // Add elements in tail.

    if(tail_full(*tail_ptr)) return 0;

    else{
        set_value(&(tail_ptr->arr[tail_ptr->back]),x); // Save element in tail.
        tail_ptr->back = (tail_ptr->back + 1 ) % MAX;
        tail_ptr->count++; // We put element.

    }
    return 1;

}

int tail_take(s_tail *tail_ptr, type *x){
    
    if(tail_empty(*tail_ptr)) return 0;

    else{
        
        set_value(x,tail_ptr->arr[tail_ptr->front]);
        tail_ptr->front = (tail_ptr->front + 1) % MAX;
        tail_ptr->count--; // We take element.
    }
    return  1;

}




void set_value(type *x_ptr, type y){ // Save element from element y.
    
    *x_ptr = y;
    
}

