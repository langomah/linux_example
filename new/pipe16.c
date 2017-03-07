#include <stdio.h>
#include<signal.h>

#define MSGSIZE 16
void abc();
main() {
	char *msg1 = "Helloworld";
	char buf[MSGSIZE];
	int p[2], pid, retval;
	pipe (p);
	signal(SIGPIPE, abc);
	pid = fork();
	
	if (pid == 0) {
	//	close (p[0]);
		//write(p[1], msg1, MSGSIZE);
	sleep(5);
		printf("RAKESH");
	}else { 
		wait(0);
		close(p[0]);
		//retval = read(p[0],inbuf, MSGSIZE);
		retval = write(p[1], msg1, 1);
		printf("The value returned is %d\n", retval);
	
	}
	
}
void abc() {
	printf("In abc");
}
