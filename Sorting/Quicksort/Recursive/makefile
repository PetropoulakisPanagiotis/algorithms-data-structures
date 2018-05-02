CC = gcc # Compilers.

a.out: test.o quicksort.o
	$(CC) -o a.out test.o quicksort.c

test.o: test.c 
	$(CC) -c test.c

quicksort.o:
	$(CC) -c quicksort.c

.PHONY: clean

clean:
		rm a.out test.o quicksort.o
