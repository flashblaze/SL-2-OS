#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void incr(int arr[], int n) {
	int i, j;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(arr[j] < arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void decr(int arr[], int n) {
	int i, j;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	
	int size, i, *arr;
	printf("Enter size of the array:\n");
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int)*size);
	printf("Enter elements for the array:\n");
	for(i=0; i<size; i++) {
		scanf("%d", (arr+i));
	}
	pid_t pid;
	pid = fork();
	if(pid==0) {
		incr(arr, size);
	}
	else {
		wait(NULL);
		decr(arr, size);
	}
	printf("Sorted array is:\n");
	for(i=0; i<size; i++) {
		printf("%d ", *(arr+i));
	}
	printf("\n");
	return 0;
}