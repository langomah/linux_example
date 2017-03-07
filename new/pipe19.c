#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MSGSIZE 16

char *msg1 = "hello";
char *msg2 = "bye";

int main() {
	int p[2], pid;
	struct stat pinfo;
	char buf[10];
	pipe (p);
	pid = fork();
	if (pid != 0) {
		sleep(5);
		write(p[1], "Helloworld", 12);
		printf("Parent\n");
	}
	else {
		for (;;) {
			fstat(p[0], &pinfo);
			if(pinfo.st_size == 0)
				abc();
			else {
				read("Buff: %s\n", buf);
				printf("Child\n");
				exit(0);
			}
		}
	}
}


abc() {
	printf("Pipe is empty\n");
}
