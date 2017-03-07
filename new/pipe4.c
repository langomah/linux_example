#include <stdio.h>

main() {
	int p[2], pid;
	pipe (p);
	pid = fork();
	if (pid == 0) {
		printf( "In child p[0] is %d p[1] is %d\n", p[0], p[1]);
	}else { 
		printf( "In parent p[0] is %d p[1] is %d\n", p[0], p[1]);
	}
}
