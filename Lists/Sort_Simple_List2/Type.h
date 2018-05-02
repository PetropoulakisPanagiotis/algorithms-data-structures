#ifndef TYPE
#define TYPE

typedef struct TE{
    int x;
}TE;


// Prototypes of functions.//

void Set_Value(TE *EL1, TE EL2);

void Read_Value(TE *EL);

void Write_Value(TE El);

int Equal_Value(TE EL1, TE EL2);

int Min_Value(TE EL1, TE EL2);

#endif
