#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>

void* producer(void*);
void* consumer(void*);

//-------------------------------------------------------------------

sem_t full_sem, empty_sem;
pthread_mutex_t buffer_mutex;
int buffer[10], buffer_index=0;


//===================================================================
main(){
	pthread_t tid[10]; //5 producers and 5 consumers
	int thread[10];
	
	sem_init(&full_sem, 0, 5); //5 producers can place
	sem_init(&empty_sem, 0, 0); //Initially 0 consumers can consume
	pthread_mutex_init(&buffer_mutex, NULL);
	
	int i;
	for(i=0; i<10; i++){
		thread[i] = i;
		pthread_create(&tid[i], NULL, producer, &thread[i]);
		i++;
		thread[i] = i;
		pthread_create(&tid[i], NULL, consumer, &thread[i]);
	}
	
	for(i=0; i<10; i++)
		pthread_join(tid[i], NULL);
		
	sem_destroy(&full_sem);
	sem_destroy(&empty_sem);
	pthread_mutex_destroy(&buffer_mutex);
}

//--------------------------------------------------
void* producer(void* n){
	int thread_no = *(int*)n;
	int value = rand()%100;
	
	sem_wait(&full_sem);
		pthread_mutex_lock(&buffer_mutex);
			buffer[buffer_index++] = value;
		pthread_mutex_unlock(&buffer_mutex);
	sem_post(&empty_sem);
	
	printf("thread no. %d produced %d\n", thread_no, value);
	pthread_exit(NULL);
}

//--------------------------------------------------
void* consumer(void* n){
	int thread_no = *(int*)n;
	int value;
	
	sem_wait(&empty_sem);
		pthread_mutex_lock(&buffer_mutex);
			 value = buffer[--buffer_index];
		pthread_mutex_unlock(&buffer_mutex);
	sem_post(&full_sem);
	
	printf("thread no. %d consumed %d\n", thread_no, value);
	pthread_exit(NULL);
}

