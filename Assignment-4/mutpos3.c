#include <stdio.h>
#include <pthread.h>

FILE *fp;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *writer(void *arg) {
		
	int val;
	pthread_mutex_lock(&mutex1);
	fp = fopen("file1", "w+");
	printf("Enter a value: ");
	scanf("%d", &val);
	fprintf(fp, "%d", val);
	fclose(fp);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

void *reader(void *arg) {
	
	
	int val;
	pthread_mutex_lock(&mutex1);
	fp = fopen("file1", "r");
	fscanf(fp, "%d", &val);
	printf("Entered value is %d and is stored in the file\n", val);
	fclose(fp);
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
