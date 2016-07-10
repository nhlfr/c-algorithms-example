CC=gcc
LDFLAGS=-lpthread

all: heapsort mergesort quicksort quicksort-threaded binary-tree
.PHONY: all

heapsort: heapsort.c
	$(CC) -o heapsort heapsort.c

mergesort: mergesort.c
	$(CC) -o mergesort mergesort.c

quicksort: quicksort.c
	$(CC) -o quicksort quicksort.c

quicksort-threaded: quicksort_threaded.c
	$(CC) -o quicksort-threaded quicksort_threaded.c $(LDFLAGS)

binary-tree: binary_tree.c
	$(CC) -o binary-tree binary_tree.c
