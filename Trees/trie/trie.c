#include "trie.h"

// Trie keeps words. Searching in trie is really fast              //
// Leaf nodes have key == '\0' and a posting list                  //
// Each node in trie has a character, next node(in the same level) //
// and children. Posting list is NULL for non-leafs nodes          //
// Note: Total words ins't the real number of words in trie        //
// Example: totalWords = 2. Given input: "nikos", "nikos".         //
// Trie contains "nikos" only once                                 //

typedef struct trieTree{
    nodeTT head; // First level
    int totalW; // Total words
}trieTree;

typedef struct trieNode{
    char key; 
    nodeTT next, children;
    PL postL;
}trieNode;

// Stack is usefull for delete and print all contents in trie //
// Stack nodes have trieNodes                                 //
// Note: stackL is double linked list                         //
typedef struct stackL{
    nodeSL head, teil;
}stackL;

typedef struct stackNode{
    nodeTT ptrNodeTT;
    nodeSL next, prev;
}stackNode;

// Functions to implement stack behavior(prototypes) //
SL createSL(void);
int destroySL(SL*);
int isEmptySL(SL);
int pushSL(SL,nodeTT);
nodeTT popSL(SL,int*);
int printSL(SL);

// Extra functions to implement trie behavior(prototypes) //
nodeTT keyIsMemberInList(char,nodeTT);
nodeTT insertKeyInList(char,nodeTT,int*);
int insertInPL(nodeTT,int);

// Create and return a trie tree //
// Success: trie tree            //
// Failure: NULL                 //
TT createTT(void){
    TT trieT = NULL;

    // Create TT //
    trieT = malloc(sizeof(trieTree));
    if(trieT == NULL)
        return NULL;

    // Initialize members //
    trieT->head = NULL;
    trieT->totalW = 0;

    return trieT;
}

// Destroy TT                      //
// Destroy nodes and posting lists //
// Success: 0                      //
// Failure: -1                     // 
int destroyTT(TT *trieT){

    // Check parameters //
    if((*trieT) == NULL)
        return -1;

    SL stack; 
    nodeTT currNode, tempNode;
    int status, flag = 0;

    // Perform DFS to delete all nodes //

    stack = createSL();

    // Start from the first level //
    currNode = (*trieT)->head;
    if(currNode == NULL)
        flag = 1;

    while(flag == 0){
        
        status = pushSL(stack,currNode);
        if(status == -1)
            return -1;
                
        // Reach end of word //
        if(status == 1){

            // Find next character //
            while(1){

                // Find next word //
                currNode = popSL(stack,&status);
                if(status == -1)
                    return -1;

                // Empty stack                  //
                // Trie nodes have been deleted //
                if(status == 1){
                    flag = 1;
                    break;
                }

                // Leaf node //
                if(currNode->postL != NULL)
                    destroyPL(&currNode->postL);

                tempNode = currNode;

                // Go to the next node //
                currNode = currNode->next;

                // Delete node //
                free(tempNode);

                // Go to the previous node //
                if(currNode == NULL)
                    continue;
                else
                    break;
            } // End while
        } // Reach end of word
        else
            currNode = currNode->children;
    } // End while
    
    destroySL(&stack);

    free(*trieT);

    *trieT = NULL;

    return 0;
}

// Insert new word in TT //
// Success: 0            //
// Failure: -1           // 
int insertTT(TT trieT, char *word, int id){

    // Check parameters //
    if((trieT == NULL) || (word == NULL) || (id < 0))
        return -1;
    
    int wordLen = strlen(word);
    int i, status;
    
    // Start from the beginning //
    nodeTT currNode = trieT->head, prevNode = currNode;
    nodeTT tempNode;

    for(i = 0; i < wordLen + 1; i++){
 
        // Insert each character in trie //
        tempNode = insertKeyInList(word[i],currNode,&status);
        if(status == -1)
            return -1;
        
        // Head of the first list has changed //
        if(i == 0 && status == 2)
            trieT->head = tempNode;
        else if(status == 2)
            prevNode->children = tempNode;
        
        // Leaf node. Fix posting list //
        if(i == wordLen){
            status = insertInPL(tempNode,id);
            if(status == -1)
                return -1;
        }   

        prevNode = tempNode;
        currNode = tempNode->children;
    } // End for

    trieT->totalW += 1;

    return 0;
}

// Search if given word exists in trie //
// Found: PL of word, 0                //
// Not found, NULL, 1                  //
// Failure: NULL, -1                   //
PL searchTT(TT trieT, char *word, int *status){

    *status = 1;
    
    // Check parameters //
    if((trieT == NULL) || (word == NULL)){
        *status = -1;
        return NULL;
    }

    nodeTT currNode = trieT->head;
    int wordLen = strlen(word);
    int i;
    for(i = 0; i < wordLen + 1; i++){

        currNode = keyIsMemberInList(word[i],currNode);
        // Not found //
        if(currNode == NULL)
            break;

        // Found //
        if(i == wordLen){
            *status = 0;
            return currNode->postL;
        }

        currNode = currNode->children;
    } // End for


    return NULL;
}

// Get total words //
// Success: words  //
// Failure: -1     //
int getTotalWordsTT(TT trieT){

    if(trieT == NULL)
        return -1;

    return trieT->totalW;
}

// Print all words from trie //
// Use stack to perform DFS  //
// Success: 0                //
// Failure: -1               //
int printTT(TT trieT){

    // Check parameters //
    if(trieT == NULL)
        return -1;

    // Empty trie //
    if(trieT->head == NULL)
        return -1;

    SL stack; 
    nodeTT currNode;
    int status, flag = 0;

    stack = createSL();

    // Use DFS to find all words from trie //
    // Start from the first level          //
    currNode = trieT->head;
    while(flag == 0){

        status = pushSL(stack,currNode);
        if(status == -1)
            return -1;
        
        // Reach end of word //
        // Print word        //
        if(status == 1){
            
            status = printSL(stack);
            if(status == -1)
                return -1;
            
            // Find next character //
            while(1){

                // Find next word //
                currNode = popSL(stack,&status);
                if(status == -1)
                    return -1;

                // Empty stack           //
                // Trie has been printed //
                if(status == 1){
                    flag = 1;
                    break;
                }

                // Go to the next character //
                currNode = currNode->next;

                // Go to the previous node //
                if(currNode == NULL)
                    continue;
                else
                    break;
            } // End while
        } // Reach end of word
        else
            currNode = currNode->children;
    } // End while

    destroySL(&stack);

    return 0;
}

// Find if key exists in list  //
// Works with leaf nodes       //
// Found: nodeTT               //
// Not found: NULL             //
// Complexity: O(n)            //
nodeTT keyIsMemberInList(char key, nodeTT headNode){
    nodeTT currNode = headNode;

    // Find key. List is sorted //
    while(currNode != NULL){
        if(key == currNode->key)
            return currNode;

        if(key < currNode->key)
            break;

        currNode = currNode->next;
    } // End while

    return NULL;
}

// Insert given key in list                               //
// Node found: 0, nodeTT                                  //
// New node created: 1, nodeTT(newNode)                   //
// Head of given list must changed: 2, nodeTT(newNode)    //
// Error: -1, NULL                                        //
// Complexity: O(n)                                       //
nodeTT insertKeyInList(char key, nodeTT headNode, int *status){
    nodeTT currNode = headNode;
    nodeTT prevNode = headNode;

    *status = 0;
    
    // Find position //
    while(currNode != NULL){
        
        // Character found //
        if(key == currNode->key){
            *status = 0;
            return currNode;
        }

        // Character not found //
        if(key < currNode->key)
            break;

        prevNode = currNode;
        currNode = currNode->next;
    } // End for

    nodeTT newNode = NULL;
    
    // Create new node //
    newNode = malloc(sizeof(trieNode));
    if(newNode == NULL){
        *status = -1;
        return NULL;   
    }

    // Initialize members of newNode //
    newNode->key = key;
    newNode->next = NULL;
    newNode->children = NULL;
    newNode->postL = NULL;

    // Empty list. Head node must changed //
    if(headNode == NULL){
        *status = 2;
        return newNode;
    }

    // Insert at start //
    if(currNode == headNode && currNode != NULL){
        newNode->next = headNode;
        
         *status = 2;
    }
    else{ 
        prevNode->next = newNode;
        newNode->next = currNode;
        *status = 1;
    }

    return newNode;
}

// Insert content in posting list(in leafs) //
// Success: 0                               //
// Failure: -1                              //
int  insertInPL(nodeTT leafNode, int id){
    
    if(leafNode == NULL)
        return -1;

    // Posting list han't been created //
    if(leafNode->postL == NULL){
        leafNode->postL = createPL();
    }

    return insertPL(leafNode->postL,id);
}

///////////
// STACK //
///////////

// Create and return stack //
// Success: stack          //
// Failure: NULL           //
SL createSL(void){
    SL stack;

    // Create stack //
    stack = malloc(sizeof(stackL));
    if(stack == NULL)
        return NULL;

    // Initialize members of stack //
    stack->head = NULL;
    stack->teil = NULL;

    return stack;
}

// Destory stack    //
// Success: 0       //
// Failure: 1       //
// Complexity: O(N) //
int destroySL(SL *stack){

    // Check parameters //
    if(*stack == NULL)
        return 0;

    nodeSL currNode = (*stack)->head;

    // Delete all nodes //
    while((*stack)->head != NULL){
        
        (*stack)->head = currNode->next;
        free(currNode);

        currNode = (*stack)->head;
    } // End while

    free(*stack);

    *stack = NULL;

    return 0;
}

// Check if stack is empty //
// Empty: 0                //
// Not empty: 1            //
// Failure: -1             //
int isEmptySL(SL stack){

    if(stack == NULL)
        return -1;

    if(stack->head == NULL)
        return 0;
    else 
        return 1;
}

// Push in SL           //
// Success: 0           //
// Reach end of word: 1 //
// Failure: -1          //
// Complexity: O(1)     //
int pushSL(SL stack, nodeTT currNode){
    
    // Check parameters //
    if((stack == NULL))
        return -1;

    // Reach end of word //
    if((stack->head != NULL) && (stack->teil->ptrNodeTT->key == '\0'))
        return 1;

    // Invalid node //
    if(currNode == NULL)
        return -1;

    nodeSL newNode;

    // Create new stack node //
    newNode = malloc(sizeof(stackNode));
    if(newNode == NULL)
        return -1;

    // Initialize members of new node //
    newNode->ptrNodeTT = currNode;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Fix members of stack //
    if(stack->teil != NULL){
        stack->teil->next = newNode;
        newNode->prev = stack->teil;
    }

    stack->teil = newNode;

    if(stack->head == NULL)
        stack->head = newNode;
    
    return 0;
}

// Pop items from SL    //
// Success: nodeTT, 0   //
// Empty stack: NULL, 1 //
// Failure: NULL, -1    //
// Complexity: O(1)     //
nodeTT popSL(SL stack, int *status){

    *status = 0;

    // Check parameters //
    if(stack == NULL){
        *status = -1;
        return NULL;
    }

    // Empty stack //
    if((stack->head == NULL)){
        *status = 1;
        return NULL;
    }

    nodeSL tempNode = stack->teil;
    nodeTT tempTrieNode = tempNode->ptrNodeTT; // Keep trie node

    // Fix stack //
    if(tempNode->prev != NULL){
        tempNode->prev->next = NULL;
        stack->teil = tempNode->prev;
    }
    else{
        stack->head = NULL;
        stack->teil = NULL;
    }

    // Delete node //
    free(tempNode);
    
    return tempTrieNode;
}

// Print stack. Stack contains characters    //
// Result will be a word with it's document  //
// frequency                                 //
// Success: 0                                //
// Failure: -1                               //
int printSL(SL stack){

    // Check parameters //
    if(stack == NULL)
        return -1;

    // Empty stack //
    if(stack->head == NULL)
        return -1;

    // Word hasn't been completed //
    if(stack->teil->ptrNodeTT->key != '\0')
        return -1;

    nodeSL tempNode = stack->head;
    int status, docFreq;

    docFreq = getDocFrequencyPL(stack->teil->ptrNodeTT->postL);
    if(docFreq == -1)
        return -1;
    
    while(tempNode != NULL){

        if(tempNode != stack->teil)
            printf("%c",tempNode->ptrNodeTT->key);
        else
            printf(" %d\n",docFreq);

        tempNode = tempNode->next;
    } // End while

    return 0;
}

// Sdi1500129
// Petropoulakis Panagiotis
