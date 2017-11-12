#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a, int *b) {
	
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partAsc(int arr[], int low, int high) {

	int pivot = arr[high];
	int i = (low-1);
	int j;
	for(j=low; j<=high-1; j++) {
		if(arr[j]<=pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return(i+1);
}

int partDesc(int arr[], int low, int high) {

	int pivot = arr[high];
	int i = (low-1);
	int j;
	for(j=low; j<=high-1; j++) {
		if(arr[j]>=pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return(i+1);
}

void sortAsc(int arr[], int low, int high) {
	if(low<high) {
		int pi = partAsc(arr, low, high);
		sortAsc(arr, low, pi-1);
		sortAsc(arr, pi+1, high);

	}
}

void sortDesc(int arr[], int low, int high) {
	if(low<high) {
		int pi = partDesc(arr, low, high);
		sortDesc(arr, low, pi-1);
		sortDesc(arr, pi+1, high);

	}
}

int main() {
  int size, i, *array;
  printf("Enter the Size of the Array\n");
  scanf("%d", &size);
  array = (int*) malloc(size * sizeof(int));
  printf("Enter the Elements of the Array\n");
  for (i = 0;i < size;i++)
    scanf("%d", (array+i));
  pid_t pid = fork();
  if (pid == 0)
    sortAsc(array, 0, size - 1);
  else {
    wait(NULL);
    sortDesc(array, 0, size - 1);
  }
  printf("Sorted Array:\n");
  for(i = 0;i < size;i++)
    printf("%d\t", *(array + i));
  printf("\n");
  return 0;
}