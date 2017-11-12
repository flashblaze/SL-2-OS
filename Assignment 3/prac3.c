#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct args {
	int i, j, rows, cols, **a, **b, **c;
}args;

int **allocateMem(int rows, int cols) {

	int **a = (int **)malloc(sizeof(int *) * rows);
	int i;
	for(i=0; i<rows; i++) {
		*(a+i) = (int *)malloc(sizeof(int *) * cols);
	}
	return a;
}

int **accept(int rows, int cols) {

	int i, j, **a;
	a = allocateMem(rows, cols);
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			scanf("%d", (*(a+i)+j));
		}
	}
	return a;
}

void display(int **a, int rows, int cols) {

	int i, j;
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			printf("%d ", *(*(a+i)+j));
		}
		printf("\n");
	}
}

void result(void *many) {

	struct args *arguments = (struct args *) many;
	int k;
	*(*((*arguments).c + (*arguments).i) + (*arguments).j) = 0;
	for(k=0; k<(*arguments).cols; k++) {
		*(*((*arguments).c + (*arguments).i) + (*arguments).j) +=
		*(*((*arguments).a + (*arguments).i) + k) *
		*(*((*arguments).b + k) + (*arguments).j);
	}
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
	
	int i, j, rows, cols, **a, **b, **c, numberofThreads;
	pthread_t *threads;
	printf("Enter no. of rows and columns:\n");
	scanf("%d%d", &rows, &cols);
	printf("Enter elements for 1st matrix\n");
	a = accept(rows, cols);
	printf("Enter elements for 2nd matrix\n");
	b = accept(rows, cols);
	c = allocateMem(rows, cols);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * rows * cols);
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			struct args *arguments = (struct args *) malloc(sizeof(struct args));
			(*arguments).rows = rows;
			(*arguments).cols = cols;
			(*arguments).i = i;
			(*arguments).j = j;
			(*arguments).a = a;
			(*arguments).b = b;
			(*arguments).c = c;
			pthread_create(&threads[numberofThreads++], NULL, result, (void *) arguments);
		}
	}
	for (j = 0;j < numberofThreads;j++) {
    	pthread_join(threads[j], NULL);
  	}
  	display(c, rows, cols);
	return 0;
}