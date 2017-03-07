#include <stdio.h>

int main() {

	int pid;
	pid = fork();
	if (pid ==0) {
		printf("Child ID is %d\n", getpid());	
		printf("parent ID is %d\n", getppid());	
		sleep(20);
		printf("Child ID is %d\n", getpid());	
		printf("parent ID is %d\n", getppid());	
	}else {
		sleep(10);
		printf("Parent ID is %d\n", getpid());	
		printf("Parentshel ID is %d\n", getppid());
		printf("Parent terminates\n");

	}
}

		
