#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	pid_t pid;
	pid = fork();
	if(pid == 0) {
		printf("In child process\n");
	}
	else {
		sleep(50);
		printf("In parent process\n");
	}
	return 0;
}