#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	int shmid, size;
	key_t key;
	char *shm, *s;

	size=28;
	key=123;

	shmid = shmget(key, size, IPC_CREAT | 0666);
	if(shmid < 0) {
		printf("Error!\n");
		exit(0);
	}

	shm = shmat(shmid, NULL, 0);
	if(shm == (char*)-1) {
		printf("Error!\n");
		exit(0);
	}

	s = shm;
	printf("The string is: ");
	for(s=shm; *s != '\0'; s++) {
		putchar(*s);
	}
	printf("\n");
	*shm = '*';
	exit(0);
	return 0;
}