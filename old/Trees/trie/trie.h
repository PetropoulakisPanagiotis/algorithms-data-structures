#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../postingList/postingList.h"

typedef struct trieTree *TT;
typedef struct trieNode *nodeTT;

typedef struct stackL *SL;
typedef struct stackNode *nodeSL;

// Create and destroy TT stracture //
TT createTT(void);
int destroyTT(TT*);

// Insert new word in TT stracture //
int insertTT(TT,char*,int);

// Search given word //
// Get posting list  //
// of word           //
PL searchTT(TT,char*,int*);

// Get total words //
int getTotalWordsTT(TT);

// Print all words from TT //
int printTT(TT);

// Sdi1500129
// Petropoulakis Panagiotis
