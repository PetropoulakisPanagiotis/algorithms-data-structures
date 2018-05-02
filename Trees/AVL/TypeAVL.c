#include <stdio.h>
#include <string.h>
#include "TypeAVL.h"

void SetValueName(TEL *x, TEL y){ // Set data.

	strcpy(x->name, y.name);
}

int ReadValueName(FILE *in, TEL *x){ // Read data.
	int error;
	
    fprintf(in,"\n give name.");

	error = fscanf(in, "%s", x->name);

	return error;
}


int WriteValueName(FILE *in, TEL x){ // Print data.
	int error = 0;

	error = fprintf(in, "%s\n", x.name);
	
	return error;
}


int LessThanName(TEL x, TEL y){ // Check if first name is less than second name.
	int result;

	result = strcmp(x.name, y.name); // Compare two names.

	if (result < 0) return 1;

	else return 0;
}

int EqualName(TEL x, TEL y){ // Check if given names are the same.
	int result;

	result = strcmp(x.name, y.name); // Compare two names.

	if (result == 0) return 1;

	else return 0;
}
