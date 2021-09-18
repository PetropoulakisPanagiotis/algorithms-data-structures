CC = gcc # Compilers.

a.out: test.o partition.o
	$(CC) -o a.out test.o partition.o

test.o: test.c
	$(CC) -c test.c

partition.o: partition.c
	$(CC) -c partition.c

.PHONY: clean

clean:
		rm a.out test.o partition.o
