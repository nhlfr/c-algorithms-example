CC=gcc
LDFLAGS=-lpthread

all: quicksort quicksort-threaded
.PHONY: all

quicksort: quicksort.c
	$(CC) -o quicksort quicksort.c

quicksort-threaded: quicksort_threaded.c
	$(CC) -o quicksort-threaded quicksort_threaded.c $(LDFLAGS)
