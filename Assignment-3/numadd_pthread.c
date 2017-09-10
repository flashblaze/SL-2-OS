#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *display_num(void *num2) {

	int *num1 = (int *) num2;
	printf("The no is: %d\n", *num1);
	return NULL;
}

int main() {

	int no1;
	pthread_t tid;
	printf("Enter a no: ");
	scanf("%d", &no1);
	pthread_create(&tid, NULL, display_num, (void *) &no1);
	pthread_join(tid, NULL);
	return 0;
}
