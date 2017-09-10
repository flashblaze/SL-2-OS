#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct numbers {
	
	int num1, num2;
};

void *add_num(void *num) {

	struct numbers *nums = (struct numbers *) num;
	int sumval = ((*nums).num1 + (*nums).num2);
	printf("Addition: %d\n", sumval);
}

void *sub_num(void *num) {

	struct numbers *nums = (struct numbers *) num;
	int subval = ((*nums).num1 - (*nums).num2);
	printf("Subtraction: %d\n", subval);
}

void *mul_num(void *num) {

	struct numbers *nums = (struct numbers *) num;
	int mulval = ((*nums).num1 * (*nums).num2);
	printf("Multiplication: %d\n", mulval);
}

void *div_num(void *num) {

	struct numbers *nums = (struct numbers *) num;
	int divval = ((*nums).num1 / (*nums).num2);
	printf("Division: %d\n", divval);
}

int main() {

	int no1, no2;
	struct numbers num;
	pthread_t tid, tid2, tid3, tid4;
	printf("Enter 1st no: ");
	scanf("%d", &num.num1);
	printf("Enter 1st no: ");
	scanf("%d", &num.num2);
	pthread_create(&tid, NULL, add_num, (void *) &num);
	pthread_create(&tid2, NULL, sub_num, (void *) &num);
	pthread_create(&tid3, NULL, mul_num, (void *) &num);
	pthread_create(&tid4, NULL, div_num, (void *) &num);
	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	return 0;
}
