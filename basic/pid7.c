#include <stdio.h>

main() {
	int i = 0, j = 0, pid;
	pid = fork();
	if (pid == 0) {
		for (i = 0; i <500;i++)
		printf("%d\t", i);
	}else if (pid > 0) {
		for (j = 0; j <500; j++)
		printf("%d..", j);
	}
}

