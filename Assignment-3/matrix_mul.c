#include <stdio.h>
#include <pthread.h>

typedef struct {
	
	int i, j;
	int row, col;
	int **m1, **m2, **m3;
}mat;

int **allocate(int row, int col) {

	int **m1, i;
	m1 = (int **) malloc(sizeof(int *) *row);
	for (i = 0; i < col; i++){
		*(m1 + i) = (int *) malloc(sizeof(int) *col);
	}
	return m1;
}

int **accept(int row, int col) {
	int **m1, i, j;
	m1 = allocate(row, col);
	for ( i = 0; i < row; i++) {
		for (j = 0; j < col; j++){
			scanf("%d", (*(m1 + i) + j));
		}
	}
	return m1;
}

void display(int **m1, int row, int col) {
	int i, j;
	for ( i = 0; i < row; i++){
		for ( j = 0; j < col; j++){
			printf("%d", *(*(m1 + i) + j));
		}
		printf("\n");
	}
}

void threads(void *mat) {
  mat *matrix = (struct mat *) matrix;
  int k;
  *(*((* matrix).m3 + (* matrix).i) + (* matrix).j) = 0;
  for (k = 0;k < (* matrix).cols;k++) {
    *(*((* matrix).m3 + (* matrix).i) + (* matrix).j) +=
    *(*((* matrix).m1 + (* matrix).i) + k) *
    *(*((* matrix).m2 + k) + (* matrix).j);
  }
  pthread_exit(NULL);
}

int main () {

	int i, j;
  	int row, col;
  	int **m1, **m2, **m3;
  	int threadn;
  	pthread_t *threadm;
  	printf("Enter the Number of Rows and Columns\n");
  	scanf("%d%d",&row,&col);
  	
  	printf("Enter Elements of Array 1\n");
  	m1 = accept(row, col);
  	printf("Enter Elements of Array 2\n");
  	m2 = accept(row, col);
  	m3 = allocate(row, col);
  	
  	threadn = 0;
  	threadm = (pthread_t *) malloc(sizeof(pthread_t) * (row * col));
  	for (i = 0; i < row; i++) {
	    for (j = 0; j < cols; j++) {
      	mat *matrix = (struct mat *) malloc(sizeof(struct args));
      	(* matrix).row = row;
      	(* matrix).col = col;
      	(* matrix).m1 = m1;
      	(* matrix).m2 = m2;
      	(* matrix).m3 = m3;
      	(* matrix).i = i;
      	(* matrix).j = j;
      	pthread_create(&threadm[threadn++], NULL, threads, (void *) matrix);
    	}
  	}
  	for (j = 0;j < threadn;j++) {
	    pthread_join(threadm[j], NULL);
  	}
  	display(c, row, col);
	return 0;
}