#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void bubble(int[],int);

void main()
{
	int a[20],n, i;
	char str[20];
	char *arg[20];
	void *ptr[20];
	printf("\nEnter the number count");
	scanf("\n%d",&n);
	printf("\nEnter the number elements");
	for(i=0;i<n;i++){
		printf("\na[%d]",i+1);
		scanf("%d",&a[i]);
	}
	
	pid_t pid = fork();
	if(pid == 0){
	// Now convert the array to char to pass through Command line arguements
		sleep(2);
		for(i=0;i<n;i++){
			sprintf(str,"%d",a[i]);
			arg[i] = malloc(sizeof(str));
			strcpy(arg[i],str);
		}	
		arg[i]=NULL;
		execve("./bin",arg,NULL);
		printf("\nConverted and called");
		
	}
	else{
		wait(NULL);
		bubble(a,n);
		printf("\nSorted Array");
		for(i=0;i<n;i++){
			ptr[i] = a[i];
			printf("\n%d",(int*)ptr[i]);
			printf("\n");
		}
	}
}

void bubble(int a[20],int n)
{
	int i,j;
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
		if(a[j] > a[j+1])
		{
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
		}
	}	
}

