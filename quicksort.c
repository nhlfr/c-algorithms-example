#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *a, int p, int r) {
	int i, j, x;
	i = p - 1;
	x = a[r];
	for (j = p; j < r; ++j) {
		if (a[j] <= x)
			swap(&a[++i], &a[j]);
	}
	swap(&a[++i], &a[r]);

	return i;
}

void quicksort(int *a, int p, int r) {
	int q;
	if (p <= r) {
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main() {
	int i, count, *a;
	scanf("%d", &count);
	a = malloc(sizeof(int) * count);
	for (i = 0; i < count; ++i) {
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, count - 1);
	printf("\n");
	for (i = 0; i < count; ++i) {
		printf("%d\n", a[i]);
	}
	free(a);

	return 0;
}
