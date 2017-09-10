#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *demo(void *arg) {
	
	printf("Hello World\n");
	return NULL;
}

int main() {

	pthread_t tid;
	pthread_create(&tid, NULL, demo, NULL);
	pthread_join(tid, NULL);
	return 0;
}
