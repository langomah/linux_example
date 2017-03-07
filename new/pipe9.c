#include <stdio.h>
#define MSGSIZE 16

main() {
	char *msg1 = "Helloworld";
	char inbuf[MSGSIZE];
	int p[2], pid, retval;
	pipe (p);

	pid = fork();
	
	if (pid == 0) {
		//close (p[0]);
		//write(p[1], msg1, MSGSIZE);
		s
		printf("RAKESH");
	}else { 
		close(p[1]);
		retval = read(p[0],inbuf, MSGSIZE);
		printf("The value returned is %d\n", retval);
	
	}
	
}
