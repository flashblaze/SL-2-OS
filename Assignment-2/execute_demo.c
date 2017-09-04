#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Loading program from demo!\n");
	execl("demo", "demo", (char *)0);
	return 0;
}