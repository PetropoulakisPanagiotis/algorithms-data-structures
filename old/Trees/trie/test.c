#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(void){
    TT trieT;
    trieT = createTT();
     
    insertTT(trieT,"pen",1);
    insertTT(trieT,"pen",1);
     
    insertTT(trieT,"pen",2);

    insertTT(trieT,"pena",2);
    insertTT(trieT,"pe",2);
    insertTT(trieT,"nikos",2);
    insertTT(trieT,"nina",2);
    insertTT(trieT,"manolis",2);
    insertTT(trieT,"manoli",2);
    insertTT(trieT,"manos",2);
    insertTT(trieT,"ma",2);
    insertTT(trieT,"mitropos",2);
    insertTT(trieT,"teratp",2);
    insertTT(trieT,"sadsadsda",2);
    insertTT(trieT,"sasda",2);
    insertTT(trieT,"sadsda",2);
    insertTT(trieT,"asa-rwrw",2);
    insertTT(trieT,"asa-r--wrw",2);
    
    printf("%d\n",getTotalWordsTT(trieT));

    printTT(trieT);

    destroyTT(&trieT);

    return 0;
}

// Sdi1500129
// Petropoulakis Panagiotis
