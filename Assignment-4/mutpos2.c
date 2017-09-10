#include <stdio.h>
#include <pthread.h>

int data = -100;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *writer(void *arg) {
	
	int val;
	pthread_mutex_lock(&mutex1);
	printf("Enter a value: ");
	scanf("%d", &val);
	data = val;
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

void *reader(void *arg) {
	
	int val;
	pthread_mutex_lock(&mutex1);
	
	if (data == -100) {
		printf("Value is not provided. Enter a value\n");
		return NULL;
	}

	val = data;
	printf("The value is: %d\n", val);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

int main() {
	
	pthread_t t1, t2;
	
	//The below infinite loop does not execute the statements in the same order as t1 and t2. 
	//To avoid the errors, set a value for data and check the value in reader to see whether the user has given input for data.
	//This will avoid the error. Also ask the user whether he wants to continue the prog
	while(1) {
		pthread_create(&t1, NULL, writer, NULL);
		pthread_create(&t2, NULL, reader, NULL);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
	}
	return 0;
}
