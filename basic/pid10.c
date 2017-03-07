#include <stdio.h>

main() {
	int dip, pid;
	printf("Ready to fork\n");
	pid = fork();
	if (pid  ==0){
		printf("Child starts %d\n", getpid());
		printf("child ends\n");
	} else {
		dip = fork();
		if (dip ==0){
			printf("Child 2 starts %d\n", getpid());
			printf("child 2 ends\n");
		} else {
			sleep(50);
			printf("parent process\n");
		}
	}
}
