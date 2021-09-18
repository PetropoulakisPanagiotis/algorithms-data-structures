CC = gcc # Compilers.

a.out: test.o knapsack_greedy.o quicksort.o
	$(CC) -o a.out test.o knapsack_greedy.o quicksort.c

test.o: test.c 
	$(CC) -c test.c

knapsack_greedy.o: knapsack_greedy.c 
	$(CC) -c knapsack_greedy.c

quicksort.o:
	$(CC) -c quicksort.c

.PHONY: clean

clean:
		rm a.out test.o knapsack_greedy.o quicksort.o
