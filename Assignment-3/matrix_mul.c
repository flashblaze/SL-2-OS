#include <stdio.h>
#include <pthread.h>

typedef struct {
	
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

int main () {

	return 0;
}