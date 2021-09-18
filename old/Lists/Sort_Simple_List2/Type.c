#include <stdio.h>
#include "Type.h"


void Set_Value(TE *EL1, TE EL2){
    EL1->x = EL2.x;
}

void Read_Value(TE *EL){

    scanf("%d",&EL->x);
}

void Write_Value(TE EL){

    printf(" %d->",EL.x);
}

int Equal_Value(TE EL1, TE EL2){

    return(EL1.x == EL2.x);
}

int Min_Value(TE EL1, TE EL2){

    return(EL1.x <= EL2.x);
}
