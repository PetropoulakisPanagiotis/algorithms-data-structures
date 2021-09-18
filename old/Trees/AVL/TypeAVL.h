#ifndef __TYPEAVLTREE__
#define __TYPEAVLTREE__


typedef struct TEl { // Elements in tree.
	char name[20]; // Contains string.

}TEL;

// -> Use data.//

void SetValueName(TEL *x, TEL y);

int ReadValueName(FILE *in, TEL *x);

int WriteValueName(FILE *in, TEL x);

// ->  Calculations.//

int LessThanName(TEL x, TEL y);

int EqualName(TEL x, TEL y);

#endif
