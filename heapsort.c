#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int heap_left(int i)
{
	return 2 * i;
}

int heap_right(int i)
{
	return 2 * i + 1;
}

void heapify(int *a, int heap_size, int i)
{
	int left, right, largest;
	left = heap_left(i);
	right = heap_right(i);
	if (left < heap_size && a[left] > a[i])
		largest = left;
	else
		largest = i;
	if (right < heap_size && a[right] >= a[largest])
		largest = right;
	if (largest != i) {
		swap(&a[largest], &a[i]);
		heapify(a, heap_size, largest);
	}
}

void build_heap(int *a, int heap_size)
{
	int i, j;
	for (i = heap_size / 2; i >= 0; --i)
		heapify(a, heap_size, i);
}

void heapsort(int *a, int length)
{
	int i, j;
	build_heap(a, length);
	for (i = length - 1; i > 0; --i) {
		swap(&a[0], &a[i]);
		build_heap(a, i);
	}
}

int main()
{
	int i, count, *a;
	scanf("%d", &count);
	a = (int*) malloc(sizeof(int) * count);
	for (i = 0; i < count; ++i)
		scanf("%d", &a[i]);
	heapsort(a, count);
	printf("\n");
	for (i = 0; i < count; ++i)
		printf("%d\n", a[i]);
	free(a);

	return 0;
}
