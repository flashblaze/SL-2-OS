#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct args {
	int i, j, rows, cols, **a, **b, **c;
}args;

//reason for taking structure

int **allocateMem(int rows, int cols) {
	int **a = (int **)malloc(sizeof(int *)*rows);
	int i;
	for(i=0; i<rows; i++) {
		*(a+i) = (int *)malloc(sizeof(int *) * cols);
	}
	return a;
}
//function for allocating memory
//1st mem is assigned to rows and then to columns row by row

int **accept (int rows, int cols) {
	int **a, i, j;
	a = allocateMem(rows, cols);
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			scanf("%d", (*(a+i)+j));
		}
	}
	return a;
}
//simple accept function
//double pointer sice it returns two values: row and column

void display (int **a, int rows, int cols) {
	int i, j;
	printf("Elements of matrix are: \n");
	for(i=0; i<rows; i++) {
		for(j=0; j<cols; j++) {
			printf("%d ", *(*(a+i)+j));
		}
		printf("\n");
	}
}
//simple display function


void result(void *many) {
	struct args *arguments = (struct args *) many; 
	//instead of void *args I used many so as to avoid confusion regarding which args was passed. 
	//Now it seems a little clearer
	int k;
	*(*((*arguments).c + (*arguments).i) + (*arguments).j) = 0; //1
	for(k=0; k< (*arguments).cols; k++) { //2
		*(*((*arguments).c + (* arguments).i) + (* arguments).j) += 
		*(*((* arguments).a + (*arguments).i) + k) * 
		*(*((* arguments).b + k) + (* arguments).j); 
	}
	pthread_exit(NULL);
}
//multiplication function
//1: initializing c matrix to zero
//2: simple multiplication for loop

int main(int argc, char const *argv[])
{
	int rows, cols, **a, **b, **c, i, j, numberOfThreads;
	pthread_t *threads;
	//pthread pointer since is going to be dynamically allocated memory

	printf("Enter no. of rows and cols: \n");
	scanf("%d%d", &rows, &cols);
	printf("Enter elements for 1st matrix: \n");
	a=accept(rows, cols);
	printf("Enter elements for 2nd matrix: \n");
	b=accept(rows, cols);
	c=allocateMem(rows, cols);
	threads=(pthread_t *)malloc(sizeof(pthread_t) * rows * cols);
	//allocating memory to threads
	
 	for (i = 0;i < rows;i++) {
    	for (j = 0;j < cols;j++) {
      		struct args *arguments = (struct args *) malloc(sizeof(struct args));
		    (* arguments).rows = rows;
		    (* arguments).cols = cols;
		    (* arguments).a = a;
		    (* arguments).b = b;
		    (* arguments).c = c;
		    (* arguments).i = i;
		    (* arguments).j = j;
      		pthread_create(&threads[numberOfThreads++], NULL, result, (void *) arguments);
    	}
  	}
  	for (j = 0;j < numberOfThreads;j++) {
    	pthread_join(threads[j], NULL);
  	}
  	display(c, rows, cols);
	return 0;
}