#include <stdio.h>
#include "BinaryTree.h"
#include "TypeBinaryTree.h"

void PrintOptions(FILE *in);

int main(void){
    InfoBT Tree = NULL; // Tree: Binary tree.
    NodeT assist = NULL; // Assist: Node in tree.
    TEL element; // Element: Assist variable that keeps data for a node.
    int error,select,tmp; // Error: Keep errors. Select: Select action to make. Tmp: Use it for more actions.

    while(1){ // Make actions until press 0.
        
        error = 0;

        PrintOptions(stdout); // Print options.
        tmp = scanf("%d",&select); // Keep selection.
         
        if(tmp == 0){ // Scanf fails.

                printf("Unknown selection. Try Again.\n");
            
                break;
        }

        switch(select){
            

            case 0: // Exit
                return 0;
                
                break;

            case 1: // Create tree.

                CreateBTree(&Tree,&error);
                if(error != 0) printf("Cant create tree.\n");
                else printf("Tree created.\n");

                break; 

            case 2: // Empty tree.
                
                tmp = EmptyBTree(Tree,&error);
                if(error != 0) printf("Cant check if tree is empty.\n");
                else if(tmp == 0) printf("Binary Tree is not empty.\n");
                else printf("Binary Tree is empty.\n");
                
                break;

            case 3: // Destroy tree.

                DestroyBTree(&Tree,&error);
                if(error != 0) printf("Cant delete tree.\n");
                else printf("The tree destroyed.\n");

                break;

            case 4: // Add element in tree.
    

                printf("Give data to add in tree.\n");
                ReadValueName(stdin,&element);

                InsertBTree(&Tree,element,&error);
                if(error != 0) printf("Cant insert element in tree.\n");
                else printf("Element add it in tree successfully.\n");

                break;

            case 5: // Print tree.

                PrintBTree(Tree,&error);
                if(error != 0) printf("Cant print tree.\n");
                
                break;

            case 6: // Search.

                printf("Give data to search.\n");
                ReadValueName(stdin,&element);

                SearchBTree(Tree,element,&tmp,&error);
                if(error != 0) printf("Cant search in tree.\n");

                printf("Data is in tree: %d.\n",tmp);

                break;

            case 7: // Search without recursion.

                printf("Give data to search.\n");
                ReadValueName(stdin,&element);

                SearchNoRecursionBTree(Tree,element,&tmp,&error);
                if(error != 0) printf("Cant search in tree.\n");

                printf("Data is in tree: %d.\n",tmp);

                break;

            case 8: // Add element without recursion.

                printf("Give data to add in tree.\n");
                ReadValueName(stdin,&element);

                InsertNoRecursionBTree(Tree,element,&error);
                if(error != 0) printf("Cant insert element in tree.\n");
                else printf("Element add it in tree successfully.\n");

                break;

            case 9: // Print tree normall with no recursion.


                printf("Give node to delete.\n");
                ReadValueName(stdin,&element);

                DeleteNodeBTree(Tree,element,&error);
                if(error != 0) printf("Cant delete node.\n");

                break;

            case 10: // Go next node.
                    
                printf("Give data to find next of it.\n");
                ReadValueName(stdin,&element);
            
                assist = SearchNoRecursionBTree(Tree,element,&tmp,&error);
                if(error != 0 || tmp == 0) printf("Cant find node.\n");
                
                assist = FindNextBT(assist);
            
                printf("Next node of:");
                WriteValueName(stdout,element);
                printf("\nis: ");
                PrintNodeBTree(assist,&error);

                if(error != 0) printf ("Cant find next node.\n");

                break;
            
            case 11:
                
                printf("Give data to find father of it.\n");
                ReadValueName(stdin,&element);

                assist = FatherBTree(Tree,element,&tmp);

                if(assist == NULL) printf("Cant find father.");
                else PrintNodeBTree(assist,&error);
                
                if(error != 0) printf("Cant printf father.");

                break;


            default:

                printf("Unknown selection. Try Again.\n");

                break;



        } // End switch.


    }





    return 0;

}


void PrintOptions(FILE *in){

    fprintf(in,"\nPress 1 to create a binary tree.\n"); 
    fprintf(in,"\nPress 2 to check if binary tree is empty.\n");
    fprintf(in,"\nPress 3 to Destroy binary tree.\n");
    fprintf(in,"\nPress 4 to add element in binary tree.\n");
    fprintf(in,"\nPress 5 to print binary tree.\n");
    fprintf(in,"\nPress 6 to search an element in binary tree.\n");
    fprintf(in,"\nPress 7 to search an element non recursivilly in binary tree.\n");
    fprintf(in,"\nPress 8 to add element with no recursion in binary tree.\n");
    fprintf(in,"\nPress 9 to delete node from binary tree.\n");
    fprintf(in,"\nPress 10 to print next node of binary tree.\n");
    fprintf(in,"\nPress 11 to find father of given node in binary tree.\n");
    fprintf(in,"\nPress 0 to exit.\n");
    fprintf(in,"Selection:");
}
