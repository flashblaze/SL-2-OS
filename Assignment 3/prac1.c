#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int a[3][3], b[3][3], c[3][3], sum; //globally declared 3 matrices and sum

struct v {

	int i, j;
};

void accept(int d[3][3]) {
	int i, j;
	printf("Enter 9 elements for 3x3 matrix:\n");
	for (i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			scanf("%d", &d[i][j]);
		}
	}
}
//created accept function to reduce code redundancy

void *result(void *arg);

int main(int argc, char const *argv[])
{
	int i, j, k=0;
	void *status=NULL;
	pthread_t pid;
	struct v *mem = (struct v *)malloc(sizeof(struct v));
	printf("Enter data for 1st matrix: \n");
	accept(a);
	printf("Enter data for 2nd matrix: \n");
	accept(b);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			mem->i=i;
			mem->j=j;

			pthread_create(&pid,NULL,result,mem);
			pthread_join(pid,&status);
			k=*((int*)status);
			c[mem->i][mem->j]=k;
		}
	}
	printf("The Matrix Multiplication Is: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}

void *result(void *arg) {

	struct v *mem=arg;
	int p;
	sum=0;
	for(p=0; p<3; p++) {
		sum += a[mem->i][p] * b[p][mem->j];
	}
	pthread_exit(&sum);
}