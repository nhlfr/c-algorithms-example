#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int p, int q, int r)
{
	int n1, n2, *left, *right, i, j, k;
	n1 = q - p + 2;
	n2 = r - q + 1;
	left = (int*) malloc(sizeof(int) * n1);
	right = (int*) malloc(sizeof(int) * n2);
	for (i = 0; i < n1 - 1; i++)
		left[i] = a[p + i];
	left[n1 - 1] = INT_MAX;
	for (i = 0; i < n2 - 1; i++)
		right[i] = a[q + i + 1];
	right[n2 - 1] = INT_MAX;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++) {
		if (left[i] <= right[j]) {
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
	}
}

void mergesort(int *a, int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	mergesort(a, p, q);
	mergesort(a, q + 1, r);
	merge(a, p, q, r);
}

int main()
{
	int count, i, *a;
	scanf("%d", &count);
	a = (int*) malloc(sizeof(int) * count);
	for (i = 0; i < count; i++)
		scanf("%d", &a[i]);
	mergesort(a, 0, count - 1);
	printf("\n");
	for (i = 0; i < count; i++)
		printf("%d\n", a[i]);
	return 0;
}
