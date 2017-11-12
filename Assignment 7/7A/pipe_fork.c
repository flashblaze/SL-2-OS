#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int i=0;
	int fd[2],fd1[2];
	pipe(fd1);
	pipe(fd);
	char var;
	char msg[100];
	char buff[1000]={'\0'};
	pid_t pid;
	pid=fork();
	if(pid == 0)
	{
		close(fd[0]); //close reader of child
		write(fd[1],msg,strlen(msg)); //write child
		close(fd[1]); //close writer of child
		close(fd1[1]); //close writer of parent
		read(fd1[0],buff,sizeof(buff)); //read parent
		close(fd1[0]); //close reader of parent
		printf("\n%s",buff);
		printf("\n");
	}
	else
	{
		i=0;
		close(fd[1]); //close writer of child
		read(fd[0],msg,strlen(msg)); //read child
		close(fd[0]); //close reader of child
		printf("Enter filename:\n");
		gets(msg);
		printf("\n !! FILE NAME IS : \t%s",msg);
		printf("\n\n");
		FILE *fp;
		fp=fopen(msg,"r");

		while(!feof(fp))
		{
			var=fgetc(fp);
			buff[i]=var;
			i++;
		}
		buff[i]='\0';
		fclose(fp);
		close(fd1[0]); //close reader of parent
		write(fd1[1],buff,i); //write parent
		close(fd1[1]); //close writer of parent
	}

	return 0;
}