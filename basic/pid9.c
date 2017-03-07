#include <stdio.h>

main() {
	int i = 0, pid;
	printf("Ready to fork\n");
	pid = fork();
	if (pid  ==0){
		printf("Child starts\n");
		for (i = 0; i<1000; i++)
			printf("%d\t", i);
		printf("child ends\n");
	} else {
		wait(0);
		for (i = 0; i<1000; i++)
			printf("%d\t", i);
		printf("parent process\n");
	}
}
