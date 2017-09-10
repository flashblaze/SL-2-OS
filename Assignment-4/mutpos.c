#include <stdio.h>
#include <pthread.h>

int data = 0;
//Initializing a global variable

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *writer(void *arg) {
	
	int val;
	pthread_mutex_lock(&mutex1);
	//Locking since the value is being written by a thread and should not be accessed by another thread

	printf("Enter a value: ");
	scanf("%d", &val);
	data = val;
	pthread_mutex_unlock(&mutex1);
	//Unlocking for giving access if needed

	return NULL;
}

void *reader(void *arg) {
	
	int val;
	pthread_mutex_lock(&mutex1);
	val = data;
	printf("The value is: %d\n", data);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

int main() {
	
	pthread_t t1, t2;
	pthread_create(&t1, NULL, writer, NULL);
	pthread_create(&t2, NULL, reader, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
