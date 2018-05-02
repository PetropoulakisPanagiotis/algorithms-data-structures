#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

typedef struct InfoBinaryTree{ // Info node of binary tree.
    int sizet; // Size of tree - total roots.
    NodeT Head; // Points in main root.

}InfoBinaryTree;

typedef struct NodeTree{ // Each root.
    TEL data; // Elements in root.
    NodeT leftk; // Left kid of root.
    NodeT rightk; // Right kid of root.

}NodeTree;

void CreateBTree(InfoBT *Tree, int * const error){ // Create info node for binary tree. And empty tree.
    
    *error = 0;

    if((*Tree) != NULL){ // Cant use an no empty pointer to info node.
        *error = 1;
        return;
    }
    
    (*Tree) = malloc(sizeof(InfoBinaryTree)); // Create info node.
    if((*Tree) == NULL) exit(-1);

    (*Tree)->sizet = 0;
    (*Tree)->Head = NULL; // Begin with empty tree.
}

void DestroyBTree(InfoBT *Tree, int * const error){ // Destroy info node and all roots of tree.

    *error = 0;

    if((*Tree) == NULL){ // Invalid info node.
        *error = 1;
        return;
    }

    if(EmptyBTree((*Tree),error)){ // Empty tree.
        *error = 2;
        return;
    }

    // Delete all roots of tree.//

    DeleteNodesBTree((*Tree)->Head); // Begin from main root.

    // Unset info node.//

    (*Tree)->sizet = 0;
    
    free((*Tree)); // Delete info node.
    (*Tree) = NULL;
}

void DeleteNodesBTree(NodeT tmp){ // Delete all nodes from tree.
    NodeT assist; // Assist: Go next node.

    if(tmp == NULL) return; // Terminate contition. Go outside tree.

    DeleteNodesBTree(tmp->leftk); // Go to left kids.

    // Delete current root.//

    assist = tmp;
    tmp = tmp->rightk; // Go right kid. 
    free(assist);

    DeleteNodesBTree(tmp); // Go right kids.
}

int EmptyBTree(InfoBT Tree, int * const error){ // Check if tree is empty.

    // Returns 1 if tree is empty, else 0.//
   
    *error = 0;
    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return -1;
    }

    return(Tree->Head == NULL);
}

void InsertBTree(InfoBT *Tree, TEL elem, int * const error){ // Insert element in tree.

    *error = 0;

    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return;
    }

    // Add new element in tree.//

    InBTree(&((*Tree)->Head),elem,error);

    if(*error == 0) (*Tree)->sizet++; // Increase size of tree.
}

void InBTree(NodeT *tmp, TEL elem, int * const error){

    if((*tmp) == NULL){  // Terminate condition - Insert node.
        
        (*tmp) = malloc(sizeof(NodeTree)); // Create new node.
        if((*tmp) == NULL) exit(-1);

        SetValueName(&((*tmp)->data),elem); // Add data in node.

        (*tmp)->rightk = NULL;
        (*tmp)->leftk = NULL;
    } // End of insert node.
    
    else if (LessThanName(elem,(*tmp)->data)) InBTree(&(*tmp)->leftk,elem,error); // Go left kid.

    else if (LessThanName((*tmp)->data,elem)) InBTree(&(*tmp)->rightk,elem,error); // Go right kide.

    else *error = 3; // Already exists.
}

void PrintBTree(InfoBT Tree, int * const error){ // Print tree.
    
    *error = 0;

    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return;
    }
    
    if(EmptyBTree(Tree,error)){ // Empty tree.
        *error = 2;
        return;
    }

    PBTree(Tree->Head); // Print all nodes.
}

void PBTree(NodeT tmp){ // Print binary tree.

        if(tmp == NULL) return; // Terminate condition.

        else{

            PBTree(tmp->leftk); // Go left.

            // Print current root.//

            WriteValueName(stdout,tmp->data);

            PBTree(tmp->rightk); // Go right.
        }
}

NodeT SearchBTree(InfoBT Tree, TEL element, int * const found, int * const error){ // Search an node with specific data.
    NodeT assist = NULL; // Assist: Node that contains searching data.
    *found = 0;
    *error = 0;

    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return;
    }

    if(EmptyBTree(Tree,error)){ // Empty tree.
        *error = 2;
        return;
    }
    
    assist = SBTree(Tree->Head,element); // Search all tree.

    // Set found.//

    if(assist != NULL) *found = 1;
    else *found = 0;
    
    return assist; // Return node.
}

NodeT SBTree(NodeT tmp, TEL element){ // Help function to find a node in tree.

    if(tmp == NULL) return NULL; // Not found, returns NULL node.

    if(LessThanName(element,tmp->data)) SBTree(tmp->leftk,element); // Go left.

    else if(LessThanName(tmp->data,element)) SBTree(tmp->rightk,element); // Go right.

    else return tmp; // Eqaul - take node.

}

NodeT SearchNoRecursionBTree(InfoBT Tree, TEL element, int * const found, int * const error){ // Search element without recursion.
    NodeT current,assist = NULL; // Current: Current node in tree, so as cross tree. Assist: Pointer in searching node.

    *found = 0;
    *error = 0;

    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return;
    }

    if(EmptyBTree(Tree,error)){ // Empty tree.
        *error = 2;
        return;
    }

    // Start searching.//

    current = Tree->Head; // Start from main root.

    while(current){ // Search until face NULL.

        if(EqualName(element,current->data)){ // Equal.
            *found = 1;
            assist = current;
            break;
        }

        else if(LessThanName(element,current->data)) current = current->leftk;

        else current = current->rightk;

    } // End while.

    return assist;
}

void InsertNoRecursionBTree(InfoBT Tree, TEL element, int * const error){ // Insert element in tree.
    NodeT father,new = NULL; // Father: Is father of new node. New: Is new node in tree. 
    int found;

    *error = 0;

    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return;
    }

    father = FindFatherBT(Tree,element,&found); // Find father.

    if(found){
        *error = 5;
        return;
    }


    new = malloc(sizeof(NodeTree)); // Create node.
    if(new == NULL) exit(-1);

    SetValueName(&(new->data),element);
    new->leftk = NULL;
    new->rightk = NULL;

    if(father == NULL) Tree->Head = new; // Only node.

    else{ // Fix father.

        if(LessThanName(element,father->data)) father->leftk = new;
        else father->rightk = new;

    }
}

NodeT FindFatherBT(InfoBT Tree, TEL element, int * const found){ // Find father of given element.
    NodeT tmp,father = NULL; // Tmp: Current node. Father: Father of given node.

    // This function used for insertion. Not find real father - but hypothetical father.//
    
    *found = 0;

    tmp = Tree->Head; // Start from the main node.

    while((*found == 0) && (tmp != NULL)){
    
        father = tmp;

        if(EqualName(tmp->data,element)){ // Equal.
            *found = 1;
            father = NULL;
        }

        else if(LessThanName(element,tmp->data)) tmp = tmp->leftk; // Go left.

        else tmp = tmp->rightk; // Go right.

    } // End while.

    return father;
}

NodeT FatherBTree(InfoBT Tree, TEL element, int * const found){ // Find real father.
    NodeT tmp; // Tmp: Pointer to father.
 
    *found = 0;

    tmp = Tree->Head; // Go to main node.

    if(EqualName(tmp->data,element)) return NULL; // Has no fahter.

    while((tmp != NULL)){

        if(tmp->rightk != NULL){ // Find father.
            if(EqualName(tmp->rightk->data,element)){
                *found = 1;
                break;
            }
        }

        if(tmp->leftk != NULL){ // Find father.
            if(EqualName(tmp->leftk->data,element)){
                *found = 1;
                break;
            }
        }

        if(LessThanName(element,tmp->data)) tmp = tmp->leftk; // Go left.

        else tmp = tmp->rightk; // Go right.
    } // End while.

    
    return tmp;
}
void DeleteNodeBTree(InfoBT Tree, TEL element, int * const error){ //   Delete given node.
    NodeT delete,father,next; // Delete : Is node that should remove. Father: Father of deleting node. Next: Next of deleting node.
    int found;
    
    if(Tree == NULL){ // Invalid info node.
        *error = 1;
        return;
    }

    if(EmptyBTree(Tree,error)){ // Empty tree.
        *error = 2;
        return;
    }

    delete = SearchBTree(Tree,element,&found,error);
    
    if(found == 0){ // Cant find node.
        *error = 6;
        return;
    }

    father = FatherBTree(Tree,element,&found);

    if((delete->leftk == NULL) && (delete->rightk == NULL)){ // Node has no kids.
        
        if(father != NULL){ // If father exists.
            
            // Set father.//

            if(father->leftk == delete) father->leftk = NULL; 
            else father->rightk = NULL; 
        }

        else Tree->Head = NULL; // Delete main node.

        free(delete); // Delete node.

    } // End if no kids.


    else if((delete->rightk == NULL) || (delete->leftk == NULL)){ // Has one kids.


        if(delete->rightk == NULL){
            
            if(father != NULL) father->leftk = delete->leftk; // Set father points next kid.
            else Tree->Head = delete->leftk; // Now is main node.

        } // No right kid.

        else{

            if(father != NULL) father->rightk = delete->rightk; // Set father points next kid.
            else Tree->Head = delete->rightk; // Now is main node.

        }

        free(delete); // Delete node.
        delete = NULL;
    }

    else{ // Node has two kids. 

        next = FindNextBT(delete); // Find next node.

        SetValueName(&(delete->data),next->data); // Set delete node with next data.

        // Also works if delete main node.//

        father = FindFatherBT(Tree,next->data,&found); // Find father of next node.
           
        if(father != NULL) father->rightk = next->rightk; // Set under tree.
        
        free(next);

    }
    
    Tree->sizet--;
}

NodeT FindNextBT(NodeT tmp){ // Find next node - by filter to be less thatn give node. So as binary tree is sorted.
    NodeT assist; // Assist: Next node of given node.

    assist = tmp;

    if(assist == NULL) return NULL; // Invalid node.

    assist = assist->rightk; // Go right.

    if(assist == NULL) return NULL; // Cant find next node.

    while(assist->leftk){ // While left kid of tmp is not NULL.
        assist = assist->leftk;

    } // End while.
        
    return assist;
}

void PrintNodeBTree(NodeT tmp, int * const error){ // Print given node.

    *error = 0;

    if(tmp == NULL){ // Invalid node.
        *error = 4; 
        return;
    }

    WriteValueName(stdout,tmp->data);
}
