#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	pid_t child_pid;

	
	child_pid = fork();
	
		if(child_pid > 0){
			printf("Parent Process\n");
			printf("%d\n", getppid());
			sleep(30);
			
		}
		
		if(child_pid == 0){
			printf("Child process\n");
			printf("%d\n", getpid());
			exit(0);

		}
}
