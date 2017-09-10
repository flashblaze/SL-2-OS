#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void swap(int *a, int *b) {
  
  int temp = *a;
  *a = *b;
  *b = temp;
}

void asc(int arr[], int s) {

	int i, j;
	for(i = 0; i < s-1; i++) {
		for(j = 0; j < s-i-1; j++) {
			if(arr[j] < arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void desc(int arr[], int s) {
	
	int i, j;
	for(i = 0; i < s-1; i++) {
		for(j = 0; j < s-i-1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}	
}

int main() {

	int *arr, i, size;
	printf("Enter size of the array: ");
	scanf("%d", &size);
	arr = (int *) malloc(size * sizeof(int));
	printf("Enter the elements of array:\n");
	for (i = 0; i < size; i++) {
		scanf("%d", (arr + i));
	}

	pid_t pid;
	pid = fork();
	if (pid == 0) {
		asc(arr, size);
	}
	else {
		wait(NULL);
		desc(arr, size);
	}

	printf("The sorted elements of array are:\n");
	for (i = 0; i < size; i++) {
		scanf("%d", *(arr + i));
	}	

	return 0;
}