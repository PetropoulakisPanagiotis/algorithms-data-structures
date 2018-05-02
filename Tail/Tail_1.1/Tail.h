#ifndef Tail_1
#define Tail_1

#define MAX 10 // Max elements of tail.

typedef int type;

typedef struct{
    int front;
    int back;
    int count;
    type arr[MAX];
}s_tail;

void tail_create(s_tail *);

int tail_empty(s_tail );

int tail_full(s_tail );


int tail_add(s_tail *, type );

int tail_take(s_tail *, type *);

void set_value(type *, type );

#endif 
