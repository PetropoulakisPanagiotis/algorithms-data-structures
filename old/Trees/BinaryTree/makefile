CC = gcc # Compiler.

Tree: MainBinaryTree.o BinaryTree.o TypeBinaryTree.o
	$(CC) -o Tree MainBinaryTree.o BinaryTree.o TypeBinaryTree.o

MainBinaryTree.o: MainBinaryTree.c
	$(CC) -c MainBinaryTree.c

BinaryTree.o: BinaryTree.c
	$(CC) -c BinaryTree.c

TypeBinaryTree.o: TypeBinaryTree.c
	$(CC) -c TypeBinaryTree.c

.Phony: clean1
	# clean 1 deletes .o files and Tree.
	
clean1:  
	rm -f Tree MainBinaryTree.o BinaryTree.o TypeBinaryTree.o 
