#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

typedef struct AVLNode{ // Each node of tree.
    TEL data;
    AVLN leftk;
    AVLN rightk;
    producing_r pr;

}AVLNode;

void CreateAVL(AVLN *root){ // Create avl tree.

    *root = NULL;
}

int EmptyAVL(AVLN root){ // Check if tree is empty.
 
    // Returns 1 if tree is empty, else 0.//
 
    return (root == NULL);
}


void RightRotationAVL(AVLN *root, int *error){ // Rotate tree right - Right hight.
    AVLN tmp; // Tmp: Keep node.

    *error = 0;

    if(EmptyAVL(*root)){ // Empty tree.
        *error = 1;
        return;
    }
    
    else if(EmptyAVL((*root)->leftk)){ // Cant rotate tree and new root become NULL.
        *error = 1;
        return;
    }

    else { // Make right rotation.
        tmp = (*root)->leftk;
        (*root)->leftk = tmp->rightk;
        tmp->rightk = (*root);
        *root = tmp;
    }
}

void LeftRotationAVL(AVLN *root, int *error){ // Rotate tree left - Right hight.
    AVLN tmp; // Tmp: Keep node.

    *error = 0;

    if(EmptyAVL(*root)){ // Empty tree.
        *error = 1;
        return;
    }

    else if(EmptyAVL((*root)->rightk)){ // Cant rotate tree and new root become NULL.
        *error = 1;
        return;
    }

    else { // Make left rotation.

        tmp = (*root)->rightk; // Save right kid of root.
        (*root)->rightk = tmp->leftk; // Make right kid of root points in left kid of tmp.
        tmp->leftk = *root; // Make tmp left kid points in root.
        *root = tmp; // Root is now tmp.

    }
}

// Wight is about root - right or left. Can't be equal.//

void RightWeightAVL(AVLN *root, boolean *higher, int *error){ // Fix AVL tree. Right weight.
    AVLN x,w; // x,w: Keep node.

    *error = 0;

    x = (*root)->rightk; // Save right kid of root.

    switch(x->pr){ // Choose case of x node.
        
        case RH: // Simple left rotation.
            
            (*root)->pr = EH; // Equal hight.
            x->pr = EH; // Equal hight.
            LeftRotationAVL(root,error); // Do left rotation.
            *higher = 0; // Hight of tree hasn't change.
            break;

        case EH: // Can't come in this section.

            *error = 1;
            return;
            break;

        case LH: // Must do two rotations.

            w = x->leftk; // Save left kid of x.

            switch(w->pr){ // Choose case of w node - Set hights.

                case EH: // Equal hight.
                    
                    (*root)->pr = EH;
                    x->pr = EH;
                    break;
                
                case LH: // Left hight.
                    
                    (*root)->pr = EH;
                    x->pr = RH;
                    break;
                
                case RH:
                    
                    (*root)->pr = LH;
                    x->pr = EH;;
                    break;


            } // End switch w->pr - set hights.

            w->pr = EH; // Hight become equal.
            
            RightRotationAVL(&x,error); // Right rotation.
            // After this x points in w.//

            (*root)->rightk = x; // X has change so paste it again. New x is w.
            LeftRotationAVL(root,error); // Left rotation.

            *higher = 0; // Same hight.
            break;
    } // End switch x->pr.
}

void LeftWeightAVL(AVLN *root, boolean *higher, int *error){ // Fix AVL tree. Left weight.
    AVLN x,w; // x,w: Keep node.

    *error = 0;

    x = (*root)->leftk; // Save left kid of root.

    switch(x->pr){ // Choose case of x node.
        
        case LH: // Simple right rotation.
            
            (*root)->pr = EH; // Equal hight.
            x->pr = EH; // Equal hight.
            RightRotationAVL(root,error); // Do left rotation.
            *higher = 0; // Hight of tree hasn't change.
            break;

        case EH: // Can't come in this section.

            *error = 1;
            return;
            break;

        case RH: // Must do two rotations.

            w = x->rightk; // Save left kid of x.

            switch(w->pr){ // Choose case of w node - Set hights.

                case EH: // Equal hight.
                    
                    (*root)->pr = EH;
                    x->pr = EH;
                    break;
                
                case RH: // Left hight.
                    
                    (*root)->pr = EH;
                    x->pr = LH;
                    break;
                
                case LH:
                    
                    (*root)->pr = RH;
                    x->pr = EH;;
                    break;


            } // End switch w->pr - set hights.

            w->pr = EH; // Hight become equal.
            
            LeftRotationAVL(&x,error);
            // After this x points in w.//

            (*root)->leftk = x; // X has change so paste it again. New x is w.
            RightRotationAVL(root,error); // Left rotation.

            *higher = 0; // Same hight.
            break;
    } // End switch x->pr.
}
/*
void InsertAVL(AVLN *root, AVLN tmp, TEL element, boolean *higher, int *error){

    *error = 0;

    if(EmptyAVL(*root)){ // Create a unique node.
        
        tmp = malloc(sizeof(AVLNode)); // Create node.
        if(tmp == NULL){
            *error = 1; 
            return;
        }
        
        SetValueName(&(tmp->data),element); // Set data.

        *root = tmp; // Set main root.
        (*root)->leftk = NULL;
        (*root)->rightk = NULL;
        (*root)->pr = EH; // Equal hight.
        *higher = 1; // Hight has been increased.
    } // End insertion in NULL root.

    else{ // No NULL root.

        if(EqualName((*root)->data,tmp->data)){ // Already exists.
            *error = 1;
            return;
        }
        
        else{ // Node not exists.
    
            // First insert node and then fix it.//
            
            if(LessThanName(tmp->data,(*root)->data)){ // Go left.
                
                InsertAVL(&(*root)->leftk,tmp,element,higher,error); 
            
                if(*higher){ // Left under tree is higher.

                    switch((*root)->pr){
                        
                        case LH: // Left higher.
                            
                            LeftWeightAVL(root,higher,error);
                            break;

                        case EH: // Equal.
                            
                            (*root)->pr = LH;
                            break;

                        case RH:
                            
                            (*root)->pr = EH;
                            *higher = 0;
                            break;
                    } // End switch.
                
                } // End if left tree is higher.
            } // End go left.

            else{ // Go right.
            
                InsertAVL(&(*root)->rightk,tmp,element,higher,error); 
            
                if(*higher){ // Right  under tree is higher.

                    switch((*root)->pr){
                        
                        case LH: // Left higher.
                            
                            (*root)->pr = EH;
                            *higher = 0;
                            break;

                        case EH: // Equal.
                            (*root)->pr = RH;
                            break;

                        case RH: // Right higher.
                            
                           RightWeightAVL(root,higher,error);
                            break;
                    } // End switch.
                
                } // End if left tree is higher.
            } // End go right.

        } // End of node not exists.
    } // End of insertion in no NULL root.
}
*/
void PrintAVL(AVLN root){
    
    if(root == NULL) return; // Terminate condition.

    else{

        PrintAVL(root->leftk);
        WriteValueName(stdout,root->data);
        PrintAVL(root->rightk);

    }
}


