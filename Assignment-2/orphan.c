#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	pid_t pid;
	pid = fork();
	if(pid == 0) {

		sleep(10);
		printf("This is child process\n");
		printf("Process id is %d\n", getpid());
		printf("Parent process id is %d\n", getppid());
	}
	else {
		sleep(5);
		printf("Process id is %d\n", getpid());
		printf("Parent process id is %d\n", getppid());
	}

	return 0;
}