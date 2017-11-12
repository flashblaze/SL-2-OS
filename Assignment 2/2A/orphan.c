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
		}
		if(child_pid == 0){
			sleep(30);
			printf("Child Process\n");
		}

		

}
