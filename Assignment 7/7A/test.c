header

main() {
	int fd[2], fd1[2];
	int i=0;
	char var;
	char msg[100];
	char buff[1000] = {'\0'};
	pipe(fd);
	pipe(fd1);
	pid_t pid;
	pid = fork();
	if(pid==0) {
		close(fd[0]);
		write(fd[1], msg, strlen(msg));
		close(fd[1]);
		
	}
}