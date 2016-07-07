#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct quicksort_args {
	int *a;
	int p;
	int r;
};

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

void *quicksort(void *args) {
	int *a, p, r, q;
	struct quicksort_args *s_args = (struct quicksort_args*) args;
	struct quicksort_args first_part_args;
	struct quicksort_args second_part_args;
	pthread_t first_part_t, second_part_t;
	a = s_args->a;
	p = s_args->p;
	r = s_args->r;
	if (p <= r) {
		q = partition(a, p, r);

		first_part_args.a = a;
		first_part_args.p = p;
		first_part_args.r = q - 1;
		pthread_create(&first_part_t, NULL, quicksort, (void*) &first_part_args);

		second_part_args.a = a;
		second_part_args.p = q + 1;
		second_part_args.r = r;
		pthread_create(&second_part_t, NULL, quicksort, (void*) &second_part_args);

		pthread_join(first_part_t, NULL);
		pthread_join(second_part_t, NULL);
	}
}

int main() {
	int i, count, *a;
	struct quicksort_args q_args;
	pthread_t quicksort_t;

	scanf("%d", &count);
	a = malloc(sizeof(int) * count);
	for (i = 0; i < count; ++i) {
		scanf("%d", &a[i]);
	}

	q_args.a = a;
	q_args.p = 0;
	q_args.r = count - 1;
	pthread_create(&quicksort_t, NULL, quicksort, (void*) &q_args);
	pthread_join(quicksort_t, NULL);

	printf("\n");
	for (i = 0; i < count; ++i) {
		printf("%d\n", a[i]);
	}

	free(a);

	return 0;
}
