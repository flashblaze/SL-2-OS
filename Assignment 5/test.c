header files

sem_t readcountaccess;
sem_t databaseaccess;
int readcount = 0;



main() {
	sem_init(&readcountaccess, 0, 1);
	sem_init(&databaseaccess, 0, 1);

	pthread_t *writethreads, *readthreads;

	int i, nowritethreads = 0, noreadthreads = 0;
	printf("enter no writer\n");
	scanf("%d", &nowritethreads);
	printf("enter no reader\n");
	scanf("%d", &noreadthreads);

	writethreads = (pthread_t *)malloc(sizeof(pthread_t *) * nowritethreads);
	readthreads = (pthread_t *)malloc(sizeof(pthread_t *) * noreadthreads);

	for (int i = 0; i < nowritethreads; ++i)
	{
		pthread_create((writethreads + i), NULL, writer, (void *) i);
	}

	for (int i = 0; i < noreadthreads; ++i)
	{
		pthread_create((readthreads + i), NULL, reader, (void *) i);
	}

	for (int i = 0; i < noreadthreads; ++i)
	{
		pthread_join(*(readthreads + i), NULL);
	}

	for (int i = 0; i < nowritethreads; ++i)
	{
		pthread_join(*(writethreads + i), NULL);
	}
}