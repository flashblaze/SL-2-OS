header files

void* producer(void *);
void* consumer(void *);

sem_t empty, full;
pthread_mutex_t buffer_mutex;
int buffer[10], bufferindex = 0;

main(){
	pthread_t tid[10];
	int thread[10];

	sem_init(&full, 0, 5);
	sem_init(&empty, 0, 1);
	pthread_mutex_init(&buffer_mutex, NULL);

	for (int i = 0; i < 10; ++i){
		thread[i] = i;
		pthread_create(&tid[i], NULL, producer, &thread[i]);
		i++;
		thread[i] = i;
		pthread_create(&tid[i], NULL, producer, &thread[i]);
	}
	for (int i = 0; i < 10; ++i)
	{
		pthread_join(tid[i], NULL);
	}
}

producer(void *n) {
	int threadno = *(int*)n;
	int val = rand()%100;

	sem_wait(&full);
	pthread_mutex_lock(&buffer_mutex);
	buffer[bufferindex++] = value;
	pthread_mutex_unlock(&buffer_mutex);
	sem_post(&empty);
	printf();
	pthread_exit;
}

consumer(void *) {
	int threadno = *(int*)n;
	int val;

	sem_wait(&empty);
	pthread_mutex_lock(&buffer_mutex);
	value = buffer[--bufferindex];
	pthread_mutex_unlock(&buffer_mutex);
	sem_post(&full);
	printf();
	pthread_exit;
}
