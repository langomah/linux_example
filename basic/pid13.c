#include <stdio.h>

main() {
	int dip, pid, cpid;
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
			cpid = wait(0);
			printf("child with pid %d\n", cpid);
			cpid = wait(0);
			printf("child with pid %d\n", cpid);
			
			printf("parent process\n");
			sleep();	
		}
	}
}
